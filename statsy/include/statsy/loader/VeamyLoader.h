#ifndef STATSY_VEAMYLOADER_H
#define STATSY_VEAMYLOADER_H

#include "MeshLoader.h"

class VeamyLoader: public MeshLoader {
public:
    Mesh getMesh();
};

#endif