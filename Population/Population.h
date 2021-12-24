#ifndef POPULATION_H_
#define POPULATION_H_
#include "../Individual/Individual.h"
#include <iostream>
using namespace std;

template <typename T>
class Population{
    private:
        Individual<T> *pop;
        int length, size, option;
        float sum, prob;
    public:
        Population(int s);
        void initPop(int l, int op);
        int getSize();
        int getLen();
        void print();
        void computeSumProb();
        float getMax();
        float getMin();
        Individual<T> getIndividual(int index);
        Population join(Population p);
        void setIndividual(int index, T *ale);
        void setIndividual(int index, Individual<T> ind);
};

#endif