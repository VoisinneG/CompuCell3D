#include "modelreader.h"
#include <QFile>

#include <iostream>
#include "XMLUtils/XMLParserExpat.h"
#include "BasicUtils/BasicException.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

ModelReader::ModelReader()
{

}

void ModelReader::readModelXMLFile(QString filePath)
{
    //TO-DO:: Asserts

    QFile cc3dFile(filePath);
    //QDomDocument domDocument;

    if(!cc3dFile.open(QIODevice::ReadOnly))
    {
       // qDebug()<< "Unable to open File in ReadMode: " << filePath;
    }

    // Create a XML Parser to read the XML model file
    XMLParserExpat parser;
    parser.setFileName(filePath.toStdString());
    parser.parse();

    // Read the data from parse and store in Parser Storage

    // Get Simulator

    Simulator sim;

    //extracting plugin elements from the XML file
    CC3DXMLElementList pluginDataList = parser.rootElement->getElements("Plugin");
    for (int i = 0; i < pluginDataList.size(); ++i) {
        cerr << "Plugin: " << pluginDataList[i]->getAttribute("Name") << endl;
        sim.ps.addPluginDataCC3D(pluginDataList[i]);
    }

    //extracting steppable elements from the XML file
    CC3DXMLElementList steppableDataList = parser.rootElement->getElements("Steppable");
    for (int i = 0; i < steppableDataList.size(); ++i) {
        cerr << "Steppable: " << steppableDataList[i]->getAttribute("Type") << endl;
        sim.ps.addSteppableDataCC3D(steppableDataList[i]);
    }

    // extracting Potts section
    CC3DXMLElementList pottsDataList = parser.rootElement->getElements("Potts");
    ASSERT_OR_THROW("You must have exactly 1 definition of the Potts section", pottsDataList.size() == 1);
    sim.ps.addPottsDataCC3D(pottsDataList[0]);

    //    extracting Metadata section
    CC3DXMLElementList metadataDataList = parser.rootElement->getElements("Metadata");
    if (metadataDataList.size() == 1) {
        sim.ps.addMetadataDataCC3D(metadataDataList[0]);
    }
    else {
        cerr << "Not using Metadata" << endl;
    }
    //     ASSERT_OR_THROW("You must have exactly 1 definition of the Metadata section",metadataDataList.size()==1);

    sim.initializeCC3D();

    sim.extraInit(); ///additional initialization after all plugins and steppables have been loaded and preinitialized

}
