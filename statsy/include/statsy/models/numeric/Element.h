#ifndef STATSY_ELASTICITYELEMENT_H
#define STATSY_ELASTICITYELEMENT_H

#include <vector>
#include <statsy/models/MeshElement.h>
#include "Displacement.h"
#include <cmath>

class Element : public MeshElement{
private:
    std::vector<Displacement> displacement;
public:
    Element(std::vector<Displacement> d);

    std::vector<double> getXDisp();
    std::vector<double> getYDisp();
    std::vector<double> getNorm();
};

#endif