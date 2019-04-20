#ifndef PUZZLE_GAME_H
#define PUZZLE_GAME_H

#include <iostream>

using namespace std;

class gra{
    int size;
    int **tab;
    int **goal;
    int x;
    int y;
    //dzialanie//
    void wczytaj_tab();
    void rand_tab();
    void where_is_blank();
    bool solvable();
    bool compare_tab(int **,int **);

    void left_tab();
    void right_tab();
    void up_tab();
    void down_tab();
public:
    gra();
    ~gra();
    //wyswietlanie//
    void print_tab();
    void print_menu();
    void play_game();


};


#endif // PUZZLE_GAME_H
