//
// Created by Anwar on 8/30/17.
//

#ifndef COMPUCELL3D_REQUESTHANDLER_H
#define COMPUCELL3D_REQUESTHANDLER_H


#include "Model/CompuCellModel.h"

/**
 * This class is responsible for taking in requests from UI or CLI for processing with CompuCell3D.
 */
class RequestHandler {


private:
    // Model class object which holds all the data for CompuCell3D Model
    Model compuCellModel;

    bool isModelLoaded;

public:

    bool openCompuCellModel(QString cc3dFilePath);

    bool loadModelXML();

    void startSimulation();

    void stepSimulation();

    void pauseSimulation();

    void stopSimulation();

    void resumeSimulation();

    void getModelXML();

    ~RequestHandler();

};


#endif //COMPUCELL3D_REQUESTHANDLER_H
