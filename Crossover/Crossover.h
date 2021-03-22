#ifndef CROSSOVER_H_
#define CROSSOVER_H_
#include "../Population/Population.h"
#include <iostream>
using namespace std;

class Crossover{
    public:
        Crossover();
        Population onePoint(Population pop);
        Population twoPoints(Population pop);
};

#endif