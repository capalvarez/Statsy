#ifndef STATSY_STATSPROCESSOR_H
#define STATSY_STATSPROCESSOR_H

#include <vector>
#include <statsy/report/Reportable.h>
#include <statsy/report/Report.h>
#include <cfloat>

template <typename T>
class StatProcessor {
private:
    std::vector<T>::iterator it;
    //TODO: Leave this default value elsewhere
    int bins = 10;
public:
    StatProcessor(std::vector<T>::iterator iterator);
    StatProcessor(std::vector<T>::iterator iterator, int bins);
    Report giveReport(Reportable *r, int bins);
    Report giveReport(Reportable* r);
};

template <typename T>
StatProcessor::StatProcessor(std::vector<T>::iterator iterator) {
    this->it = iterator;
}

template <typename T>
StatProcessor::StatProcessor(std::vector<T>::iterator iterator, int bins) {
    this->it = iterator;
    this->bins = bins;
}

template <typename T>
Report StatProcessor::giveReport(Reportable *r, int bins) {
    double max = DBL_MIN;
    double min = DBL_MAX;
    double sum = 0, sum2 = 0;

    int j = 0;
    for (auto i = this->it.begin() ; i != this->it.end(); ++i) {
        double value = r->getValue(*i);

        if(value < min){
            min = value;
        }

        if(value > max){
            max = value;
        }

        sum += value;
        sum2 += std::pow(value, 2);

        j++;
    }

    Histogram histogram(min, max, bins);
    for (auto i = this->it.begin() ; i != this->it.end(); ++i) {
        histogram.addValue( r->getValue(*i));
    }

    return Report(min, max, sum/j, (j*sum2 - sum*sum)/(j*j), histogram);
}

template <typename T>
Report StatProcessor::giveReport(Reportable *r) {
    return giveReport(r, this->bins);
}

#endif