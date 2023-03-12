#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>
#include "../../external/eigen/Eigen/Dense"
#include "../utils/utils.h"

template <typename T>
class Individual {
 private:
  Eigen::VectorX<T> allele;
  float fitness;
  float ve;

 public:
  int lenght;

  Individual(int len);
  Individual(Individual& other);
  Individual(Eigen::VectorX<T> allele);

  void init();
  void init(T);
  void init(T, T);
  void zeros();

  Eigen::VectorX<T> getAllele();
  void setAllele(Eigen::VectorX<T> a);

  friend std::ostream& operator<<(std::ostream& out, Individual<T>& ind) {
    out << ind.getAllele().transpose();
    return out;
  }
};

#endif