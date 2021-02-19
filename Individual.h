#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include <iostream>
using namespace std;

class Individual{
    private:
        int *allele;
        int len;
        float fitness;
        float ve;
    public:
        Individual(int *al);
        Individual(int len);
        Individual();
        void setLength(int);
        int getLength();
        void initZero();
        void initRandom();
        void initGrayCode();
        void set(int *);
        void computeFit();
        float getFitness();
        void setVe(float prob);
        int getAllele(int);
        void setAllele(int,int);
        float getVe();
        int *getAle();
        void print();
};

#endif