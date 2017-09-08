#ifndef STATSY_MESH_H
#define STATSY_MESH_H

#include <vector>
#include <statsy/report/Report.h>
#include <statsy/report/Reportable.h>
#include <statsy/models/geometry/Polygon.h>
#include <statsy/report/StatProcessor.h>
#include <statsy/models/numeric/Element.h>

template <typename T>
class Mesh {
private:
    std::vector<T*> elements;
public:
    Mesh();
    Mesh(std::vector<T*> e);
    ~Mesh();
    Mesh(const Mesh& other);
    std::vector<Report> getReports(std::vector<Reportable<T*>*> toReport);
    std::vector<Report> getReports(std::vector<Reportable<T*>*> toReport, std::vector<int> bins);
};

#endif