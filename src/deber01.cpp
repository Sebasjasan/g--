#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int datos(){
    cout << "\nSebastian Sanchez" << endl
         << "1752364123"        << endl << endl;
    return 0;
}

int sanchezSerie24(char letra){
    string frase;
    cout << "--- SERIE 24 ---\n" << endl
         << "Ingrese una frase: "; 
    getline (cin, frase);
    cout << "Ingrese una letra: ";
    cin >> letra;
    cout << endl;
    for (int i = 0; i <= frase.length(); i++)
    {
        if (frase[i]==letra)
            frase[i]=' ';
        cout << frase[i];
    Sleep (100);
    } 
    cout << endl << endl;
    cout << "For series 14 and 04 ";
    return 0;
}

int sanchezSerie14(int nro){

    cout << "\n\n\n--- SERIE 14 ---\n" << endl;
    for (int i = 1; i <= nro; i++)
        {
        for (int r = 1; r <= nro - i; r++)
            cout << " ";
        for (int r = 1; r <= 2*i-1; r++)
            cout << "*";
        cout << "\n";
        }
    return 0;
}

int sanchezSerie04(int nro, int a=0, int b=1, int c=0, int sumaDos = 2){
        cout<< "Ingrese un numero para los terminos y niveles de las series: ";
        cin >> nro;
    
    cout << "\n--- SERIE 04 ---\n" << endl;
    for (int i = 1; i <= nro; i++)
    {
        cout << c << "/" << sumaDos << "  ";
        a=b;
        b=c;
        c=a+b;
        sumaDos +=2;
    }
    sanchezSerie14(nro);
    cout << endl
         << "To exit ";
    return 0;
}

int main(){
    
    int nroTerminos, nroNiveles;
    char letter;
    datos();
    sanchezSerie24(letter);
    system ("pause");
    system ("cls");
    sanchezSerie04(nroTerminos, nroNiveles);
    system ("pause");
    system ("cls");
    return 0;
}