#include <iostream>
using namespace std;
 
    int **crearMatrizMalloc(int f, int c){
        int **m=NULL;
        m = (int **) malloc(f*sizeof(int *)); // int ** guarda referencia
        for (int i = 0; i < f; i++)
            m[i] = (int *) malloc(c*sizeof(int));
        
        return m;
    }
    int **crearMatrizCalloc(int f, int c)
    {
        int **m=NULL;
        m = (int **) calloc(f, sizeof(int *));
        for (int i = 0; i < f; i++)
            m[i] = (int *) calloc(c, sizeof(int));
        
        return m;
    }
    int **crearMatrizNew(int f, int c)
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
 
    int main()
    {
        int f = 0, c = 0;
        int **pd=NULL;
 
        cout<<"Ingresa fila y columnas de la matriz : ";
        cin>> f >> c;
    
        pd = crearMatrizNew(f,c);
 
        for (int i = 0; i < f; i++)
            for (int j = 0; j < c; j++)
                pd[i][j] = rand() % 10;  // genera randomicos hasta 10
        
        showMatriz(pd,f,c);
        return 0;
    }