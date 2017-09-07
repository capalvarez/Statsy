#ifndef STATSY_VALUE_H
#define STATSY_VALUE_H

#include <vector>

class Value{
public:
    virtual double getValue(std::vector<double> vals) = 0;
};

#endif