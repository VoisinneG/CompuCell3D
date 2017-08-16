#ifndef CC3DREADER_H
#define CC3DREADER_H

#include <modelresoucedata.h>
#include <QDomDocument>
#include <QFileInfo>
#include <QDir>

/**
 * This class responsible for reading CompuCell3D project file.
 * Which is a XML file with .cc3d extension.
 *
 */
class CC3DReader
{

public:
    CC3DReader();

    /**
     * @brief readCC3DFile
     * @param filePath
     * @return
     */
    ModelResouceData readCC3DFile(QString filePath);
};

#endif // CC3DREADER_H
