#ifndef STATSY_STATSPROCESSOR_H
#define STATSY_STATSPROCESSOR_H

#include <vector>
#include <statsy/report/Reportable.h>
#include <statsy/report/Report.h>
#include <cfloat>

template <typename T>
class StatProcessor {
private:
    typename std::vector<T> it;
public:
    StatProcessor(std::vector<T> iterator);
    Report giveReport(Reportable<T> *r, int bins);
};

template <typename T>
StatProcessor<T>::StatProcessor(std::vector<T> iterator) {
    this->it = iterator;
}

template <typename T>
Report StatProcessor<T>::giveReport(Reportable<T> *r, int bins) {
    double max = DBL_MIN;
    double min = DBL_MAX;
    double sum = 0, sum2 = 0;

    int i;
    for (i = 0 ; i < this->it.size(); ++i) {
        double value = r->getValue(it[i]);

        if(value < min){
            min = value;
        }

        if(value > max){
            max = value;
        }

        sum += value;
        sum2 += std::pow(value, 2);
    }

    Histogram histogram(min, max, bins);
    for (i = 0 ; i < this->it.size(); ++i) {
        histogram.addValue( r->getValue(it[i]));
    }

    return Report(min, max, sum/i, (i*sum2 - sum*sum)/(i*i), histogram);
}



#endif