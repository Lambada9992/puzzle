#include <iostream>
#include <PQ_lista.h>

using namespace std;

////////////STRUKTURA////////
lista::lista(astar *elem,int N){
    next=NULL;
    down=NULL;
    key=N;
    element=elem;



}
lista::~lista(){

    delete next;
    delete down;
    element=NULL;


}
///////////////|PQ\/////////////
PQ_lista::PQ_lista(){
    H=NULL;
}

PQ_lista::~PQ_lista(){
    delete H;
}
void PQ_lista::insert(astar *x,int N){
    if(H==NULL){
        H=new lista(x,N);


    }
    else{

        lista *pom2=new lista(x,N);
        if(H->key>N){
            pom2->down=H;
            H=pom2;
        }else{if(H->key==N){
                pom2->next=H;
                pom2->down=H->down;
                H->down=NULL;
                H=pom2;
            }
        else{
            lista *pom=H;
            while(pom!=NULL){

                if(pom->down==NULL){
                    pom->down=pom2;

                    break;
                }

                if(pom->down->key==N){

                  pom2->next=pom->down;
                  pom2->down=pom->down->down;
                  pom->down->down=NULL;
                  pom->down=pom2;
                  break;}

                if(pom->down->key>N){

                 pom2->down=pom->down;
                 pom->down=pom2;
                 break;
                }

              pom=pom->down;
            }
           // pom=NULL;
            //delete pom;
            //pom2=NULL;
            //delete pom2;
        }
        }
    }


}
astar *PQ_lista::extract_min(){
    lista*pom=H;

    if(H==NULL)return NULL;
    if(H->next==NULL){
        H=H->down;
        astar *pom2=pom->element;
        pom->element=NULL;
        pom->down=NULL;
        delete pom;

        return pom2;
    }
    if(H->next!=NULL){
        H->next->down=H->down;
        H=H->next;
        pom->next=NULL;
        pom->down=NULL;
        astar *pom2=pom->element;
        pom->element=NULL;
        delete pom;
        return pom2;
    }

}
astar *PQ_lista::min(){
    if(H==NULL){return NULL;}else
    {
        return H->element;
    }
}

