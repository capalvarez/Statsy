#ifndef STATSY_REPORTABLE_H
#define STATSY_REPORTABLE_H

template <typename T>
class Reportable{
public:
     virtual double getValue(T elem) = 0;
};

#endif