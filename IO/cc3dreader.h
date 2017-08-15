#ifndef CC3DREADER_H
#define CC3DREADER_H

#include "io_global.h"
#include <modelresoucedata.h>

class IOSHARED_EXPORT CC3DReader
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
