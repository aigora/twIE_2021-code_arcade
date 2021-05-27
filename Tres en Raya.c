//  Tres en Raya definitivo

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define Jug_IA_X Jug_X
#define Jug_IA_O Jug_O
#define Juf_X 'X'
#define Jug_X 'O'
#define verificar_ganador 3

void Iniciar(int mode);
void duplicarMatriz (char origMesa[3][3],char final[3][3]);
void clean (char tablero[3][3]);
void print (char tablero[3][3]);
int empty (int y, int x, char tablero[3][3]);
void jugar (int y, int x, char pieza, char tablero[3][3]);
int up (int x, int y, char jugador, char tablero[3][3]);
int right (int x, int y, char jugador, char tablero[3][3]);
int upRight (int x, int y, char jugador, char tablero[3][3]);
int downright (int x, int y, char jugador, char tablero[3][3]);
