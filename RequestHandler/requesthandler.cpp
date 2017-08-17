#include "requesthandler.h"
#include <qdebug.h>
RequestHandler::RequestHandler()
{
    this->compuCellModel = Model();
}

bool RequestHandler::openCompuCellModel(QString cc3dFilePath)
{
    bool isOpenModelSucess = false;

    QString COMPUCELL_3D_FILE_EXTENSION = ".cc3d";

    Q_ASSERT_X(cc3dFilePath != NULL, "Opening Simulation", "Null file path");
    Q_ASSERT_X(QFileInfo(cc3dFilePath).exists(), "Opening Simulation", "File does not exists");
    Q_ASSERT_X(cc3dFilePath.endsWith(COMPUCELL_3D_FILE_EXTENSION), "Opening Simulation", "Invalid File Extension");

    try
    {
        // Read the CompuCell3D project file (.cc3d)
        CC3DReader cc3dReader;
        ModelResouceData modelResourceData = cc3dReader.readCC3DFile(cc3dFilePath);
        this->compuCellModel.setModelResourceData(modelResourceData);
        qDebug() << "Reading file successful- " << cc3dFilePath;
    }
    catch(...)
    {
        isOpenModelSucess = false;
        qDebug() << "Unable to open File-" << cc3dFilePath;
    }

    isOpenModelSucess = true;
    return isOpenModelSucess;
}

QDomDocument RequestHandler::getModelXML()
{
    // Read the Model XML file and populate the Model Explorer and Editor
    ModelReader modelReader;
    ModelResouceData modelResourceData = this->compuCellModel.getModelResourceData();
    QDomDocument domDocument = modelReader.readModelXMLFile(modelResourceData.getModelXMLFilePath());
    qDebug() << "Reading XML file successful- " << modelResourceData.getModelXMLFilePath();

    qDebug() << domDocument.firstChildElement().nodeName();

    return domDocument;
}

RequestHandler::~RequestHandler()
{
    //delete this->compuCellModel;
}


