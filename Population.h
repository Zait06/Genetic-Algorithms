#ifndef POPULATION_H_
#define POPULATION_H_
#include "Individual.h"
#include <iostream>
using namespace std;

class Population{
    private:
        Individual *pop;
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
        Individual getIndividual(int index);
        Population join(Population p);
        void setIndividual(int index, int *ale);
        void setIndividual(int index, Individual ind);
};

#endif