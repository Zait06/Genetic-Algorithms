#ifndef POPULATIONBASE_H_
#define POPULATIONBASE_H_
#include <iostream>
#include <vector>
#include "../Individual/Individual.h"
#include "../utils/utils.h"

class PopulationBase {
 private:
  int length, size;
  float sum, prob;

 public:
  PopulationBase(int size, int length);
};

#endif
