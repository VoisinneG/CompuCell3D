#ifndef MODELRESOUCEDATA_H
#define MODELRESOUCEDATA_H

#include<QString>
#include<QMap>
#include<resourcetype.h>

class ModelResouceData
{

private:

    QString modelXMLFilePath;
    QString modelPythonFilePath;
    QString modelSettingFilePath;

    QMap<QString, ResourceType> modelResourceFilePathToTypeMap;

    void intialize();

public:
    ModelResouceData();

    QString getModelXMLFilePath() const;
    void setModelXMLFilePath(const QString &value);

    QString getModelPythonFilePath() const;
    void setModelPythonFilePath(const QString &value);

    QString getModelSettingFilePath() const;
    void setModelSettingFilePath(const QString &value);

    QMap<QString, ResourceType> getModelResourceFilePathToTypeMap() const;
    void setModelResourceFilePathToTypeMap(const QMap<QString, ResourceType> &value);
};

#endif // MODELRESOUCEDATA_H
