#include "Individual.h"
#include <ctime>
#include <cmath>

template class Individual<int>;
template class Individual<bool>;
template class Individual<float>;

template <typename T>
Individual<T>::Individual(int len)
{
    this->allele = new T[len];
    this->lenght = len;
}

template <typename T>
Individual<T>::Individual(T *ale)
{
    int i = 0;
    allele = ale;
    while (true)
    {
        if (ale[i] == '\0')
            break;
        i++;
    }
    lenght = i;
}

template <typename T>
Individual<T>::Individual() {}

template <typename T>
void Individual<T>::init()
{
    if (std::is_same<T, bool>::value) {
        for (int i = 0; i < lenght; i++) allele[i] = rand() % 2;
    }else init(lenght);
}

template <typename T>
void Individual<T>::init(T range)
{
    if (std::is_same<T, bool>::value)
        init();
    for (int i = 0; i < lenght; i++)
        allele[i] = randomNumber(range);
}

template <typename T>
void Individual<T>::init(T min, T max)
{
    if (std::is_same<T, bool>::value) init();
    for (int i = 0; i < lenght; i++)
        allele[i] = min + randomNumber(max - min);
}

template <typename T>
void Individual<T>::zeros()
{
    for (int i = 0; i < lenght; i++) allele[i] = 0.0;
}

template <typename T>
void Individual<T>::set(T *s)
{
    allele = s;
}

template <typename T>
float Individual<T>::getFitness()
{
    return fitness;
}

template <typename T>
void Individual<T>::setVe(float prob)
{
    ve = fitness / prob;
}

template <typename T>
float Individual<T>::getVe()
{
    return ve;
}

template <typename T>
T *Individual<T>::get()
{
    return allele;
}

template <typename T>
void Individual<T>::setGene(int i, T a)
{
    allele[i] = a;
}

template <typename T>
T Individual<T>::getGene(int i)
{
    return allele[i];
}

template <typename T>
void Individual<T>::print()
{
    for (int i = 0; i < lenght; i++)
        std::cout << "|" << allele[i];
    std::cout << "|" << std::endl;
}

template <typename T>
T Individual<T>::randomNumber(T range)
{
    return T(rand()) / (T(RAND_MAX / (range)));
}

template <typename T>
void Individual<T>::computeFitness()
{
    if (std::is_same<T, bool>::value) fitnessBool();
    else fitnessNumber();
}

template <typename T>
void Individual<T>::fitnessBool() {
    fitness = 0;
    for(int i = lenght - 1, j = 0; i >= 0; i--, j++) {
        fitness += allele[i] ? pow(2, j) : 0;  
    }
}

template <typename T>
void Individual<T>::fitnessNumber() {}