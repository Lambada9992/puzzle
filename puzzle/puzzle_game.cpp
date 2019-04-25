#include "puzzle_game.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "PQ_lista.h"

using namespace std;


gra::gra(){
    int x=5;
    while(x>4 or x<2){
        cout<<"Podaj rozmiar gry <2;4> : ";
        cin>>x;
        system("cls");
    }
    size=x;
    //size=3;
    tab= new int *[size];
    goal=new int *[size];
    for(int i=0;i<size;i++){
        tab[i]=new int [size];
        goal[i]=new int [size];
    }
    wczytaj_tab();

}

gra::~gra(){
    for(int i=0;i<size;i++){
        delete []tab[i];
        delete []goal[i];
    }
    delete []tab;
    delete []goal;
}

void gra::wczytaj_tab(){

    system("cls");
    int pom;

    cout<<"wpisz tablice ("<<size<<"x"<<size<<") - 0 to puste pole :";
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cin>>pom;
            tab[i][j]=pom;
            if(pom==0){x=i;y=j;}
        }
    }


    //goal
    pom=1;
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
               goal[i][j]=pom;
               pom++;
            }
        }
        goal[size-1][size-1]=0;
        system("cls");



}

void gra::print_tab(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            cout<<"|"<<setw(2)<<tab[i][j];
        }cout<<"|"<<endl;if(i<size-1){
            for(int k=0;k<size;k++){cout<<"---";}cout<<endl;}
    }
    cout<<endl;
}

void gra::where_is_blank(){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab[i][j]==0){x=i;y=j;}
        }
    }
}


void gra::left_tab(){

    if(y>0){
    int pom=tab[x][y];
    tab[x][y]=tab[x][y-1];
    tab[x][y-1]=pom;
    y--;
    }
}

void gra::right_tab(){

    if(y<size-1){
    int pom=tab[x][y];
    tab[x][y]=tab[x][y+1];
    tab[x][y+1]=pom;
    y++;}
}

void gra::up_tab(){

    if(x>0){
    int pom=tab[x][y];
    tab[x][y]=tab[x-1][y];
    tab[x-1][y]=pom;
    x--;}
}

void gra::down_tab(){

    if(x<size-1){
    int pom=tab[x][y];
    tab[x][y]=tab[x+1][y];
    tab[x+1][y]=pom;
    x++;}
}


bool gra::solvable(){
    int *pom=new int [size*size];
    int ilosc_zmian=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            pom[ilosc_zmian]=tab[i][j];
            ilosc_zmian++;
        }
    }
    ilosc_zmian=0;
    for (int i=0;i<(size*size)-1;i++)
                for (int j=i+1;j<size*size;j++)
                     if (pom[j] && pom[i] &&pom[i] > pom[j])ilosc_zmian++;
    delete []pom;


    if(size==3){
        if(ilosc_zmian%2==0)return true;
    else
         return false;}

    if(size==4){
        if (size & 1)
               return !(ilosc_zmian & 1);

           else     // grid is even
           {

               if (x & 1)
                   return !(ilosc_zmian & 1);
               else
                   return ilosc_zmian & 1;
           }

        }


}

void gra::rand_tab(){
    srand(time(0));
    int los;
    int ilosc_losow;
    //ilosc_losow=20+rand()%(100-20+1);
    ilosc_losow=50;
    for(int i=0;i<ilosc_losow;i++){
        los=rand()%(3-0+1);
        if(los==0){left_tab();}
        if(los==1){right_tab();}
        if(los==2){up_tab();}
        if(los==3){down_tab();}
    }
}

bool gra::compare_tab(int **tab1,int **tab2){
    bool g_state=true;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(tab1[i][j]!=tab2[i][j])g_state=false;
        }
    }return g_state;
}

void gra::print_menu(){
    cout<<"w - ruch do gory"<<endl;
    cout<<"s - ruch do dolu"<<endl;
    cout<<"a - ruch w lewo"<<endl;
    cout<<"d - ruch w prawo"<<endl;
    cout<<"p - podpowiedz"<<endl;
    cout<<"r - Randomize"<<endl;
    cout<<"k - Zakoncz gre"<<endl;
}

void gra::play_game(){
    system("cls");
    print_tab();
    AS W(tab,goal,size);
    int pom;

    if(!solvable()){cout<<endl<<"nie da sie rozwiazac";
    }else{
        int czas=0;
        cout<<endl;
        print_menu();
        char ruch;
        while(ruch!='k'){
            cin>>ruch;
            if(ruch=='w'){up_tab();}
            if(ruch=='s'){down_tab();}
            if(ruch=='a'){left_tab();}
            if(ruch=='d'){right_tab();}
            if(ruch=='p'){
clock_t start = clock();
                W.status(tab);
                pom=W.hint();
                czas = clock() - start;
                if(pom==2){up_tab();}
                if(pom==3){down_tab();}
                if(pom==0){left_tab();}
                if(pom==1){right_tab();}
                if(pom==5){cout<<"brak:"<<endl;}

            }
            if(ruch=='r'){rand_tab();}
            system("cls");
             printf( "Czas wykonywania: %lu ms\n",czas);
            print_tab();
            cout<<endl;
            print_menu();


        }

    }
}
