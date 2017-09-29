#ifndef COMPUCELLMODEL_H
#define COMPUCELLMODEL_H

#include "modelresoucedata.h"

class Model
{

private:

    ModelResouceData modelResourceData;

    Simulator* simulator;


public:
    Model();

    ModelResouceData getModelResourceData() const;

    void setModelResourceData(const ModelResouceData value);

    ~Model();
};

#endif // COMPUCELLMODEL_H
