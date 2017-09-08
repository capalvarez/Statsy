#include <statsy/report/Reportable.h>
#include <vector>
#include <statsy/models/geometry/Polygon.h>
#include <statsy/report/reportables/Value.h>

class AngleReport: public Reportable<Polygon*>{
private:
    Value* value;
public:
    AngleReport(Value* value){
        this->value = value;
    }

    double getValue(Polygon* p){
        return value->getValue(p->getInnerAngles());
    }
};

class LengthReport: public Reportable<Polygon*>{
private:
    Value* value;
public:
    LengthReport(Value* value){
        this->value = value;
    }

    double getValue(Polygon* p){
        return value->getValue(p->getEdgesLength());
    }
};

class AreaReport: public Reportable<Polygon*>{
public:
    double getValue(Polygon* p){
        return p->getArea();
    }
};

class NumberSidesReport: public Reportable<Polygon*>{
public:
    double getValue(Polygon* p){
        return p->numberOfSides();
    }
};

