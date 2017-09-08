#include <statsy/report/reportables/Value.h>
#include <algorithm>

class Min: public Value{
public:
    double getValue(std::vector<double> vals){
        return *std::min_element(vals.begin(), vals.end());
    }
};

class Max: public Value{
public:
    double getValue(std::vector<double> vals){
        return *std::max_element(vals.begin(), vals.end());
    }
};

class Average : public Value{
public:
    double getValue(std::vector<double> vals){
        return std::accumulate(vals.begin(), vals.end(),0)/vals.size();
    }
};