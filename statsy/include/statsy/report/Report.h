#ifndef STATSY_REPORT_H
#define STATSY_REPORT_H

#include "Histogram.h"

struct Report{
    double min, max, avg, dev;
    Histogram histogram;

    Report(double MIN, double MAX, double AVG, double DEV, Histogram& hist){
        min = MIN;
        max = MAX;
        avg = AVG;
        dev = DEV;
        histogram = hist;
    }
};

#endif