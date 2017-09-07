#ifndef STATSY_MESHLOADER_H
#define STATSY_MESHLOADER_H

#include <statsy/models/Mesh.h>

class MeshLoader{
public:
    virtual Mesh getMesh(std::string fileName) = 0;
};

#endif