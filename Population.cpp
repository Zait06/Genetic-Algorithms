#include "Population.h"
#include <algorithm>

Population::Population(int s){
    pop = new Individual[s];
    size = s;
    sum = 0;
    prob = 0;
}

void Population::initPop(int l, int op){
    length = l;
    option = op;
    for(int i=0; i<size; i++){
        pop[i].setLength(l);
        switch (op){
            case 0:
                pop[i].initZero();
            break;
            
            case 1:
                pop[i].initRandom();
            break;
        }
        pop[i].computeFit();
    }
    computeSumProb();
}

int Population::getSize(){
    return size;
}

Individual Population::getIndividual(int index){
    return pop[index];
}

void Population::setIndividual(int index, int *ale){
    pop[index].set(ale);
}

void Population::setIndividual(int index, Individual ind){
    pop[index] = ind;
}

void Population::computeSumProb(){
    sum = 0;
    prob = 0;
    for(int i=0; i<size; i++)
        sum += pop[i].getFitness();

    prob = sum / size;

    for(int i=0; i<size; i++)
        pop[i].setVe(prob);
}

int Population::getLen(){
    return length;
}

float Population::getMax(){
    float max = 0;
    for(int i=0; i<size; i++){
        float aux = pop[i].getFitness();
        if(max < aux)
            max = aux;
    }
    return max;
}

float Population::getMin(){
    float min = pop[0].getFitness();
    for(int i=0; i<size; i++){
        float aux = pop[i].getFitness();
        if(min > aux)
            min = aux;
    }
    return min;
}

void Population::print(){
    for(int i=0; i<size; i++){
        pop[i].print();
    }
}


Population insertsortPop(Population p, int l, int o){
    int s = p.getSize();
    int j = 0;
    for(int i = 0; i < s; i++){
        j = i - 1;
        while(j >= 0 && p.getIndividual(j).getFitness() < p.getIndividual(j+1).getFitness()){
            Individual aux = p.getIndividual(j);
            p.setIndividual(j,p.getIndividual(j+1));
            p.setIndividual(j+1,aux);
            j--;
        }
    }

    Population b = Population(s/2);
    b.initPop(l, o);

    for(int i = 0; i < s/2; i++)
        b.setIndividual(i, p.getIndividual(i));

    return b;
}

Population Population::join(Population p){
    Population jp = Population(size*2);
    jp.initPop(length, option);

    for(int i = 0; i < size; i++)
        jp.setIndividual(i,pop[i]);

    for(int i = size, j = 0; i < 2*size; i++, j++)
        jp.setIndividual(i,p.getIndividual(j));

    return insertsortPop(jp, length, option);

}