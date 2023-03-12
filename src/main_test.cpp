#include <iostream>
#include <vector>
#include "Individual/Individual.h"
#include "Population/Population.h"
#include "gnuplot/gnuplot.h"
#include "utils/utils.h"

int main() {

  srand(time(NULL));

  // gnuplot myPlot;
  // myPlot << "plot [-pi/2:pi] cos(x),-(sin(x) > sin(x+1) ? sin(x) : sin(x+1))";

  Individual<gatype::DOUBLE> ind(7);
  ind.init(20);
  std::cout << ind << std::endl;

  std::vector<Individual<gatype::DOUBLE>> algo;

  for (int i = 0; i < 3; i++) {
    Individual<gatype::DOUBLE> ind(7);
    algo.push_back(ind);
  }

  // Population<gatype::DOUBLE> pop(7, 5);

  return 0;
}