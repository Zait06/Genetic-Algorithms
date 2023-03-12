#ifndef POPULATION_H_
#define POPULATION_H_
#include <iostream>
#include <vector>
#include "PopulationBase.h"
#include "../Individual/Individual.h"
#include "../utils/utils.h"

// enum class InitType {
//   ZEROS,
//   RANDOM,
//   GRAY
// };

template <typename T>
class Population {
 private:
  std::vector<Individual<T>> m_population;
  int length, size;
  float sum, prob;

 public:
  Population(int size, int length);

  // void intiPop(InitType type);
  // void initPopRandom();
  // void initPopZeros();
  // void initPopGray();
};

#endif
