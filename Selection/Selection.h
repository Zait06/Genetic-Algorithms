#ifndef SELECTION_H_
#define SELECTION_H_
#include "../Population/Population.h"
#include <iostream>

template <typename T>
class Selection{
    public:
        static Population<T> roulette(Population<T> p);
        static Population<T> tournament(Population<T> p);
};

#endif