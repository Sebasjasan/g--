#include <iostream>
#include <windows.h>
#include <conio.h>

#define ARRIBA  72
#define IZQUIERDA  75
#define DERECHA  77
#define ABAJO  80

using namespace std; 

void gotoxy(int x, int y){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X=x;
    dwPos.Y=y;

    SetConsoleCursorPosition(hCon, dwPos);

}

void OcualtarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    _CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}
void pintar_limites(){
    for (int i = 2; i < 78; i++ ){
        gotoxy(i, 3); cout << (char)205;
        gotoxy(i, 33); cout << (char)205;

    }

    for (int i = 4; i < 33; i++ ){
        gotoxy(2, i); cout << (char)186;
        gotoxy(77, i); cout << (char)186;

    }
    gotoxy(2, 3); cout << (char)201;
    gotoxy(2, 33); cout << (char)200;
    gotoxy(77, 3); cout << (char)187;
    gotoxy(77, 33); cout << (char)188;
    

}

class NAVE{
    int x, y;
    int corazones;
public:
    NAVE(int _x, int _y, int _corazones): x(_x), y(_y), corazones(_corazones){}
    void pintar(); 
    void borrar(); 
    void mover (); 
    void pintar_corazones();
};

void NAVE::pintar(){
    gotoxy(x, y); cout << "  "<<(char)30;
    gotoxy(x, y+1); cout << " " <<(char)40 << (char)207 << (char)41;
    gotoxy(x, y+2); cout << (char)30 << (char)190 << " " << (char)190 << (char)30;
}
void NAVE :: borrar (){
    gotoxy(x, y); cout << "     ";
    gotoxy(x, y+1); cout << "     ";
    gotoxy(x, y+2); cout << "     ";

}

void NAVE::mover(){
    if(kbhit()){
                char tecla = getch();
                borrar();
                if(tecla == IZQUIERDA && x>3) x--;
                if(tecla == DERECHA && x<72) x++;
                if(tecla == ARRIBA && y > 4) y--;
                if(tecla == ABAJO && y< 30) y++;
                pintar ();
                pintar_corazones();
                
        }

}
void NAVE::pintar_corazones(){
    gotoxy(64,2); cout << "SALUD";
    gotoxy(70,2); cout << "       ";
    for (int i = 0; i < corazones; i++){
        gotoxy(70+i,2); cout << (char)3;
    }
    


}

int main(){

    // char username [20];

    // cout << "********" << endl;
    // cout << "*********" << endl;
    // cout << "***   ***" << endl;
    // cout << "***   ***" << endl;
    // cout << "*********" << endl;
    // cout << "*******" << endl;
    // cout << "***" << endl;
    // cout << "***" << endl;

    // cout << "Nombre del jugador; ";
    // cin >> username;
    system("cls");


    cout<< "\n";
    OcualtarCursor();
    NAVE N (7,7,3);
    N.pintar();
    N.pintar_corazones();

    pintar_limites();


    bool game_over = false;
    while(!game_over){
        
        N.mover();
        Sleep(10);
    }


    return 0;
}