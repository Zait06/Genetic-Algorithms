#include "Population.h"

template class Population<gatype::BOOLEAN>;
template class Population<gatype::INTEGER>;
template class Population<gatype::DOUBLE>;
template class Population<gatype::FLOAT>;

/**
 * @brief Create population
 * @param size Population size
 * @param length Alleles number
 */
template <typename T>
Population<T>::Population(int size, int length) {
  sum = 0;
  prob = 0;
  // m_population = new std::vector<Individual<T>>();

  for (int i = 0; i < size; i++) {
    Individual<T> ind(length);
  }
}
