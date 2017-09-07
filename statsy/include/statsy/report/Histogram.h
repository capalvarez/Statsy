#ifndef STATSY_HISTOGRAM_H
#define STATSY_HISTOGRAM_H

#include <vector>

class Histogram {
private:
    std::vector<double> binLimits;
    std::vector<int> frecuency;

    std::vector<double> outOfRange;
public:
    Histogram();
    Histogram(double min, double max, int bins);
    void addValue(double val);

    std::vector<int> getBinsFrecuency();
    std::vector<double> getBinsLimits();
    std::vector<double> reportErrors();
};

#endif