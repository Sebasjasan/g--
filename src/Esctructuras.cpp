#include <iostream>
using namespace std;
struct Mascota{
    string nameMascota;
    int edadMascota;
};
struct Alumnos{
    string nombre;
    int edad;
    Mascota m;
};
int main(){
    Alumnos a1 = {"Sebas", 19, {"Negro", 4}};
    Alumnos a2 = {"Sophia", 4, {"Blanca", 3}};
    Alumnos lst[] = {a1, a2};
    cout << "[+] Datos de alumno" << endl
         << "- Nombre: " << a1.nombre  << endl
         << "- Edad: "   << a1.edad    << endl
         << "- Nombre de la mascota: " << a1.m.nameMascota   << endl
         << "- Edad de la mascota: "   << a1.m.edadMascota     << endl
         << endl;
    // for ( auto && a : lst)   // For inteligente 
    // {
    //     cout << endl << "[+] Datos de alumno" << endl
    //      << "- Nombre: " << a.nombre  << endl
    //      << "- Edad: "   << a.edad    << endl
    //      << "- Nombre de la mascota: " << a.m.nameMascota   << endl
    //      << "- Edad de la mascota: "   << a.m.edadMascota     << endl
    //      << endl;
    // }
    return 0;
}