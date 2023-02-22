#include <iostream>
using namespace std;

int const TKErr=-1;
int const TKFin1=-2;
int const TKFin2=-3;
string const ALFA [] = {"25","50","s","\\t"};

int **matrizNew(int f, int c)
    {
        int **m=NULL;
        m = new int*[f];
        for (int i = 0; i < f; i++)
            m[i] = new int[c];
        return m;
    }
void showMatriz(int **pd, int f,int c)
{
    for (int i = 0; i < f; i++)
    {
            for (int j = 0; j < c; j++)
                cout<< pd[i][j] <<"\t";   
            cout<< endl;
    }
}

int getIndexAlfabeto(string str)
{
    for (int i = 0; i < sizeof(ALFA) / sizeof(ALFA[0]); i++)
        if (ALFA[i] == str)
            return i;
    return TKErr;
}

int main ( void)
{
    int **mt = NULL;
    int Q=5, L=3;
    mt = matrizNew(Q,L);

    mt[0][0]=1;         mt[0][1]=2;         mt[0][2]=TKErr;   
    mt[1][0]=2;         mt[1][1]=3;         mt[1][2]=TKErr;   
    mt[2][0]=3;         mt[2][1]=4;         mt[2][2]=TKFin1;   
    mt[3][0]=4;         mt[3][1]=TKErr;     mt[3][2]=TKErr;   
    mt[4][0]=TKErr;     mt[4][1]=TKErr;     mt[4][2]=TKFin2;   
   
    int q=0, l=0;
    string moneda;
    cout << "-------MAQUINA DISPENSADORA-------" << endl;
    cout << "Ingrese solo monedas de 25 y 50 cent" << endl;
    cout << "Gaseosa $1" << endl;
    cout << "Papas 50 cent" << endl;
    do
    {
        cout << "(s para salir) >> Ingresa las monedas: ";
        cin >> moneda;
        l = getIndexAlfabeto(moneda);
        q = mt[q][l];

        if (q == TKErr || q > Q){
            cout << ">> Error, devolviendo tu dinero" << endl;
            exit (0);
        }
        if (q == TKFin1){
            cout << ">> Ok, cobrando tu papa" << endl;
            exit (0);
        }
        if (q == TKFin2){
            cout << ">> Ok, cobrando tu gaseosa" << endl;
            exit (0);
        }
    } while (true);
}