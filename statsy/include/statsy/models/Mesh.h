#ifndef STATSY_MESH_H
#define STATSY_MESH_H

#include <vector>
#include <wingdi.h>
#include <statsy/report/Report.h>
#include <statsy/report/Reportable.h>
#include <statsy/models/geometry/Polygon.h>

class Mesh {
private:
    std::vector<MeshElement*> elements;
public:
    Mesh();
    Mesh(const Mesh& other);
    std::vector<Report> getReports(std::vector<Reportable*> toReport);
};

#endif