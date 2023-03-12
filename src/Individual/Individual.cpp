#include "Individual.h"
#include <cmath>
#include <ctime>

template class Individual<gatype::BOOLEAN>;
template class Individual<gatype::INTEGER>;
template class Individual<gatype::DOUBLE>;
template class Individual<gatype::FLOAT>;

/**
 * @brief Create individual
 * @param len Alleles number
 */
template <typename T>
Individual<T>::Individual(int len) {
  allele = Eigen::VectorX<T>(len);
  lenght = len;
}

/**
 * @brief Create individual
 * @param other Individual
 */
template <typename T>
Individual<T>::Individual(Individual &other) {}

/**
 * @brief Create individual
 * @param allele A Eigen Vector
 */
template <typename T>
Individual<T>::Individual(Eigen::VectorX<T> allele) {
  this->allele = allele;
  lenght = (int)allele.rows();
}

/**
 * @brief Set values randomly
 */
template <typename T>
void Individual<T>::init() {
  allele = Eigen::VectorX<T>::Random(lenght);
}

/**
 * @brief Set values randomly with a range
 * @param range Max range random value
 */
template <typename T>
void Individual<T>::init(T range) {
  if (std::is_same<T, bool>::value) {
    init();
    return;
  }
  Eigen::VectorX<double> aux = Eigen::VectorX<double>::Random(lenght);
  aux = (aux + Eigen::VectorX<double>::Constant(lenght, 1)) * (range / 2.0);
  aux = (aux + Eigen::VectorX<double>::Constant(lenght, 0));
  allele = aux.cast<T>();
}

/**
 * @brief Set values randomly with a min and max range
 * @param min Min range random value
 * @param max Max range random value
 */
template <typename T>
void Individual<T>::init(T min, T max) {
  if (std::is_same<T, bool>::value) {
    init();
    return;
  }
  double range = (double)max - min;
  Eigen::VectorX<double> aux = Eigen::VectorX<double>::Random(lenght);
  aux = (aux + Eigen::VectorX<double>::Constant(lenght, 1)) * (range / 2.0);
  aux = (aux + Eigen::VectorX<double>::Constant(lenght, min));
  allele = aux.cast<T>();
}

/**
 * @brief Init population with zeros
 */
template <typename T>
void Individual<T>::zeros() {
  allele = Eigen::VectorX<T>::Zero(lenght);
}

/**
 * @brief Return allele
 */
template <typename T>
Eigen::VectorX<T> Individual<T>::getAllele() {
  return allele;
}

/**
 * @brief Set complete allele
 */
template <typename T>
void Individual<T>::setAllele(Eigen::VectorX<T> a) {
  if (a.rows() != this->lenght) return;
  this->allele = allele;
}