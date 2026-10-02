#include "pch.h"
#include <iostream>

using namespace System;
using namespace std;


const int columnas = 200;
const int filas = 45;

void goToXY(int x, int y) {
    Console::SetCursorPosition(x,y);
}

void printP(int x, int y) {
    goToXY(x, y);
    cout << "@";
}

void printP2(int x, int y) {
    goToXY(x, y);
    cout << "X";
}


void deleteP(int x, int y) {
    goToXY(x, y);
    cout << " ";
}
void deleteP2(int x, int y) {
    goToXY(x, y);
    cout << " ";
}

int main()
{
    Console::CursorVisible = false;
    Console::SetWindowSize(columnas, filas);
    Console::SetBufferSize(columnas, filas);

    int xP1 = 30;  int yP1 = 14; int dxP1 = -1; int dyP1 = 0; //PERSONAJE 1 -> @
    int xP2 = 100;  int yP2 = 6; int dxP2 = 0; int dyP2 = 1; //PERSONAJE 2 -> X

    while (1) {
        //=============BORRAR============
        deleteP(xP1, yP1);
        deleteP2(xP2, yP2);

        //=======CAMBIAR COORDENADAS====

        //cambio de deltas PERSONAJE 1
        //COLISIÓN HORIZONTAL IZQUIERDA
        if (xP1 <= 0) {
            dxP1 = 1;
        }
        //COLISIÓN HORIZONTAL DERECHHA
        if (xP1 >= columnas-1) {
            dxP1 = -1;
        }

        //cambio de deltas PERSONAJE 2
        //COLISIÓN VERTICAL ARRIBA
        if (yP2 <= 0) {
            dyP2 = 1;
        }
        //COLISIÓN VERTICAL ABAJO
        if (yP2 >= filas - 1) {
            dyP2 = -1;
        }


        //actulización de coordenadas
        xP1 += dxP1; yP1 += dyP1; // PERSONAJE 1
        xP2 += dxP2;  yP2 += dyP2; // PERSONAJE 2

        //=============MOSTRAR===========
        printP(xP1, yP1);
        printP2(xP2, yP2);


        _sleep(10);
    }


    cin.get();
    cin.ignore();

    return 0;
}
