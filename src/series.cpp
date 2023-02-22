#include <iostream>
#include <windows.h>
#include <string.h>

using namespace std;

int datos(){
    cout << "Sebastian Sanchez" << endl
         << "1752364123"        << endl;
    return 0;
}

int serie00(int nro){
    cout << "Ingrese el numero de signos para la serie: ";
    cin >> nro;
    for (int i = 1; i <= nro; i++)
    {
        cout << ((i%2==0)?"-":"+") << " ";
    }
    return 0;
}

int serie02(){
    int nro;
    cout << "Ingrese el numero de terminos para la serie: ";
    cin >> nro;

    for (int i = 1; i <= nro; i++)
    {
        cout << "+";
    }
    

    return 0;
}

int sanchezSerie04(int nro, int a=0, int b=1, int c=0, int sumaDos = 2){
    cout << "Ingrese el numero de terminos para la serie: ";
    cin >> nro;
    for (int i = 1; i <= nro; i++){
        cout << c << "/" << sumaDos << "  ";
        a=b;
        b=c;
        c=a+b;
        sumaDos +=2;
    }
    cout << endl;
    return 0;
}

int serie06(){
    int nro;
    cout << "Ingrese el numero de terminos para la serie: ";
    cin >> nro;
    for (int i = 1; i <= nro; i++)
        {
        for (int r = 1; r <= i; r++)
            cout << "+"; 
            i++;
            i-=1;
        cout << " ";
        }
    return 0;
}

int sanchezSerie14(int nro){
    cout << "Ingrese el numero de niveles: ";
    cin >> nro;
    cout << endl;
    for (int i = 1; i <= nro; i++)
        {
        for (int r = 1; r <= nro - i; r++)
            cout << " ";
        for (int r = 1; r <= 2*i-1; r++)
            cout << "*";
        cout << "\n";
        }
    cout << endl;
    return 0;
}

int serie15(int nro){
    cout << "Ingrese el numero de niveles: ";
    cin >> nro;
    cout << endl;
    for (int i = nro; i > 0; i--)
    {
        for (int r = 1; r <= nro-i; r++)
            cout << " ";
        for (int r = 1; r <= i*2-1; r++)
            cout << "*";
        cout << "\n";
    }
    cout << endl;
    return 0;
}

int serie17(int filas, int columnas){
    char matriz [filas][columnas];
    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            if ((f+c+1)==filas)
            {
                matriz[f][c]='+';
            }
            
        }
        cout << endl;
    }

    for (int f = 0; f < filas; f++)
    {
        for (int c = 0; c < columnas; c++)
        {
            cout << matriz[f][c] << " ";
        }
        cout << endl;
    }
    
    return 0;
}

int sanchezSerie24(){
    string frase;
    char letra;
    //char vocal [5] = {'a','e','i','o','u'};
    int tam;
    cout << "Ingrese una frase: ";
    getline (cin,frase);
    //do {
        cout << "\nIngrese una letra: ";
        cin >> letra;
        cout << endl;
    //}while ((letra != 'a') && (letra != 'e') && (letra != 'i') && (letra != 'o') && (letra != 'u'));
    tam=frase.length();
    for (int i = 0; i <= tam; i++)
    {
        if (frase[i]==letra)
            frase[i]=' ';
        cout << frase[i];
    Sleep(200);
    } 
    return 0;
}

int serie25(){
    char frase [50];
    char letra;
    int tam;
    cout << "Ingrese una frase: ";
    gets (frase);
    strrev(frase);
    cout << "\nLa frase invertida es: " << frase;
    return 0;
}

int main(){
    int nroSignos, nroTerminos, nroNiveles;
    datos();
//serie00(nroTerminos);
    //serie01(nroTerminos);
    //serie02();
    //serie03(nroTerminos);
//sanchezSerie04(nroTerminos);
    //serie05(nroTerminos);
    //serie06();
    //serie07(nroTerminos);
    //serie08(nroTerminos);
    //serie09(nroTerminos);
    //serie10(nroTerminos);
    //serie11(nroTerminos);
    //serie12(nroTerminos);
    //serie13(nroTerminos);
//sanchezSerie14(nroNiveles);
//serie15(nroNiveles);
    //serie16(nroNiveles);
    serie17(5,5);
    //serie18(nroNiveles);
    //serie19(nroNiveles);
    //serie20(nroNiveles);
    //serie21(nroNiveles);
    //serie22(nroNiveles);
    //serie23(nroNiveles);
//sanchezSerie24();
//serie25();
    //serie26(nroNiveles);
    //serie27(nroNiveles);
    //serie28(nroNiveles);
    //serie29(nroNiveles);
    //serie30(nroNiveles);
    //serie31(nroNiveles);
    //serie32(nroNiveles);
}