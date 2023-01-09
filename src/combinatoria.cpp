#include <iostream>

using namespace std;

void combinacionSR (char *iteams, int n, int r, int x=0, int aux=0, int *indices=NULL){
    if (indices==NULL){
        indices = new int [r];
    }
    if (aux<r){
        for (int c1 = x; c1 < n; c1++){
            indices[aux]=c1;
            combinacionSR (iteams, n, r, c1+1, aux+1, indices);
        }
    }else{
        cout <<"\n\t";
            for (int w = 0; w < r; w++){
                cout << iteams[indices[w]];
            }
    }
}

void numeroCombinacionesSR (int n, int r, int nf, int rf, int nrf, int rta){
    

    for (int i = 1; i <= n; i++){
        nf *= i;
    }
    
    for (int j = 1; j <= r; j++){
        rf *= j;
        }
    
    for (int k = 1; k <= n-r; k++){
        nrf *= k;
    }    
    

    rta=(nf)/(rf*nrf);

    cout << "\nLas combinaciones sin repeticion son: "<< rta << endl;

}

int main()
{
    
    char correo [] = "jaime.sanchez02@epn.edu.ec";
    int n, r, nf=1, rf=1, nrf=1, rta;

    cout << "Cadena (correo): jaime.sanchez02@epn.edu.ec\n";
    cout << "Conjunto sin repeticion: jaimesnchz02@pduc\n";
    cout << "Longitud cadena: 26\n";
    cout << "Longitud conjunto: 17\n";

    cout <<"\n\nNumero de elementos: "; cin >> n;
    cout <<"Numero de grupo: "; cin >> r;
    
    numeroCombinacionesSR (n, r, nf, rf, nrf, rta);

    combinacionSR (correo, n, r);

    return 0;
}
