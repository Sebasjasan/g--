#include <iostream>
using namespace std;
 
struct nodo {    //Estructura nodo
    int nro;
    nodo *sgte;
};

struct cola {
    nodo *delante;
    nodo *atras  ;
};

// int main(){
// cola q;
//     q.delante = NULL;
//     q.atras   = NULL;
//     int valor;
// }

void encolar(cola &q, int valor )
{
     nodo *aux = new(nodo);
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;   // encola el primero elemento
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;        // puntero que siempre apunta al ultimo elemento
     cout <<" << encolado >> " <<endl;
}

void muestraCola(cola q )
{
    nodo *aux;
    aux = q.delante;

    cout << "<<  \t";
    while( aux != NULL )
    {
        cout << aux->nro <<"\t";    //aux[]->
        aux = aux->sgte;            //[1]->[5]->[]->[]->[]->[]->[]->NULL
    }  
    cout << " << "<<endl;
}

int main()
{
    cola q;
    q.delante = NULL;
    q.atras   = NULL;
    int valor;  // numero a encolar 
   
    do
    {
        cout<<"\n\n\n\t  FUNCIONALIDAD COLA : \t";
        if(q.delante==NULL)
            cout<<" <<    vacia    << ";
        else   
            muestraCola( q );
        cout<< "\n NUMERO A ENCOLAR: "; cin>> valor;
                    encolar( q, valor );  //q.encolar(1);
        
    }while(true);
    return 0;
}