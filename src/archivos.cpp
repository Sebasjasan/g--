#include <iostream>
#include <fstream> //para archivos
using namespace std;


void LeerArchivo(string pathFile)  
{
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    else
        do 
        {
            getline( f, s );
            cout << s << endl;
            //getchar();  // Para presentar de uno en uno
        }while( !f.eof() );
    f.close();
}
void CrearArchivo(string pathFile)  
{
    string s;
    fstream f;

    cout << "Escibiendo en un archivo" << endl;
    f.open(pathFile, ios_base::out);
    //ios_base::in --> Solo lee, no agrega texto
    //ios_base::app --> Agrega texto
    //ios_base::out --> Escribe y borra el texto anterior
    if (f.is_open())
    {
        do
        {
            cout<< "(N = salir ) Ingresa un nombre: ";
            cin>>s;
            if (s!="N")
                f << s << endl;
        } while (s!="N");
    }
    f.close();
}

int main()
{
    //CrearArchivo("textfiles/ListaAlumnos.txt");
    LeerArchivo("textfiles/ListaAlumnos.txt");
    return 0;
}

// void leerArchivo (string pathfile){

//     int parrafos=1;
//     string s;
//     ifstream f (pathfile);

//     if (!f.is_open())
//         cerr << "Error al abrir el archivo."<< endl;
//     else
//         do {
//             getline(f,s);
//             cout << s << endl;

//             if (parrafos++%2==0)
//             getchar();

//         }while (!f.eof());
//     f.close();
        


// }

// void escribirArchivo(string pathfile){

//     ofstream f;
    
//     f.open (pathfile, ios_base::out); // borra y agrega
//     //f.open (pathfile, ios_base::app); // agrega sin borrar

//     f<<"Humano 1\n";
//     f<<"Humano 2\n";
//     f<<"Humano 3\n";
//     f.close();
// }

// int main (){
//     //leerArchivo ("files\\texto1.txt");
//     escribirArchivo ("files\\texto2.txt");
// }