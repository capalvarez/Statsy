#ifndef STATSY_POLYGON_H
#define STATSY_POLYGON_H

#include <vector>
#include <statsy/models/geometry/Vertex.h>
#include <statsy/models/geometry/Edge.h>
#include <statsy/utils/utils.h>
#include <statsy/models/MeshElement.h>

class Polygon: public MeshElement {
private:
    std::vector<Edge> edges;
    double area;

    void computeArea(std::vector<Vertex> vertices);
public:
    Polygon(std::vector<Edge> e, std::vector<Vertex> v);

    double getArea();
    int numberOfSides();
    std::vector<double> getInnerAngles();
    std::vector<double> getEdgesLength();


};

#endif