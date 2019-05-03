#include <iostream>
#include "puzzle_game.h"
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{   int N;char pom='0';int czas=0;
    string nazwa="test.txt";

    gra w;


    do{
    cout<<"podaj rozmiar GRY : ";
    cin>>N;
    system("cls");
    }
    while(N<3 or N>4);

    int **tablica;
    tablica =new int *[N];
    for(int i=0;i<N;i++){
        tablica[i]=new int[N];
    }
    cout<<"wprowadz tablice 0-puste pole :";
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
           cin>>tablica[i][j];
        }
    }

    w.wczytaj_tab(tablica,N);
    while (pom!='k'){
        system("cls");
        printf( "Czas wykonywania: %lu ms\n",czas);
        w.print_tab();
        w.print_menu();

        cin>>pom;
        if(pom=='a'){w.left_tab();}
        if(pom=='d'){w.right_tab();}
        if(pom=='w'){w.up_tab();}
        if(pom=='s'){w.down_tab();}
        if(pom=='r'){w.rand_tab();}
        if(pom=='p'){clock_t start = clock();
            w.hint_tab();
        czas = clock() - start;
        }
        if(pom=='k'){break;}
    }



    return 0;
}

