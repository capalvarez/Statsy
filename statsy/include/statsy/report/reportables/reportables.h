#ifndef STATSY_REPORTABLES_H
#define STATSY_REPORTABLES_H

#include <statsy/reporter/reportables/Value.h>
#include <statsy/reporter/Reportable.h>

namespace reportables{
    Reportable* element_area();
    Reportable* edge_length(Value* v);
    Reportable* inner_angle(Value* v);
    Reportable* number_sides();
}

#endif