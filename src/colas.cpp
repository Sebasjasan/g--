#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
struct nodo{             //  [ # ]>-->
    int nro;
    struct nodo *sgte;
};
struct cola{             //  <--< >-->
    nodo *delante;
    nodo *atras;
};
void encolar(struct cola &q, int valor)
{
    struct nodo *aux = new (struct nodo);
    aux->nro = valor;
    aux->sgte = NULL;
    if (q.delante == NULL)
        q.delante = aux; // encola el primero elemento
    else
        (q.atras)->sgte = aux;
    q.atras = aux; // puntero que siempre apunta al ultimo elemento
}
void muestraCola(struct cola q)
{
    struct nodo *aux;
    aux = q.delante;

    while (aux != NULL)
    {
        cout << "   " << aux->nro;
        aux = aux->sgte;
    }
}

int main()
{
    struct cola q;
    q.delante = NULL;
    q.atras = NULL;
    int dato; // numero a encolar
    do
    {
        cout << "Encolar: ";
        cin >> dato;
        encolar(q, dato);
    } while (dato != 0);

    cout << "\n\n MOSTRANDO COLA\n\n";
    if (q.delante != NULL)
        muestraCola(q);
    else
        cout << "\n\n\tCola vacia...!" << endl;

    return 0;
}