#include <iostream>
#include "Individual/Individual.h"

int main(){

    srand(time(NULL));

    Individual<bool> ind(6);
    ind.initRandom();
    ind.print();

    Individual<float> ind1(6);
    ind1.initRandom(10);
    ind1.print();

    Individual<int> ind2(6);
    ind2.initRandom(10);
    ind2.print();

    return 0;

}