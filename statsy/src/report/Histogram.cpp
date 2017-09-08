#include <statsy/report/Histogram.h>

Histogram::Histogram() {}

Histogram::Histogram(double min, double max, int bins) {
    double delta = (max-min)/bins;

    binLimits.push_back(min);
    frecuency.push_back(0);
    for (int i = 1; i <= bins; ++i) {
        binLimits.push_back(min+i*delta);
        frecuency.push_back(0);
    }
}

void Histogram::addValue(double val) {
    //TODO: What if they are equal
    auto lower = std::lower_bound(binLimits.begin(), binLimits.end(), val);
    int dist = std::distance(binLimits.begin(), lower);

    if(dist<=0 || dist>=binLimits.size()){
        outOfRange.push_back(val);
    } else{
        int& f = frecuency[dist];
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
