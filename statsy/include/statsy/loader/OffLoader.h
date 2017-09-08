#ifndef STATSY_OFFLOADER_H
#define STATSY_OFFLOADER_H

#include "MeshLoader.h"

class OffLoader: public MeshLoader<Polygon>{
    Mesh<Polygon> getMesh(std::string file);
};


#endif