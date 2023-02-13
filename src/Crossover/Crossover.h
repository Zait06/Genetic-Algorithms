#ifndef CROSSOVER_H_
#define CROSSOVER_H_
#include "../Population/Population.h"

template <typename T>
class Crossover{
    public:
        Crossover();
        Population<T> onePoint(Population<T> pop);
        Population<T> twoPoints(Population<T> pop);
};

#endif