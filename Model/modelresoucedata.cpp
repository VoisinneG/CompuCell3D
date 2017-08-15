#include "modelresoucedata.h"

void ModelResouceData::intialize()
{
    this->modelPythonFilePath = "";
    this->modelSettingFilePath = "";
    this->modelXMLFilePath = "";
    this->modelResourceFilePathToTypeMap.clear();
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
    Q_ASSERT_X(!value.isNull(), "setModelXMLFilePath", "File path is NULL");
    Q_ASSERT_X(!value.isEmpty(), "setModelXMLFilePath", "File path is Empty");
    Q_ASSERT_X(QFile::exists(value), "setModelXMLFilePath", "File does not exists");

    modelXMLFilePath = value;
}

QString ModelResouceData::getModelPythonFilePath() const
{
    return modelPythonFilePath;
}

void ModelResouceData::setModelPythonFilePath(const QString &value)
{
    Q_ASSERT_X(!value.isNull(), "setModelPythonFilePath", "File path is NULL");
    Q_ASSERT_X(!value.isEmpty(), "setModelPythonFilePath", "File path is Empty");
    Q_ASSERT_X(QFile::exists(value), "setModelPythonFilePath", "File does not exists");


    modelPythonFilePath = value;
}

QString ModelResouceData::getModelSettingFilePath() const
{
    return modelSettingFilePath;
}

void ModelResouceData::setModelSettingFilePath(const QString &value)
{
    Q_ASSERT_X(!value.isNull(), "setModelSettingFilePath", "File path is NULL");
    Q_ASSERT_X(!value.isEmpty(), "setModelSettingFilePath", "File path is Empty");
    Q_ASSERT_X(QFile::exists(value), "setModelSettingFilePath", "File does not exists");


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

QVersionNumber ModelResouceData::getVersionNumber() const
{
    return versionNumber;
}

void ModelResouceData::setVersionNumber(const QString value)
{
    // TO-DO: Validate the string value
    versionNumber = QVersionNumber::fromString(value);
}

void ModelResouceData::addResource(QString resourceFilePath, QString resourceType)
{
    Q_ASSERT_X(!resourceFilePath.isNull(), "addResource", "File path is NULL");
    Q_ASSERT_X(!resourceFilePath.isEmpty(), "addResource", "File path is Empty");
    Q_ASSERT_X(QFile::exists(resourceFilePath), "addResource", "File does not exists");

    // Validate and add the resource
}



