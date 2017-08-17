#include "modelreader.h"
#include <QFile>
#include <qdebug.h>

ModelReader::ModelReader()
{

}

QDomDocument ModelReader::readModelXMLFile(QString filePath)
{
    QFile cc3dFile(filePath);
    QDomDocument domDocument;

    if(!cc3dFile.open(QIODevice::ReadOnly))
    {
        qDebug()<< "Unable to open File in ReadMode: " << filePath;
    }

    domDocument.setContent(&cc3dFile, false);

    return domDocument;
}
