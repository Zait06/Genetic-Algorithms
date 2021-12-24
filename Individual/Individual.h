#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>

template <typename T>
class Individual
{
private:
    // Attributes
    T *allele;
    float fitness;
    float ve;

    // Methods
    T randomNumber(T range);

public:
    // Attributes
    int lenght;

    // Constructor
    Individual(T *al);
    Individual(int len);
    Individual();

    // Methods
    void zeros();
    void initRandom();
    void initRandom(T);
    void initRandom(T, T);
    void set(T *);
    void computeFit();
    float getFitness();
    void setVe(float prob);
    T getGene(int);
    void setGene(int, T);
    float getVe();
    T *get();
    void print();
};

#endif