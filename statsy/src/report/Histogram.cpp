#include <statsy/report/Histogram.h>

Histogram::Histogram() {}

Histogram::Histogram(double min, double max, int bins) {
    double delta = (max-min)/bins;

    binLimits.push_back(min);
    for (int i = 1; i <= bins; ++i) {
        binLimits.push_back(min+i*delta);
    }
}

void Histogram::addValue(double val) {
    auto lower = std::lower_bound(binLimits.begin(), binLimits.end(), val);

    if(*lower<=0 || *lower>=binLimits.size()){
        outOfRange.push_back(val);
    } else{
        int& f = frecuency[*lower];
        f++;
    }
}

std::vector<int> Histogram::getBinsFrecuency() {
    return this->frecuency;
}

std::vector<double> Histogram::getBinsLimits() {
    return this->binLimits;
}

std::vector<double> Histogram::reportErrors() {
    return this->outOfRange;
}
