#include "modelresoucedata.h"

void ModelResouceData::intialize()
{
    this->modelPythonFilePath = "";
    this->modelSettingFilePath = "";
    this->modelXMLFilePath = "";
    this->modelResourceFilePathToTypeMap;
}

ModelResouceData::ModelResouceData()
{
    this->intialize();
}

QString ModelResouceData::getModelXMLFilePath() const
{
    return modelXMLFilePath;
}

void ModelResouceData::setModelXMLFilePath(const QString &value)
{
    modelXMLFilePath = value;
}

QString ModelResouceData::getModelPythonFilePath() const
{
    return modelPythonFilePath;
}

void ModelResouceData::setModelPythonFilePath(const QString &value)
{
    modelPythonFilePath = value;
}

QString ModelResouceData::getModelSettingFilePath() const
{
    return modelSettingFilePath;
}

void ModelResouceData::setModelSettingFilePath(const QString &value)
{
    modelSettingFilePath = value;
}

QMap<QString, ResourceType> ModelResouceData::getModelResourceFilePathToTypeMap() const
{
    return modelResourceFilePathToTypeMap;
}

void ModelResouceData::setModelResourceFilePathToTypeMap(const QMap<QString, ResourceType> &value)
{
    modelResourceFilePathToTypeMap = value;
}
