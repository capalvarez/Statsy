#ifndef STATSY_POLYGON_H
#define STATSY_POLYGON_H

#include <vector>
#include <statsy/geometry/Vertex.h>
#include <statsy/geometry/Edge.h>
#include <statsy/geometry/utils/utils.h>

class Polygon {
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