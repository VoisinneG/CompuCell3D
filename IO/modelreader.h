#ifndef MODELREADER_H
#define MODELREADER_H

#include<QDomDocument>

/**
 * This class is responsible for reading the XML file for the model.
 *
 */
class ModelReader
{
public:
    ModelReader();

    QDomDocument readModelXMLFile(QString filePath);
};

#endif // MODELREADER_H
