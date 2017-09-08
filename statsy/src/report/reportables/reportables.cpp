#include <statsy/report/reportables/reportables.h>
#include "ReportableClasses.cpp"


namespace reportables{
    Reportable<Polygon*>* element_area(){
        return new AreaReport();
    }

    Reportable<Polygon*>* edge_length(Value* value){
        return new LengthReport(value);
    }

    Reportable<Polygon*>* inner_angle(Value* value){
        return new AngleReport(value);
    }

    Reportable<Polygon*>* number_sides(){
        return new NumberSidesReport();
    }
}