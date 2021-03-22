#include "Mutation.h"

Mutation::Mutation(float per){
    percent = per;
    srand(time(NULL));
}

void Mutation::mutBin(Population* pop){
    int num = (int) percent * (pop->getSize());
    int si = pop->getSize() - 1;
    int ln = pop->getLen();
    
    for(int i = 0; i < num; i++){
        int index = (int)rand()%(si);
        Individual p = pop->getIndividual(index);
        
        int in = (int) rand() % (ln-1);
        int al = p.getAllele(in);
        
        al = al == 0 ? 1 : 0;

        p.setAllele(in, al);

        pop->setIndividual(in, p);

    }
}