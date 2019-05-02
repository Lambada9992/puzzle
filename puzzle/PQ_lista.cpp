#include <iostream>
#include <PQ_lista.h>

using namespace std;

////////////STRUKTURA////////
lista::lista(astar *elem,int N){
    next=nullptr;
    down=nullptr;
    key=N;
    element=elem;



}

///////////////|PQ\/////////////
PQ_lista::PQ_lista(){
    H=nullptr;
}


void PQ_lista::insert(astar *x,int N){
    if(H==nullptr){
        H=new lista(x,N);
  }
    else{

        lista *new_node=new lista(x,N);
        if(H->key>N){
            new_node->down=H;
            H=new_node;
        }else{if(H->key==N){
                new_node->next=H;
                new_node->down=H->down;
                H->down=nullptr;
                H=new_node;
            }
        else{
            lista *pom=H;
            while(pom!=nullptr){

                if(pom->down==nullptr){
                    pom->down=new_node;

                    break;
                }

                if(pom->down->key==N){

                  new_node->next=pom->down;
                  new_node->down=pom->down->down;
                  pom->down->down=nullptr;
                  pom->down=new_node;
                  break;}

                if(pom->down->key>N){

                 new_node->down=pom->down;
                 pom->down=new_node;
                 break;
                }

              pom=pom->down;
            }

            }
        }
    }


}
astar *PQ_lista::extract_min(){


    if(H==nullptr)return nullptr;
    lista*pom=H;

    if(H->next!=nullptr){
        H->next->down=H->down;
        H=H->next;
        pom->next=nullptr;
        pom->down=nullptr;
        astar *pom2=pom->element;
        delete pom;
        return pom2;
    }
    else{
        H=H->down;
        astar *pom2=pom->element;
        pom->next=nullptr;
        pom->down=nullptr;
        delete pom;
        return pom2;
    }


}
astar *PQ_lista::min(){
    if(H==nullptr){return nullptr;}else
   {
        return H->element;
   }
}
void PQ_lista::usun(){
    if(H!=NULL){
        lista *pom=H;
        while(H!=NULL){
            pom=H;
            H=H->down;
            usun_next(pom);

        }
    }
}
void PQ_lista::usun_next(lista *&X){
    lista *pom;
    while (X!=NULL){
        pom =X;

        X=X->next;
        delete pom;
    }
}
