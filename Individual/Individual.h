#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>
using namespace std;

class Individual{
    private:
        float *allele;
        int len;
        float fitness;
        float ve;
    public:
        Individual(float *al);
        Individual(int len);
        Individual();
        void setLength(int);
        int getLength();
        void initZero();
        void initRandom();
        void initGrayCode();
        void set(float *);
        void computeFit();
        float getFitness();
        void setVe(float prob);
        float getAllele(int);
        void setAllele(int,float);
        float getVe();
        float *getAle();
        void print();
};

#endif