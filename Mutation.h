#ifndef MUTATION_H_
#define MUTATION_H_
#include "Population.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

class Mutation{
    private:
        float percent;
    public:
        Mutation(float);
        void mutBin(Population* pop);
};

#endif