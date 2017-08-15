#ifndef COMPUCELLMODEL_H
#define COMPUCELLMODEL_H

#include "model_global.h"
#include <modelresoucedata.h>

class MODELSHARED_EXPORT Model
{

private:

    ModelResouceData modelResourceData;

public:
    Model();

    ModelResouceData getModelResourceData() const;

    void setModelResourceData(const ModelResouceData value);

    ~Model();
};

#endif // COMPUCELLMODEL_H
