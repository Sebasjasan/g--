/*
*@author    :Sebastian Sanchez
*@date      :09.01.2023
*@details   :Examen
*/

#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "../lib/jsColores.h"

using namespace std;

void jsAutenticacion()
{
    char jsUsuario[30];
    char jsClave[15];
    int nIntentos = 0;
    int ingresa = 0;

    do
    {

        cout << COLOR_RED << "\t----------WELCOME----------";
        cout << COLOR_BLUE;
        cout << "\nUSUARIO: ";
        gets(jsUsuario);
        cout << "\nCLAVE: ";
        gets(jsClave);

        if (strcmp(jsUsuario, "jaime.sanchez02@epn.edu.ec") == 0 && strcmp(jsClave, "123456") == 0)
        {
            ingresa = 1;
        }
        else
        {
            cout << "\nUSUARIO O CLAVE INCORRECTOS\n";
            fflush(stdin);
            nIntentos++;
            getchar();
        }
        system("cls");

    } while (nIntentos < 3 && ingresa == 0);

    if (ingresa == 1)
    {
        cout << COLOR_RED << "\nBIENVENIDO:" << jsUsuario;
    }
    else
    {
        cout << "\nLo sentimos tu usuario y clave son incorrectos";
        cout << "\nGRACIAS\n";
        system("pause");
        system("cls");
    }
}

void jsMenu(int jsOpciones, int jsBar1 = 177)
{
    char jsNombre[40] = "Jaime Sebastian Sanchez Gordon";
    cout << COLOR_BLUE;
    cout << "\n1. Mostrar Usuario\n";
    cout << "2. Barra de carga\n";
    cout << "3. Combinatoria\n";
    cout << "0. Salir\n";
    cout << "Opciones: ";
    cin >> jsOpciones;
    cout << "\n";

    system("cls");

    switch (jsOpciones)
    {
    case 0:
        break;
    case 1:
        cout << COLOR_GREEN;
        cout << "CEDULA: 1752364123\n";
        cout << "CORREO: JAIME.SANCHEZ02@EPN.EDU.EC\n";
        cout << "NOMBRE: jaime sebastian sanchez gordon";
        break;

    case 2:

        cout << COLOR_ROSE;
        cout << "\n\n\n\t\tLoading....";
        cout << "\n\n\n\t";

        for (int i = 0; i < 25; i++)
            cout << (char)jsBar1;

        for (int i = 0; i <= 100; i++)
        {

            cout << "\r";
            cout << i << "%"
                 << "\t";

            for (int j = 0; j < i / 4; j++)
                cout << "=";

            cout << "\r\t\t\t\t\t";
            for (int z = 0; z <= i / 3; z++)
                cout << jsNombre[z];

            Sleep(50);
        }
        break;

    case 3:
        cout << COLOR_YELLOW;
        cout << "Cadena (correo): jaime.sanchez02@epn.edu.ec\n";
        cout << "Conjunto sin repeticion: jaimesnchz02@pduc\n";
        cout << "Longitud cadena: 26\n";
        cout << "Longitud conjunto: 17\n";
        // NO PUDE UNIR LA COMBINATORIA :(
        // void combinacionSR(char *iteams, int n, int r, int x = 0, int aux = 0, int *indices = NULL)
        // {
        //     if (indices == NULL)
        //     {
        //         indices = new int[r];
        //     }
        //     if (aux < r)
        //     {
        //         for (int c1 = x; c1 < n; c1++)
        //         {
        //             indices[aux] = c1;
        //             combinacionSR(iteams, n, r, c1 + 1, aux + 1, indices);
        //         }
        //     }
        //     else
        //     {
        //         cout << "\n\t";
        //         for (int w = 0; w < r; w++)
        //         {
        //             cout << iteams[indices[w]];
        //         }
        //     }
        // }

        // void numeroCombinacionesSR(int n, int r, int nf, int rf, int nrf, int rta)
        // {

        //     for (int i = 1; i <= n; i++)
        //     {
        //         nf *= i;
        //     }

        //     for (int j = 1; j <= r; j++)
        //     {
        //         rf *= j;
        //     }

        //     for (int k = 1; k <= n - r; k++)
        //     {
        //         nrf *= k;
        //     }

        //     rta = (nf) / (rf * nrf);

        //     cout << "\nLas combinaciones sin repeticion son: " << rta << endl;
        // }
        break;

    case 4:
        break;
    }
}

int main()
{
    int jsOpciones;
    char jsNombre[40] = "Jaime Sebastian Sanchez Gordon";

    jsAutenticacion();
    jsMenu(jsOpciones);

    cout << "\n";
    system("pause");
    return 0;
}