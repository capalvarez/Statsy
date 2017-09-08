#ifndef STATSY_DISPLACEMENT_H
#define STATSY_DISPLACEMENT_H

#include <statsy/models/geometry/Vertex.h>

struct Displacement{
    double x, y;
    Vertex vertex;

    Displacement(double u, double v, Vertex point){
        x = u;
        y = v;
        vertex = point;
    }
};

#endif