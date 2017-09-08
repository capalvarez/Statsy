#include <statsy/config/StatsyConfig.h>

StatsyConfig* StatsyConfig::s_instance = nullptr;

StatsyConfig::StatsyConfig() {
    this->default_bins = 10;
    this->double_comparison_tolerance = 0.0001;
}

void StatsyConfig::setNumberOfBins(int bins) {
    this->default_bins = bins;
}

void StatsyConfig::setTolerance(double t) {
    this->double_comparison_tolerance = t;
}

int StatsyConfig::getNumberOfBins() {
    return this->default_bins;
}

double StatsyConfig::getTolerance() {
    return this->double_comparison_tolerance;
}

StatsyConfig *StatsyConfig::instance() {
    if(!s_instance){
        s_instance = new StatsyConfig;
    }

    return s_instance;
}

