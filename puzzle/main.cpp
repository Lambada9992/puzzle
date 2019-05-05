#include <iostream>
#include "puzzle_game.h"
#include <ctime>
#include <cstdlib>

using namespace std;

void print_menu(){

        cout<<"w - Ruch do gory"<<endl;
        cout<<"s - Ruch do dolu"<<endl;
        cout<<"a - Ruch w lewo"<<endl;
        cout<<"d - Ruch w prawo"<<endl;
        cout<<"p - Podpowiedz"<<endl;
        cout<<"r - Randomize"<<endl;
        cout<<"y - Zapisz rozwiazanie do pliku o podanej nazwie"<<endl;
        cout<<"u - Wczytaj ponowinie gre"<<endl;
        cout<<"k - Zakoncz gre"<<endl;

}

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
    for(int i=0;i<N;i++){
        delete []tablica[i];
    }
    delete []tablica;


    while (pom!='k'){
        system("cls");
        cout<<"Czas wykonywania: "<<czas<<" ms\n";
        w.print_tab();
        if(!w.is){cout<<"Wczytaj ponownie gre!!!!!!"<<endl<<endl;}
        print_menu();

        cin>>pom;clock_t start = clock();
        if(pom=='a'){w.left_tab();}
        if(pom=='d'){w.right_tab();}
        if(pom=='w'){w.up_tab();}
        if(pom=='s'){w.down_tab();}
        if(pom=='r'){w.rand_tab();}
        if(pom=='p'){
            w.hint_tab();

        }
        if(pom=='y'){if(w.is){
            system("cls");
            cout<<"podaj nazwe pliku(zakonczona *.txt) :";
            cin>> nazwa;
            w.save_solution(nazwa);}
        }
        if(pom=='u'){
            system("cls");
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
            for(int i=0;i<N;i++){
                delete []tablica[i];
            }
            delete []tablica;

        }
        if(pom=='k'){break;}
        czas = clock() - start;

    }



    return 0;
}

