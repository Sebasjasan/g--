#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <dos.h>
#include <cstring>

using namespace std;

int main(){
    system("cls");
    printf("\e[?251");

    int jsBar1=177;
    char jsNombre [40]="Jaime Sebastian Sanchez Gordon"; 

     cout<<"\n\n\n\t\tLLoading....";
            cout<<"\n\n\n\t";

        for (int i = 0; i < 25; i++)
            cout << (char)jsBar1;  
    

        for (int i = 0; i <= 100; i++){
        
            cout << "\r";
            cout << i<< "%" << "\t";    

        for (int j = 0; j < i/4; j++)
            cout <<"=";
        
            cout << "\r\t\t\t\t\t";
        for (int z = 0; z <= i/3; z++)
            cout <<jsNombre[z];
            Sleep (50);

        }
   
    cout << endl;
    system ("pause");
    return 0;
}
