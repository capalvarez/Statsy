#ifndef STATSY_VEAMYLOADER_H
#define STATSY_VEAMYLOADER_H

#include <statsy/models/numeric/Element.h>
#include "MeshLoader.h"

class VeamyLoader: public MeshLoader<Element> {
public:
    Mesh<Element> getMesh(std::string file);
};

#endif