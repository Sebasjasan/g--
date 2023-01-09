#include <iostream>

using namespace std;

int main ()
{   
    int n1,n2;
    
    cout <<"Ingresa primer numero: ";
    cin >> n1;

    cout <<"Ingresa segundo numero: ";
    cin >> n2;

    if(n1>n2)
        cout <<"El mayor es el primer numero";
    if(n2>n1)
        cout <<"El mayor es el segundo numero";
    if(n1==n2)
        cout <<"Son iguales";

    return 0;
}
