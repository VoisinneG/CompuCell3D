#include "cc3dreader.h"
#include <QXmlReader>

CC3DReader::CC3DReader()
{
}

ModelResouceData CC3DReader::readCC3DFile(QString filePath)
{
    // ASSERTS

    ModelResouceData modelResourceData;

    /**
     * Read the Compucell3D project file (.cc3d) which is a XML file containing list of
     * all the resources in the project.
     */



    QString modelXMLFilePath = "";
    QString modelPythonFilePath = "";
    QString modelSettingFilePath = "";

    QMap<QString, ResourceType> modelResourceFilePathToTypeMap;
    modelResourceFilePathToTypeMap.insert("", ResourceType::PYTHON);

    // Read the .cc3d (XML) file and populate the file paths

    // Check if all the file exists and readable. Raise appropriate errors.

    return modelResourceData;
}
