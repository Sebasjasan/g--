#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

using namespace std;

/**
 * It moves the cursor to the specified position
 *
 * @param x The x coordinate of the new cursor position.
 * @param y The y coordinate of the cursor's position.
 */
void gotoxy(int x, int y)
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;

    SetConsoleCursorPosition(hCon, dwPos);
}

/**
 * It gets the console handle, sets the cursor size to 2, and sets the cursor visibility to false
 */
void OcualtarCursor()
{
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    _CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon, &cci);
}

/**
 * It prints the borders of the game
 */
void pintar_limites()
{
    for (int i = 2; i < 78; i++)
    {
        gotoxy(i, 3);
        cout << (char)205;
        gotoxy(i, 33);
        cout << (char)205;
    }

    for (int i = 4; i < 33; i++)
    {
        gotoxy(2, i);
        cout << (char)186;
        gotoxy(77, i);
        cout << (char)186;
    }
    gotoxy(2, 3);
    cout << (char)201;
    gotoxy(2, 33);
    cout << (char)200;
    gotoxy(77, 3);
    cout << (char)187;
    gotoxy(77, 33);
    cout << (char)188;
}

/* NAVE is a class that has a constructor that takes four parameters, and has four public functions
that return an int, and three public functions that don't return anything */
class NAVE
{
    int x, y;
    int corazones;
    int vidas;

public:
    NAVE(int _x, int _y, int _corazones, int _vidas) : x(_x), y(_y), corazones(_corazones), vidas(_vidas) {}
    int X() { return x; }
    int Y() { return y; }
    int VID() { return vidas; }
    void COR() { corazones--; }
    void pintar();
    void borrar();
    void mover();
    void pintar_corazones();
    void morir();
};

/**
 * The function prints the spaceship on the screen
 */
void NAVE::pintar()
{
    gotoxy(x, y);
    cout << "  " << (char)30;
    gotoxy(x, y + 1);
    cout << " " << (char)40 << (char)207 << (char)41;
    gotoxy(x, y + 2);
    cout << (char)30 << (char)190 << " " << (char)190 << (char)30;
}

/**
 * The function borrar() is used to delete the spaceship from the screen
 */
void NAVE ::borrar()
{
    gotoxy(x, y);
    cout << "     ";
    gotoxy(x, y + 1);
    cout << "     ";
    gotoxy(x, y + 2);
    cout << "     ";
}

/**
 * It moves the ship left, right, up, or down, depending on the key pressed
 */
void NAVE::mover()
{
    if (kbhit())
    {
        char tecla = getch();
        borrar();
        if (tecla == IZQUIERDA && x > 3)
            x--;
        if (tecla == DERECHA && x < 72)
            x++;
        if (tecla == ARRIBA && y > 4)
            y--;
        if (tecla == ABAJO && y < 30)
            y++;
        if (tecla == 'e')
            corazones--;
        pintar();
        pintar_corazones();
    }
}

/**
 * It prints the number of lives and hearts the player has left
 */
void NAVE::pintar_corazones()
{

    gotoxy(50, 2);
    cout << "VIDAS " << vidas;
    gotoxy(64, 2);
    cout << "SALUD";
    gotoxy(70, 2);
    cout << "       ";
    for (int i = 0; i < corazones; i++)
    {
        gotoxy(70 + i, 2);
        cout << (char)3;
    }
}

/**
 * If the player has no more hearts, the player's ship is destroyed and the player loses a life
 */
void NAVE ::morir()
{
    if (corazones == 0)
    {
        borrar();
        gotoxy(x, y);
        cout << " **  ";
        gotoxy(x, y + 1);
        cout << " *** ";
        gotoxy(x, y + 2);
        cout << " **  ";
        Sleep(200);

        borrar();
        gotoxy(x, y);
        cout << "* * *";
        gotoxy(x, y + 1);
        cout << " *** ";
        gotoxy(x, y + 2);
        cout << "* * *";
        Sleep(200);
        borrar();

        vidas--;
        corazones = 3;
        pintar_corazones();
        pintar();
    }
}

/* AST is a class that has two private variables, x and y, and a bunch of public functions. */
class AST
{
    int x, y;

public:
    AST(int _x, int _y) : x(_x), y(_y) {}
    void pintar();
    void mover();
    void choque(NAVE &N);
    int X() { return x; }
    int Y() { return y; }
};

/**
 * It prints a character at the coordinates x and y
 */
