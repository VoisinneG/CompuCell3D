#include "cc3dreader.h"
#include <QXmlReader>
#include <qdebug.h>

CC3DReader::CC3DReader()
{
}

ModelResouceData CC3DReader::readCC3DFile(QString filePath)
{
    Q_ASSERT_X(!filePath.isNull(), "readCC3DFile", "File path is NULL");
    Q_ASSERT_X(!filePath.isEmpty(), "readCC3DFile", "File path is Empty");
    Q_ASSERT_X(QFile::exists(filePath), "readCC3DFile", "File does not exists");

    ModelResouceData modelResourceData;

    /**
     * Read the Compucell3D project file (.cc3d) which is a XML file containing list of
     * all the resources in the project.
     */

    QFileInfo fileInfo(filePath);
    QDir modelDir = fileInfo.dir();

    QDomDocument domDocument;
    QFile cc3dFile(filePath);

    if(!cc3dFile.open(QIODevice::ReadOnly))
    {
        qDebug()<< "Unable to open File in ReadMode: " << filePath;
    }

    domDocument.setContent(&cc3dFile, false);

    // Get the Top-most element (node) in the document
    QDomElement simulationDomElement = domDocument.documentElement();

    // Get the node name ('Simulation')
    QString nodeName = simulationDomElement.nodeName();
    if(nodeName == "Simulation")
    {
        // Get the model Version number
        QString modelVersion = simulationDomElement.attribute("version");

        // Validate the version string

        // Set the version string to modelResourceData
        modelResourceData.setVersionNumber(modelVersion);
    }

    // Get the model XML Script element
    QDomElement modelXMLDomElement = simulationDomElement.firstChildElement("XMLScript");
    if(!modelXMLDomElement.isNull())
    {
        // Get the file path
        QString modelXMLFilePath = modelXMLDomElement.text();
        modelXMLFilePath = modelDir.absoluteFilePath(modelXMLFilePath);

        modelResourceData.setModelXMLFilePath(modelXMLFilePath);
    }

    // Get the model python element
    QDomElement modelPythonDomElement = simulationDomElement.firstChildElement("PythonScript");
    if(!modelPythonDomElement.isNull())
    {
        QString modelPythonFilePath = modelPythonDomElement.text();
        modelPythonFilePath = modelDir.absoluteFilePath(modelPythonFilePath);

        modelResourceData.setModelPythonFilePath(modelPythonFilePath);
    }

    // Get the remaining resources in the file by iterating over resources
    QDomElement resourceDomElement = simulationDomElement.firstChildElement("Resource");
    while(!resourceDomElement.isNull())
    {
        QString resourceFilePath = resourceDomElement.text();
        resourceFilePath = modelDir.absoluteFilePath(resourceFilePath);

        QString resourceType = resourceDomElement.attribute("Type");

        modelResourceData.addResource(resourceFilePath, resourceType);

        resourceDomElement = resourceDomElement.nextSiblingElement("Resource");
    }


    QString modelSettingFilePath = "";


    return modelResourceData;
}
