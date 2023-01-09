#include <iostream>
#include <string>

using namespace std;

main ()
{
    float b, h, area = 0;
    
    cout << "Introduce la base del rect: ";
    cin >> b;
    

    cout << "Introduce la altura del rect: ";
    cin >> h;
    

    area=b*h;

    cout.precision(3);
    cout << "\nLa area del rect es: "<< area;
    cout << endl << endl;

//    int b, h, area = 0;
//
//    cout << "Introduce la base del rect: ", "%i";
//    cin >> b;
//    
//
//    cout << "Introduce la altura del rect: ", "%i";
//    cin >> h;
//    
//
//    area=b*h;
//
//    cout << "\nLa area del rect es: "<< area;
//    cout << endl << endl;
    
}