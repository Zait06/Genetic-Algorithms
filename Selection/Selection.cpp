#include "Selection.h"
#include <stdlib.h>
#include <time.h>

template <typename T>
Selection<T>::Selection(){
    srand(time(NULL));
}

template <typename T>
Population<T> Selection<T>::roulette(Population<T> pop){
    int sz = pop.getSize();
    Population p(sz);
    float sumve = 0.0;

    p.initPop(pop.getLen(),0);

    for(int i = 0; i < sz; i++){
        float r = (float) (rand()%(((int) sz*100)+1)) / 100;
        sumve = 0;

        for(int j = 0; j < sz; j++){
            sumve += pop.getIndividual(j).getVe();
            if(sumve > r){
                p.setIndividual(i,pop.getIndividual(j));
                break;
            }
        }
    }

    // p.computeSumProb();

    return p;
}

template <typename T>
Population<T> Selection<T>::tournament(Population<T> pop){
    int sz = pop.getSize();
    Population p(sz);

    p.initPop(pop.getLen(), 0);

    for(int i = 0; i < sz; i++){
        int p1 = rand() % sz;
        int p2;

        while(true){
            p2 = rand() % sz;
            if(p2 != p1) break;
        }

        float r1 = pop.getIndividual(p1).getFitness();
        float r2 = pop.getIndividual(p2).getFitness();

        int index = r1 > r2 ? p1 : p2;

        p.setIndividual(i,pop.getIndividual(index));
    }

    return p;
}