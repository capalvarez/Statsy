#ifndef STATSY_STATSYCONFIG_H
#define STATSY_STATSYCONFIG_H

class StatsyConfig{
private:
    double double_comparison_tolerance;
    int default_bins;

    static StatsyConfig* s_instance;

    StatsyConfig();
    StatsyConfig(const StatsyConfig& other) = delete;
    StatsyConfig&operator=(const StatsyConfig& copy) = delete;
public:
    void setNumberOfBins(int bins);
    void setTolerance(double t);

    int getNumberOfBins();
    double getTolerance();

    static StatsyConfig* instance();

};

#endif