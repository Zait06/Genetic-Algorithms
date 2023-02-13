#include "Population.h"

template class Population<GA_INT>;
template class Population<GA_BOOL>;
template class Population<GA_FLOAT>;
template class Population<GA_DOUBLE>;


template <typename T>
Population<T>::Population(int len, int s){
    pop = Eigen::ArrayX<Individual<T>>(len);
    size = s;
    sum = 0;
    prob = 0;
}

// template <typename T>
// void Population<T>::initPop(int l, int op){
//     length = l;
//     option = op;
//     for(int i=0; i<size; i++){
//         pop[i].setLength(l);
//         switch (op){
//             case 0:
//                 pop[i].initZero();
//             break;
            
//             case 1:
//                 pop[i].initRandom();
//             break;
//         }
//         pop[i].computeFit();
//     }
//     computeSumProb();
// }

// template <typename T>
// int Population<T>::getSize(){
//     return size;
// }

// template <typename T>
// Individual<T> Population<T>::getIndividual(int index){
//     return pop[index];
// }

// template <typename T>
// void Population<T>::setIndividual(int index, T *ale){
//     pop[index].set(ale);
// }

// template <typename T>
// void Population<T>::setIndividual(int index, Individual<T> ind){
//     pop[index] = ind;
// }

// template <typename T>
// void Population<T>::computeSumProb(){
//     sum = 0;
//     prob = 0;
//     for(int i=0; i<size; i++)
//         sum += pop[i].getFitness();

//     prob = sum / size;

//     for(int i=0; i<size; i++)
//         pop[i].setVe(prob);
// }

// template <typename T>
// int Population<T>::getLen(){
//     return length;
// }

// template <typename T>
// float Population<T>::getMax(){
//     float max = 0;
//     for(int i=0; i<size; i++){
//         float aux = pop[i].getFitness();
//         if(max < aux)
//             max = aux;
//     }
//     return max;
// }

// template <typename T>
// float Population<T>::getMin(){
//     float min = pop[0].getFitness();
//     for(int i=0; i<size; i++){
//         float aux = pop[i].getFitness();
//         if(min > aux)
//             min = aux;
//     }
//     return min;
// }

// template <typename T>
// void Population<T>::print(){
//     for(int i=0; i<size; i++){
//         pop[i].print();
//     }
// }

// template <typename T>
// Population<T> insertsortPop(Population<T> p, int l, int o){
//     int s = p.getSize();
//     int j = 0;
//     for(int i = 0; i < s; i++){
//         j = i - 1;
//         while(j >= 0 && p.getIndividual(j).getFitness() < p.getIndividual(j+1).getFitness()){
//             Individual aux = p.getIndividual(j);
//             p.setIndividual(j,p.getIndividual(j+1));
//             p.setIndividual(j+1,aux);
//             j--;
//         }
//     }

//     Population b = Population(s/2);
//     b.initPop(l, o);

//     for(int i = 0; i < s/2; i++)
//         b.setIndividual(i, p.getIndividual(i));

//     return b;
// }

// template <typename T>
// Population<T> Population<T>::join(Population<T> p){
//     Population jp = Population(size*2);
//     jp.initPop(length, option);

//     for(int i = 0; i < size; i++)
//         jp.setIndividual(i,pop[i]);

//     for(int i = size, j = 0; i < 2*size; i++, j++)
//         jp.setIndividual(i,p.getIndividual(j));

//     return insertsortPop(jp, length, option);

// }