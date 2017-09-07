#include <statsy/reporter/reportables/reportables.h>
#include <statsy/reporter>
#include "ReportableClasses.cpp"


namespace reportables{
    Reportable* element_area(){
        return new AreaReport();
    }

    Reportable* edge_length(Value* value){
        return new LengthReport(value);
    }

    Reportable* inner_angle(Value* value){
        return new AngleReport(value);
    }

    Reportable* number_sides(){
        return new NumberSidesReport();
    }
}