#include "Individual.h"
#include <ctime>
#include <cmath>

template class Individual<GA_INT>;
template class Individual<GA_BOOL>;
template class Individual<GA_FLOAT>;
template class Individual<GA_DOUBLE>;

template <typename T>
Individual<T>::Individual(int len) {
    allele = Eigen::ArrayX<T>(len);
    lenght = len;
}

template <typename T>
Individual<T>::Individual(Individual &other) {}

template <typename T>
Individual<T>::Individual() {}

template <typename T>
void Individual<T>::init()
{
    allele = Eigen::ArrayX<T>::Random(lenght);
}

template <typename T>
void Individual<T>::init(T range)
{
    if (std::is_same<T, bool>::value) {
        init();
        return;
    }
    Eigen::ArrayX<double> aux = Eigen::ArrayX<double>::Random(lenght);
    aux = (aux + Eigen::ArrayX<double>::Constant(lenght, 1)) * (range / 2.0);
    aux = (aux + Eigen::ArrayX<double>::Constant(lenght, 0));
    allele = aux.cast<T>();
}

template <typename T>
void Individual<T>::init(T min, T max)
{
    if (std::is_same<T, bool>::value) {
        init();
        return;
    }
    double range = (double) max - min;
    Eigen::ArrayX<double> aux = Eigen::ArrayX<double>::Random(lenght);
    aux = (aux + Eigen::ArrayX<double>::Constant(lenght, 1)) * (range / 2.0);
    aux = (aux + Eigen::ArrayX<double>::Constant(lenght, min));
    allele = aux.cast<T>();
}

template <typename T>
void Individual<T>::zeros()
{
    allele = Eigen::ArrayX<T>::Zero(lenght);
}

// template <typename T>
// void Individual<T>::set(T *s)
// {
//     allele = s;
// }

// template <typename T>
// float Individual<T>::getFitness()
// {
//     return fitness;
// }

// template <typename T>
// void Individual<T>::setVe(float prob)
// {
//     ve = fitness / prob;
// }

// template <typename T>
// float Individual<T>::getVe()
// {
//     return ve;
// }

// template <typename T>
// T *Individual<T>::get()
// {
//     return allele;
// }

// template <typename T>
// void Individual<T>::setGene(int i, T a)
// {
//     allele(i) = a;
// }

// template <typename T>
// T Individual<T>::getGene(int i)
// {
//     return allele(i);
// }

// template <typename T>
// T Individual<T>::randomNumber(T range)
// {
//     return T(rand()) / (T(RAND_MAX / (range)));
// }

// template <typename T>
// void Individual<T>::computeFitness()
// {
//     if (std::is_same<T, bool>::value) fitnessBool();
//     else fitnessNumber();
// }

// template <typename T>
// void Individual<T>::fitnessBool() {
//     fitness = 0;
//     for(int i = lenght - 1, j = 0; i >= 0; i--, j++) {
//         fitness += allele(i) ? pow(2, j) : 0;  
//     }
// }

template <typename T>
void Individual<T>::print() {
    std::cout << allele << std::endl;
}