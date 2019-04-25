#ifndef PQ_LISTA_H
#define PQ_LISTA_H

#include <iostream>
#include <puzzle_solver.h>

using namespace std;

class lista{
    int key;
    astar* element;
    lista* next;
    lista* down;

    lista(astar *,int N);
    ~lista();
    friend class PQ_lista;
};
class PQ_lista{
lista *H;
public:
    PQ_lista();
    ~PQ_lista();


    void insert(astar*,int);
    astar *extract_min();
    astar *min();

};





#endif // PQ_LISTA_H
