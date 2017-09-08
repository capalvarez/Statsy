#ifndef STATSY_MESHLOADER_H
#define STATSY_MESHLOADER_H

#include <statsy/models/Mesh.h>

template <typename T>
class MeshLoader{
public:
    virtual Mesh<T> getMesh(std::string fileName) = 0;
};

#endif