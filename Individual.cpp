#include "Individual.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cmath>

Individual::Individual(int len){
    allele = new int[len];
    this->len = len;
    srand(time(NULL));
}

Individual::Individual(int *ale){
    int i = 0;
    allele = ale;
    while(true){
        if(ale[i] == '\0')
            break;
    }
    len = i;
    computeFit();
}

Individual::Individual(){
    srand(time(NULL));
}

void Individual::setLength(int l){
    len = l;
    allele = new int[l];
}

int Individual::getLength(){
    return len;
}

void Individual::initRandom(){
    for(int i=0; i<len; i++)
        allele[i] = rand() % 2;
}

void Individual::computeFit(){
    fitness = 0.0;
    for(int i=len-1, j=0; i>=0; i--,j++)
        fitness += (float) pow(allele[i]*2,j);
}

void Individual::initGrayCode(){
    cout<<"A ver que pasa"<<endl;
}

void Individual::initZero(){
    for(int i=0; i<len; i++)
        allele[i] = 0;
}

void Individual::set(int *s){
    allele = s;
    computeFit();
}

float Individual::getFitness(){
    return fitness;
}

void Individual::setVe(float prob){
    ve = fitness / prob;
}

float Individual::getVe(){
    return ve;
}

int* Individual::getAle(){
    return allele;
}

void Individual::setAllele(int i, int a){
    allele[i] = a;
}

int Individual::getAllele(int i){
    return allele[i];
}

void Individual::print(){
    for(int i=0; i<len; i++){
        cout<<allele[i];
    }
    printf("\t%4.2f\t%2.2f\n",fitness,ve);
}