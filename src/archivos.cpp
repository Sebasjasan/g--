#include <iostream>
#include <fstream> //para archivos
using namespace std;

void leerArchivo (string pathfile){

    int parrafos=1;
    string s;
    ifstream f (pathfile);

    if (!f.is_open())
        cerr << "Error al abrir el archivo."<< endl;
    else
        do {
            getline(f,s);
            cout << s << endl;

            if (parrafos++%2==0)
            getchar();

        }while (!f.eof());
    f.close();
        


}

void escribirArchivo(string pathfile){

    ofstream f;
    
    f.open (pathfile, ios_base::out); // borra y agrega
    //f.open (pathfile, ios_base::app); // agrega sin borrar

    f<<"Humano 1\n";
    f<<"Humano 2\n";
    f<<"Humano 3\n";
    f.close();
}

int main (){
    //leerArchivo ("files\\texto1.txt");
    escribirArchivo ("files\\texto2.txt");
}