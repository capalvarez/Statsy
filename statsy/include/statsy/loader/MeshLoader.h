#ifndef STATSY_MESHLOADER_H
#define STATSY_MESHLOADER_H

#include <statsy/geometry/Mesh.h>

class MeshLoader{
public:
    virtual std::vector<Polygon> getPolygons() = 0;
};

#endif