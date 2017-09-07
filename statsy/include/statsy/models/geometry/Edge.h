#ifndef STATSY_EDGE_H
#define STATSY_EDGE_H

#include <statsy/models/geometry/Vertex.h>
#include <cmath>
#include <stdexcept>

class Edge {
private:
    Vertex v1;
    Vertex v2;
public:
    Edge(Vertex v1, Vertex v2);
    double getLength();
    double computeInnerAngle(Edge other);
    Vertex moveToOrigin();
};

#endif