void AST ::pintar()
{
    gotoxy(x, y);
    cout << (char)147;
}

/**
 * This function is used to move the asterisk down the screen
 */
void AST ::mover()
{
    gotoxy(x, y);
    cout << " ";
    y++;
    if (y > 32)
    {
        x = rand() % 71 + 4;
        y = 4;
    }
    pintar();
}

/**
 * "If the x and y coordinates of the asteroid are within the x and y coordinates of the spaceship,
 * then the spaceship loses a life and the asteroid is reset to a random x and y coordinate."
 * 
 * The function is called in the main loop of the game, and it's called for each asteroid
 * 
 * @param N is the spaceship
 */
void AST ::choque(NAVE &N)
{
    if (x >= N.X() && x < N.X() + 5 && y >= N.Y() && y <= N.Y() + 2)
    {
        N.COR();
        N.borrar();
        N.pintar();
        N.pintar_corazones();
        x = rand() % 71 + 4;
        y = 4;
    }
}

/* A class that represents a bullet */
class BALA
{
    int x, y;

public:
    BALA(int _x, int _y) : x(_x), y(_y) {}
    int X() { return x; }
    int Y() { return y; }
    void mover();
    bool fuera();
};

/**
 * The function mover() is used to move the bullet up the screen
 */
void BALA ::mover()
{
    gotoxy(x, y);
    cout << " ";
    y--;
    gotoxy(x, y);
    cout << "*";
}

/**
 * "If the y coordinate of the bullet is equal to 4, then return true, otherwise return false."
 * 
 * The function is called "fuera" which means "out" in Spanish
 * 
 * @return a boolean value.
 */
bool BALA ::fuera()
{
    if (y == 4)
        return true;
    return false;
}

int main()
{
    cout << "\n";
    OcualtarCursor();
    pintar_limites();
    /* It's creating a new object of the class NAVE, and it's passing four parameters to the
    constructor. */
    NAVE N(37, 30, 3, 3);
    N.pintar();
    N.pintar_corazones();

    /* It's creating a list of pointers to AST objects, and then it's creating an iterator for the
    list. Then it's creating five AST objects and adding them to the list. */
    list<AST *> A;
    list<AST *>::iterator itA;
    for (int i = 0; i < 5; i++)
    {
        A.push_back(new AST(rand() % 75 + 3, rand() % 5 + 4));
    }

    list<BALA *> B;
    list<BALA *>::iterator it;

    bool game_over = false;
    int puntos = 0;
    /* It's the main loop of the game. */
    while (!game_over)
    {

        gotoxy(4, 2);
        cout << "PUNTOS " << puntos;
        /* It's checking if the player has pressed the 'a' key. If the player has pressed the 'a' key,
        then a new bullet is created. */
        if (kbhit())
        {
            char tecla = getch();
            if (tecla == 'a')
                B.push_back(new BALA(N.X() + 2, N.Y() - 1));
        }
        /* It's moving the bullets and checking if they are out of the screen. */
        for (it = B.begin(); it != B.end(); it++)
        {
            (*it)->mover();
            if ((*it)->fuera())
            {
                gotoxy((*it)->X(), (*it)->Y());
                cout << " ";
                delete (*it);
                it = B.erase(it);
            }
        }

        /* It's moving the asteroids and checking if they hit the spaceship. */
        for (itA = A.begin(); itA != A.end(); itA++)
        {
            (*itA)->mover();
            (*itA)->choque(N);
        }

        /* It's checking if the bullet and the asteroid are in the same position. If they are, then the
        asteroid is deleted and a new one is created. */
        for (itA = A.begin(); itA != A.end(); itA++)
        {
            for (it = B.begin(); it != B.end(); it++)
            {
                if ((*itA)->X() == (*it)->X() && ((*itA)->Y() + 1 == (*it)->Y() || (*itA)->Y() == (*it)->Y()))
                {
                    gotoxy((*it)->X(), (*it)->Y());
                    cout << " ";
                    delete (*it);
                    it = B.erase(it);

                    A.push_back(new AST(rand() % 74 + 3, 4));
                    gotoxy((*itA)->X(), (*itA)->Y());
                    cout << " ";
                    delete (*itA);
                    itA = A.erase(itA);

                    puntos += 5;
                }
            }
        }

        /* It's checking if the player has no more lives. If the player has no more lives, then the
        game is over. */
        if (N.VID() == 0)
            game_over = true;
        N.morir();
        N.mover();
        Sleep(50);
    }
    return 0;
}