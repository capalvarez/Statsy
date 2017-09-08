#ifndef STATSY_DELYNOILOADER_H
#define STATSY_DELYNOILOADER_H

#include "MeshLoader.h"
#include <statsy/reader/LineReader.h>
#include <fstream>

class DelynoiLoader : public MeshLoader<Polygon> {
public:
    Mesh<Polygon> getMesh(std::string file);
};

#endif