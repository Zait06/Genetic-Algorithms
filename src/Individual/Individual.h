#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>
#include "../../external/eigen/Eigen/Dense"
#include "../utils/utils.h"

template <typename T>
class Individual {
 private:
  // Attributes
  Eigen::ArrayX<T> allele;
  float fitness;
  float ve;

  // Methods
  // void computeFitness();
  // void fitnessBool();
  // void fitnessNumber();

 public:
  // Attributes
  int lenght;
  Eigen::ArrayX<T> getAllele();

  // Constructor
  // Individual(T *al);
  Individual();
  Individual(int len);
  Individual(Individual& other);

  // Methods
  void init();
  void init(T);
  void init(T, T);
  void zeros();
  // void set(T *);
  // float getFitness();
  // void setVe(float prob);
  // T getGene(int);
  // void setGene(int, T);
  // float getVe();
  // T *get();
  friend std::ostream& operator<<(std::ostream& out, Individual<T>& ind) {
    out << ind.getAllele();
    return out;
  }
};

#endif