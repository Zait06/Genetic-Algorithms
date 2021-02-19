#include "Crossover.h"
#include <stdlib.h>
#include <time.h>

Crossover::Crossover(){
    srand(time(NULL));
}

Population Crossover::onePoint(Population pop){
    int sz = pop.getSize();
    int ln = pop.getLen();
    Population p(sz);

    p.initPop(ln, 0);

    for(int i = 0; i < sz; i+=2){
        int pb00 = (int) rand()%(ln-1);
        int *al00 = new int[ln];
        int *al01 = new int[ln];

        int *a = pop.getIndividual(i).getAle();
        int *b = pop.getIndividual(i+1).getAle();
        
        for(int j = 0; j < pb00; j++){
            al00[j] = a[j];
            al01[j] = b[j];
        }

        for(int j = pb00; j < ln; j++){
            al00[j] = b[j];
            al01[j] = a[j];
        }

        p.setIndividual(i,al00);
        p.setIndividual(i+1,al01);
    }

    p.computeSumProb();

    return p;
}

Population Crossover::twoPoints(Population pop){
    int sz = pop.getSize();
    int ln = pop.getLen();
    Population p(sz);

    p.initPop(ln, 0);

    for(int i = 0; i < sz; i+=2){
        int pb00 = (int) rand()%(ln-1);
        int pb01 = (int) rand()%(ln-1);
        int aux;

        if(pb00 > pb01){
            aux = pb01;
            pb01 = pb00;
            pb00 = aux;
        }
        
        int *al00 = new int[ln];
        int *al01 = new int[ln];

        int *a = pop.getIndividual(i).getAle();
        int *b = pop.getIndividual(i+1).getAle();
        
        for(int j = 0; j < pb00; j++){
            al00[j] = a[j];
            al01[j] = b[j];
        }

        for(int j = pb00; j < pb01; j++){
            al00[j] = b[j];
            al01[j] = a[j];
        }

        for(int j = pb01; j < ln; j++){
            al00[j] = a[j];
            al01[j] = b[j];
        }

        p.setIndividual(i,al00);
        p.setIndividual(i+1,al01);
    }

    p.computeSumProb();

    return p;
}