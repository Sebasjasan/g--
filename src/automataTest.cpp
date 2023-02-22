#include <iostream>
using namespace std;

int const TKErr=-1;
int const TKOK=-2;
string const ALFA = "ab \\t";

int **matrizNew(int f, int c)
    {
        int **m=NULL;
        m = new int*[f];
        for (int i = 0; i < f; i++)
            m[i] = new int[c];
 
        return m;
    }
void showMatriz(int **pd, int f,int c)
{
    for (int i = 0; i < f; i++)
    {
            for (int j = 0; j < c; j++)
                cout<< pd[i][j] <<"\t";   
            cout<< endl;
    }
}

int getIndexAlfabeto(char c)
{
    int index = ALFA.find(c);
    if (index < ALFA.length())
        return index;
    return TKErr;
}

int main ()
{
    int **mt = NULL;
    int Q=3, L=3;
    mt = matrizNew(Q,L);

    mt[0][0]=1;         mt[0][1]=2;         mt[0][2]=TKErr;   
    mt[1][0]=1;         mt[1][1]=2;         mt[1][2]=TKErr;   
    mt[2][0]=TKErr;     mt[2][1]=TKErr;     mt[2][2]=-1000;   
    
    string w = "aaaabc ";
    int q=0, l=0;
    cout << "palabra w = " << w << endl;
    for (auto &&c : w)
    {
        l = getIndexAlfabeto(c);
        q = mt[q][l];
        //cout << c << " " << q << "," << l << endl;
        if (q == TKErr || q > Q)
            cout << " --> Error";
        if (q == -1000)
            cout << "\t --> OK";
    }
    cout << endl;
}