#ifndef SELECTION_H_
#define SELECTION_H_
#include "../Population/Population.h"
#include <iostream>
using namespace std;

class Selection{
    public:
        Selection();
        Population roulette(Population p);
        Population tournament(Population p);
};

#endif