#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

int main(){
    string usuario1 = "Sebas123";
    string usuario2;
    string contrasena1 = "12345";
    string contrasena2;
    
    for (int i = 0; i < 3; i++)
    {
        cout << "----BIENVENIDO----" << endl;
        cout << "Usuario: ";
        cin >> usuario2;
        cout << "Contrasena: ";
        cin >> contrasena2;
        system ("cls");
        if ((usuario1==usuario2) && (contrasena1==contrasena2))
        cout << "\nBienvenido\n";
        break;
        
    }
        if ((usuario1!=usuario2) || (contrasena1!=contrasena2))
        cout << "\nEl usuario o contrasena esta incorrecto\n";

    return 0;
}

// void jsAutenticacion()
// {
// 	char jsUsuario[25];
// 	char jsClave[11];
//     char jsProfe[25];
// 	char jsProfeClave[11];
// 	int nIntentos = 0;
// 	int ingresa = 0;

// 	do
// 	{
// 		cout << "\t----------WELCOME----------";
// 		cout << "\nUSUARIO: ";gets(jsUsuario);
// 		cout << "\nCLAVE: ";gets(jsClave);

// 		if ((strcmp(jsUsuario,"sebas")==0 || strcmp(jsProfe,"profe")==0 ) && (strcmp(jsClave, "456")==0)
//         || strcmp(jsProfeClave, "123")==0)
// 		{
// 			ingresa = 1;
// 		}
// 		else
// 		{
// 			cout << "\nUSUARIO O CLAVE INCORRECTOS\n";
// 			fflush(stdin);
// 			nIntentos++;
// 			getchar();
// 		}
//         system ("cls");

// 	} while (nIntentos < 3 && ingresa == 0);

// 	if (ingresa == 1)
// 	{
// 		printf("\nBIENVENIDO %s",jsUsuario);
// 	}
// 	else
// 	{
// 		cout << "\nLo sentimos tu usuario y clave son incorrectos";
// 		cout << "\nGRACIAS\n";
// 		system("pause");	
// 		system("cls");
// 	}
// }

// int main ()
// {
// 	jsAutenticacion();
// }