#include <iostream>
#include <stdlib.h>

using namespace std;
 int main ()
 {
    int opciones, ns, tamC, n1, n2;


    cout << "1. Signos algernos\n";
    cout << "2. Genrar un cuadrado\n";
    cout << "3. Mayor de dos numeros\n";
    cout << "4. Salir\n";
    cout << "Opciones: ";
    cin >> opciones;
    cout << "\n";

    switch (opciones){
        case 1:
            cout << "Ingrese el numero de signos: ";
            cin >> ns;
            for (int i=0; i<ns; i++)
                if (i%2==0)
                    cout << " + ";
                else
                    cout << " - ";
            break;
        case 2:
            cout << "Ingrese el tamano del cuadrado: ";
            cin >> tamC;
            for (int i = 0; i < tamC; i++)
            {
                for (int j = 0; j < tamC; j++)
                {
                    cout << " + ";
                }
                cout << "\n";
            }
            break;
        case 3:
            cout << "Ingrese 2 numeros \n";
            cout << "Primero numero: ";
            cin >> n1;
            cout << "Segundo numero: ";
            cin >> n2;
            if (n1>n2)
                cout << "El mayor es el primero";
            if (n1<n2)
                cout << "El mayor es el segundo";
            if (n1==n2)
                cout << "Son iguales";
            break;
        case 4:
            break;

    }
    cout << "\n";
    system("pause");
    return 0;
 }
