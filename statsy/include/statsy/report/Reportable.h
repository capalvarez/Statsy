#ifndef STATSY_REPORTABLE_H
#define STATSY_REPORTABLE_H

#include <statsy/models/geometry/Polygon.h>

template <typename T>
class Reportable{
public:
     virtual double getValue(T element) = 0;
};

#endif