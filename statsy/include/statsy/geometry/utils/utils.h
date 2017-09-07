#ifndef MESHSTATS_UTILS_H
#define MESHSTATS_UTILS_H

#include <statsy/geometry/Vertex.h>
#include <vector>

namespace utils {
    extern double area2(Vertex p1, Vertex p2, Vertex p3);
    extern double triangleArea(Vertex p1, Vertex p2, Vertex origin);
    extern double area(std::vector<Vertex> points);
};

#endif