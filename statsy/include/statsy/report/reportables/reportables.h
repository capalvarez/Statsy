#ifndef STATSY_REPORTABLES_H
#define STATSY_REPORTABLES_H

#include <statsy/report/reportables/Value.h>
#include <statsy/report/Reportable.h>
#include <statsy/models/geometry/Polygon.h>

namespace reportables{
    Reportable<Polygon*>* element_area();
    Reportable<Polygon*>* edge_length(Value* v);
    Reportable<Polygon*>* inner_angle(Value* v);
    Reportable<Polygon*>* number_sides();
}

#endif