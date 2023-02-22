#include <iostream>
using namespace std;

// void matrizImpar(int tf, int tc){
//     int matriz [tf][tc];
//     //encerar
//     // for (int f = 0; f < tf; f++)
//     //     for (int c = 0; c < tc; c++)
//     //         matriz [tf][tc] = 0;
    

//     for (int f = 0; f < tf; f++)
//         for (int c = 0; c < tc; c++)
//             if (f==0)
//                 matriz [f][c] = c*2;
//             else if (f==1)
//                 matriz [f][c] = c*2+1;
//             else
//             matriz [f][c] = 0;


//     //presentar
//     for (int f = 0; f < tf; f++)
//     {
//         for (int c = 0; c < tc; c++)
//             cout << matriz [f][c] << " ";
//         cout << endl;
//     }
        
// }

// int main(){
//     int fila, columna;
//     cout << "Ingresa el nro de filas: ";
//     cin >> fila;
//     cout << "Ingresa el nro de columnas: ";
//     cin >> columna;
//     matrizImpar(fila, columna);
// }




 
void MatrizCaracteresG(int fila, int columna){
     char matriz[fila][columna];
 
    for(int f= 0; f < fila; f++){
        for( int c=0; c < columna; c++){
            matriz[f][c]='+';
        }
    }
    for(int f= 0; f < fila; f++){
        for( int c=0; c < columna; c++){
            cout<<matriz[f][c]<<" ";
        }
        cout<<endl;
    }
}
void showMatriz(char matriz[][2],int fila, int columna){
 
 for(int f= 0; f < fila; f++){
        for( int c=0; c < columna; c++){
            cout<<matriz[f][c]<<" ";
        }
        cout<<endl;
    }
}
void MatrizCaracteres(){
    int fila = 3;
    int columna = 2;
    char matriz[3][2]={  {'a' , 'b'}
                        ,{'c' , 'd'}
                        ,{'e' , 'f'}};
    showMatriz(matriz,fila,columna);
}
int main(void){
    MatrizCaracteres();
    //MatrizCaracteresG(5,2);
    return 0;
}


