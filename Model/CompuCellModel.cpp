#include "CompuCellModel.h"


Model::Model()
{
    //this->modelResourceData = NULL;
}


ModelResouceData Model::getModelResourceData() const
{
    return modelResourceData;
}

void Model::setModelResourceData(ModelResouceData value)
{
    modelResourceData = value;
}

Model::~Model()
{
    //delete this->modelResourceData;
}

