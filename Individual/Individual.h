#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>

#include "../external/eigen/Eigen/Dense"
#include "../utils/utils.h"

template <typename T>
class Individual
{
private:
    // Attributes
    Eigen::ArrayX<T> allele;
    float fitness;
    float ve;
    

    // Methods
    // T randomNumber(T range);
    // void computeFitness();
    // void fitnessBool();
    // void fitnessNumber();

public:
    // Attributes
    int lenght;

    // Constructor
    // Individual(T *al);
    Individual();
    Individual(int len);
    Individual(Individual &other);

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
    void print();
};

#endif