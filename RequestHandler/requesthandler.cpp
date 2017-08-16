#include "requesthandler.h"

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

    // Read the CompuCell3D project file (.cc3d)
    CC3DReader cc3dReader;
    ModelResouceData modelResourceData = cc3dReader.readCC3DFile(cc3dFilePath);
    this->compuCellModel.setModelResourceData(modelResourceData);


    // Read the Model XML file and populate the Model Explorer and Editor
//    ModelReader modelReader;
//    QDomDocument domDocument = modelReader.readModelXMLFile(modelResourceData.getModelXMLFilePath());
//    this->testDocument = domDocument;

    return isOpenModelSucess;
}

QDomDocument RequestHandler::getModelXML()
{
    return this->testDocument;
}

RequestHandler::~RequestHandler()
{
    //delete this->compuCellModel;
}


