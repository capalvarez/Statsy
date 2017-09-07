#ifndef STATSY_MESH_H
#define STATSY_MESH_H

#include <vector>
#include <wingdi.h>
#include <statsy/report/Report.h>
#include <statsy/report/Reportable.h>
#include "Polygon.h"

class MeshLoader;

class Mesh {
private:
    std::vector<Polygon> polygons;
public:
    Mesh();
    Mesh(const Mesh& other);
    void load_mesh(MeshLoader* loader);
    std::vector<Report> getReports(std::vector<Reportable*> toReport);
};

#endif