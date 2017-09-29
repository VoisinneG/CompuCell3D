#ifndef MODELREADER_H
#define MODELREADER_H

#include <QDebug>
//#include <QString>


/**
 * This class is responsible for reading the XML file for the model.
 *
 */
class ModelReader
{
public:
    ModelReader();

    void readModelXMLFile(QString filePath);
};

#endif // MODELREADER_H
