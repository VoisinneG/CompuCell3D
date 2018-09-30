# -*- coding: utf-8 -*-
import warnings
import os, sys
from os.path import join, exists, dirname
import string
# from utils import mkdir_p
import Configuration
# import SimpleTabView
from Utilities import ScreenshotData

# from Graphics.GraphicsFrameWidget import GraphicsFrameWidget

MODULENAME = '---- ScreenshotManager.py: '


class ScreenshotManagerCore(object):
    def __init__(self):
        self.screenshotDataDict = {}
        self.screenshotCounter3D = 0

    def cleanup(self):
        """
        Implementes cleanup actions
        :return: None
        """
        raise NotImplementedError()

    def produceScreenshotCoreName(self, _scrData):
        return str(_scrData.plotData[0]) + "_" + str(_scrData.plotData[1])

    def produceScreenshotName(self, _scrData):
        screenshotName = "Screenshot"
        screenshotCoreName = "Screenshot"

        if _scrData.spaceDimension == "2D":
            screenshotCoreName = self.produceScreenshotCoreName(_scrData)
            screenshotName = screenshotCoreName + "_" + _scrData.spaceDimension + "_" + _scrData.projection + "_" + str(
                _scrData.projectionPosition)
        elif _scrData.spaceDimension == "3D":
            screenshotCoreName = self.produceScreenshotCoreName(_scrData)
            screenshotName = screenshotCoreName + "_" + _scrData.spaceDimension + "_" + str(self.screenshotCounter3D)
        return (screenshotName, screenshotCoreName)

    def appendBoolChildElement(self, elem, elem_label, elem_value):
        """
        creates child xml element for boolean value

        :param elem: {inst. of XMLUtils.ElementCC3D} parent element
        :param elem_label: {str} name of the child elemenbt
        :param elem_value: {bool} flag
        :return: None
        """

        elem.ElementCC3D(elem_label, {"On": 1 if elem_value else 0})

    def parseAndAssignBoolChildElement(self, parent_elem, elem_label, obj, attr):
        """
        creates child xml element for boolean value

        :param parent_elem: {inst. of XMLUtils.ElementCC3D} parent element
        :param elem_label: {str} name of the child element
        :param obj: {object} object whose attribute will be set to elem value
        :param attr: {str} attribute name
        :return: None
        """
        elem = parent_elem.getFirstElement(elem_label)
        if elem:
            on_flag = int(elem.getAttribute("On"))
            setattr(obj, attr, bool(on_flag))

    def writeScreenshotDescriptionFile(self, fileName):
        from XMLUtils import ElementCC3D

        screenshotFileElement = ElementCC3D("CompuCell3DScreenshots")

        for name in self.screenshotDataDict:
            scrData = self.screenshotDataDict[name]
            scrDescElement = screenshotFileElement.ElementCC3D("ScreenshotDescription")
            if scrData.spaceDimension == "2D":
                scrDescElement.ElementCC3D("Dimension", {}, str(scrData.spaceDimension))
                scrDescElement.ElementCC3D("Plot",
                                           {"PlotType": str(scrData.plotData[1]), "PlotName": str(scrData.plotData[0])})
                scrDescElement.ElementCC3D("Projection", {"ProjectionPlane": scrData.projection,
                                                          "ProjectionPosition": str(scrData.projectionPosition)})

            if scrData.spaceDimension == "3D":
                scrDescElement.ElementCC3D("Dimension", {}, str(scrData.spaceDimension))
                scrDescElement.ElementCC3D("Plot",
                                           {"PlotType": str(scrData.plotData[1]), "PlotName": str(scrData.plotData[0])})
                scrDescElement.ElementCC3D("CameraClippingRange",
                                           {"Min": str(scrData.clippingRange[0]), "Max": str(scrData.clippingRange[1])})
                scrDescElement.ElementCC3D("CameraFocalPoint",
                                           {"x": str(scrData.focalPoint[0]), "y": str(scrData.focalPoint[1]),
                                            "z": str(scrData.focalPoint[2])})
                scrDescElement.ElementCC3D("CameraPosition",
                                           {"x": str(scrData.position[0]), "y": str(scrData.position[1]),
                                            "z": str(scrData.position[2])})
                scrDescElement.ElementCC3D("CameraViewUp", {"x": str(scrData.viewUp[0]), "y": str(scrData.viewUp[1]),
                                                            "z": str(scrData.viewUp[2])})

            scrDescElement.ElementCC3D("Size", {"Width": str(scrData.win_width),
                                                "Height": str(scrData.win_height)})

            # saving complete visulaization gui settings
            self.appendBoolChildElement(elem=scrDescElement, elem_label='CellBorders',
                                        elem_value=scrData.cell_borders_on)
            self.appendBoolChildElement(elem=scrDescElement, elem_label='Cells',
                                        elem_value=scrData.cells_on)
            self.appendBoolChildElement(elem=scrDescElement, elem_label='ClusterBorders',
                                        elem_value=scrData.cluster_borders_on)
            self.appendBoolChildElement(elem=scrDescElement, elem_label='CellGlyphs',
                                        elem_value=scrData.cell_glyphs_on)
            self.appendBoolChildElement(elem=scrDescElement, elem_label='FPPLinks',
                                        elem_value=scrData.fpp_links_on)
            self.appendBoolChildElement(elem=scrDescElement, elem_label='BoundingBox',
                                        elem_value=scrData.bounding_box_on)

            self.appendBoolChildElement(elem=scrDescElement, elem_label='LatticeAxes',
                                        elem_value=scrData.lattice_axes_on)

            self.appendBoolChildElement(elem=scrDescElement, elem_label='LatticeAxesLabels',
                                        elem_value=scrData.lattice_axes_labels_on)

            invisible_types_str = ''
            if scrData.invisible_types is not None:
                invisible_types_str = ','.join(list(map(lambda x:str(x), scrData.invisible_types)))

            scrDescElement.ElementCC3D("TypesInvisible", {},invisible_types_str)

            # scrDescElement.ElementCC3D("TypesInvisible", {},
            #                            scrData.invisible_types if scrData.invisible_types is not None and len(scrData.invisible_types) else '')

            # scrDescElement.ElementCC3D("CellBorders", {"On": 1 if scrData.cell_borders_on else 0})

        screenshotFileElement.CC3DXMLElement.saveXML(str(fileName))

    def readScreenshotDescriptionFile(self, _fileName):
        import XMLUtils

        xml2ObjConverter = XMLUtils.Xml2Obj()
        root_element = xml2ObjConverter.Parse(_fileName)
        scrList = XMLUtils.CC3DXMLListPy(root_element.getElements("ScreenshotDescription"))
        for scr in scrList:
            scrData = ScreenshotData()

            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='CellBorders', obj=scrData,
                                                attr='cell_borders_on')
            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='Cells', obj=scrData,
                                                attr='cells_on')
            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='ClusterBorders', obj=scrData,
                                                attr='cluster_borders_on')
            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='CellGlyphs', obj=scrData,
                                                attr='cell_glyphs_on')
            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='FPPLinks', obj=scrData,
                                                attr='fpp_links_on')

            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='BoundingBox', obj=scrData,
                                                attr='bounding_box_on')
            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='LatticeAxes', obj=scrData,
                                                attr='lattice_axes_on')
            self.parseAndAssignBoolChildElement(parent_elem=scr, elem_label='LatticeAxesLabels', obj=scrData,
                                                attr='lattice_axes_labels_on')

            try:
                types_invisible_elem_str = scr.getFirstElement("TypesInvisible").getText()
                if types_invisible_elem_str:
                    scrData.invisible_types = map(lambda x: int(x), types_invisible_elem_str.split(','))
                else:
                    scrData.invisible_types = []
            except:
                pass

            # borders_elem = scr.getFirstElement("CellBorders1")
            # if borders_elem:
            #     on_flag = int(borders_elem.getAttribute("On"))
            #
            #     scrData.cell_borders_on = bool(on_flag)
            plotElement = scr.getFirstElement("Plot")
            scrData.plotData = (plotElement.getAttribute("PlotName"), plotElement.getAttribute("PlotType"))

            sizeElement = scr.getFirstElement("Size")
            scrSize = [int(sizeElement.getAttribute("Width")), int(sizeElement.getAttribute("Height"))]

            if scr.getFirstElement("Dimension").getText() == "2D":
                print MODULENAME, "GOT 2D SCREENSHOT"

                scrData.spaceDimension = "2D"
                projElement = scr.getFirstElement("Projection")
                scrData.projection = projElement.getAttribute("ProjectionPlane")
                scrData.projectionPosition = int(projElement.getAttribute("ProjectionPosition"))

                # sizeElement = scr.getFirstElement("Size")
                # scrSize = [int(sizeElement.getAttribute("Width")), int(sizeElement.getAttribute("Height"))]

                # scrData initialized now will initialize graphics widget
                (scrName, scrCoreName) = self.produceScreenshotName(scrData)
                if not scrName in self.screenshotDataDict:
                    scrData.screenshotName = scrName
                    scrData.screenshotCoreName = scrCoreName
                    # scrData.screenshotGraphicsWidget = self.screenshotGraphicsWidget
                    self.screenshotDataDict[scrData.screenshotName] = scrData
                else:
                    print MODULENAME, "Screenshot ", scrName, " already exists"

            elif scr.getFirstElement("Dimension").getText() == "3D":

                scrData.spaceDimension = "3D"
                # plotElement = scr.getFirstElement("Plot")
                # scrData.plotData = (plotElement.getAttribute("PlotName"), plotElement.getAttribute("PlotType"))
                # sizeElement = scr.getFirstElement("Size")
                # scrSize = [int(sizeElement.getAttribute("Width")), int(sizeElement.getAttribute("Height"))]

                (scrName, scrCoreName) = self.produceScreenshotName(scrData)
                print MODULENAME, "(scrName,scrCoreName)=", (scrName, scrCoreName)
                okToAddScreenshot = True

                # extracting Camera Settings
                camSettings = []

                clippingRangeElement = scr.getFirstElement("CameraClippingRange")
                camSettings.append(float(clippingRangeElement.getAttribute("Min")))
                camSettings.append(float(clippingRangeElement.getAttribute("Max")))

                focalPointElement = scr.getFirstElement("CameraFocalPoint")
                camSettings.append(float(focalPointElement.getAttribute("x")))
                camSettings.append(float(focalPointElement.getAttribute("y")))
                camSettings.append(float(focalPointElement.getAttribute("z")))

                positionElement = scr.getFirstElement("CameraPosition")
                camSettings.append(float(positionElement.getAttribute("x")))
                camSettings.append(float(positionElement.getAttribute("y")))
                camSettings.append(float(positionElement.getAttribute("z")))

                viewUpElement = scr.getFirstElement("CameraViewUp")
                camSettings.append(float(viewUpElement.getAttribute("x")))
                camSettings.append(float(viewUpElement.getAttribute("y")))
                camSettings.append(float(viewUpElement.getAttribute("z")))

                for name in self.screenshotDataDict:
                    scrDataFromDict = self.screenshotDataDict[name]
                    if scrDataFromDict.screenshotCoreName == scrCoreName and scrDataFromDict.spaceDimension == "3D":
                        print MODULENAME, "scrDataFromDict.screenshotCoreName=", scrDataFromDict.screenshotCoreName, " scrCoreName=", scrCoreName

                        if scrDataFromDict.compareExistingCameraToNewCameraSettings(camSettings):
                            print MODULENAME, "CAMERAS ARE THE SAME"
                            okToAddScreenshot = False
                            break
                        else:
                            print MODULENAME, "CAMERAS ARE DIFFERENT"
                print MODULENAME, "okToAddScreenshot=", okToAddScreenshot

                if (not scrName in self.screenshotDataDict) and okToAddScreenshot:
                    scrData.screenshotName = scrName
                    scrData.screenshotCoreName = scrCoreName

                    # scrData.screenshotGraphicsWidget = self.screenshotGraphicsWidget

                    scrData.extractCameraInfoFromList(camSettings)
                    self.screenshotDataDict[scrData.screenshotName] = scrData

            else:
                print MODULENAME, "GOT UNKNOWN SCREENSHOT"

    def safe_writeScreenshotDescriptionFile(self, out_fname):
        """
        writes screenshot descr file in a safe mode. any problems are reported via warning
        :param out_fname: {str}
        :return: None
        """
        raise NotImplementedError()

    def serialize_screenshot_data(self):
        """
        Method called immediately after we add new screenshot via camera button. It serializes all screenshots data
        for future reference/reuse
        :return: None
        """
        raise NotImplementedError

    def add2DScreenshot(self, _plotName, _plotType, _projection, _projectionPosition, _camera):
        """
        adds screenshot stub based on current specification of graphics window
        Typically called from GraphicsFrameWidget
        :param _plotName:
        :param _plotType:
        :param _projection:
        :param _projectionPosition:
        :param _camera:
        :return:
        """
        raise NotImplementedError()

    def add3DScreenshot(self, _plotName, _plotType, _camera):
        """
        adds screenshot stub based on current specification of graphics window
        Typically called from GraphicsFrameWidget
        :param _plotName:
        :param _plotType:
        :param _projection:
        :param _projectionPosition:
        :param _camera:
        :return:
        """

        raise NotImplementedError()

    def outputScreenshots(self, _generalScreenshotDirectoryName,
                          _mcs):  # called from SimpleTabView:handleCompletedStep{Regular,CML*}
        """
        Outputs screenshot
        :param _generalScreenshotDirectoryName:
        :param _mcs:
        :return:
        """
        raise NotImplementedError()