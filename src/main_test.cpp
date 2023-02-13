#include <iostream>
#include "Individual/Individual.h"
#include "Population/Population.h"
#include "gnuplot/gnuplot.h"
#include "utils/utils.h"

int main() {

  srand(time(NULL));

  // gnuplot myPlot;
  // myPlot << "plot [-pi/2:pi] cos(x),-(sin(x) > sin(x+1) ? sin(x) : sin(x+1))";

  // int min = 0;
  // int max = 101;
  // int range = max - min;
  // Eigen::ArrayX<float> perro = Eigen::ArrayX<float>::Random(6);
  // perro = (perro + Eigen::ArrayX<float>::Constant(6, 1)) * (range / 2);
  // perro = (perro + Eigen::ArrayX<float>::Constant(6, min));
  // std::cout << perro.cast<int>() << std::endl;

  Individual<GA_DOUBLE> ind(7);
  ind.init(25, 50);
  std::cout << ind << std::endl;

  Population<GA_DOUBLE> pop(7, 5);

  return 0;
}