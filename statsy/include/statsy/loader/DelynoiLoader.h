#ifndef STATSY_DELYNOILOADER_H
#define STATSY_DELYNOILOADER_H

#include "MeshLoader.h"

class DelynoiLoader : public MeshLoader {
public:
    Mesh getMesh();
};

#endif