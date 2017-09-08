#include <statsy/report/reportables/values.h>
#include "ValueClasses.cpp"

namespace values{
    Value* min(){
        return new Min();
    }

    Value* max(){
        return new Max();
    }

    Value* average(){
        return new Average();
    }
}