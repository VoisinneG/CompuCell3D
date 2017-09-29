//
// Created by Anwar on 8/30/17.
//

#include "requesthandler.h"
#include "IO/cc3dreader.h"
#include "IO/modelreader.h"
#include <qdebug.h>
#include <QFileInfo>
#include "XMLUtils/XMLParserExpat.h"

bool RequestHandler::openCompuCellModel(QString cc3dFilePath) {

    bool isOpenModelSuccess = false;

    QString COMPUCELL_3D_FILE_EXTENSION = ".cc3d";

    Q_ASSERT_X(cc3dFilePath != NULL, "Opening Simulation", "Null file path");
    Q_ASSERT_X(QFileInfo(cc3dFilePath).exists(), "Opening Simulation", "File does not exists");
    Q_ASSERT_X(cc3dFilePath.endsWith(COMPUCELL_3D_FILE_EXTENSION, Qt::CaseInsensitive), "Opening Simulation", "Invalid File Extension");

    try
    {
        // Read the CompuCell3D project file (.cc3d)
        CC3DReader cc3dReader;
        ModelResouceData modelResourceData = cc3dReader.readCC3DFile(cc3dFilePath);

        // Set Model ResourceData which contains the information from .cc3d file
        this->compuCellModel.setModelResourceData(modelResourceData);
        qDebug() << "Reading file successful- " << cc3dFilePath;
    }
    catch(...)
    {
        isOpenModelSuccess = false;
        qDebug() << "Unable to open File-" << cc3dFilePath;
    }

    isOpenModelSuccess = true;
    return isOpenModelSuccess;
}

void RequestHandler::getModelXML()
{

    // Load model into simulation

    //return &parser;
}

RequestHandler::~RequestHandler()
{
    //delete this->compuCellModel;
}

bool RequestHandler::loadModelXML() {
    bool isModelLoadingSuceesful = false;
    try
    {
        // Read the XML file for the model
        ModelResouceData modelResouceData = this->compuCellModel.getModelResourceData();
        QString xMLFilePath = modelResouceData.getModelXMLFilePath();

        ModelReader modelReader;
        modelReader.readModelXMLFile(xMLFilePath);

        isModelLoadingSuceesful = true;

        qDebug() << QString(parser.rootElement->name.c_str());

    }
    catch(...)
    {
        isModelLoadingSuceesful = false;
    }

    isModelLoaded = isModelLoadingSuceesful;

    return isModelLoadingSuceesful;
}
