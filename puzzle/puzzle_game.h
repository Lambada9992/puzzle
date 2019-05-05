#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <iostream>
#include <puzzle_solver.h>

using namespace std;

class gra{
    int size;
    int **tab;
    int **goal;
    int x;
    int y;
    AS *W;
public:
    bool is;
private:

    //dzialanie//


    void where_is_blank();
    bool solvable();
    bool compare_tab(int **,int **);
public:
    void wczytaj_tab(int **,int);
    void rand_tab();
    void left_tab();
    void right_tab();
    void up_tab();
    void down_tab();
    void hint_tab();
    void save_solution(string);

    gra();
    ~gra();
    //wyswietlanie//
    void print_tab();




};


#endif // PUZZLE_GAME_H
