//  Tres en Raya

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define Jug_IA_X Jug_X
#define Jug_IA_O Jug_O
#define Jug_X 'X'
#define Jug_O 'O'
#define verificar_ganador 3

void Iniciar(int mode); //Funcion loop principal
void duplicarMatriz (char origMesa[3][3],char final[3][3]); //Duplica la matriz, así no se altera la original
void clean (char tablero[3][3]); // Pone la matriz tablero en espacios libres
void print (char tablero[3][3]); //Imprime el tablero
int empty (int y, int x, char tablero[3][3]); //Permite saber si la casilla elegida esta ocupada
void jugar (int y, int x, char pieza, char tablero[3][3]); //Pone la ficha adecuada en la casilla elegida
int up (int x, int y, char jugador, char tablero[3][3]); //Las cuatro sigueintes funciones sirven para contar 
int right (int x, int y, char jugador, char tablero[3][3]); // las casillas que estan alineadas, es decir, 
int upRight (int x, int y, char jugador, char tablero[3][3]); // cuantas fichas del mismo tipo, X o O,
int downright (int x, int y, char jugador, char tablero[3][3]); // estan alineadas en el tablero
int verificarVictoria(char jugador, char tablero[3][3]); //Comprueba si alguno de os jugadores ha ganado
char rival (char jugador); //Esta funcion sirve para cambiar los turnos, recibe X y entrega O, por ejemplo                      
void imprimir_texto (char *mensaje, char jugador);
int tie (char origMesa[3][3]); // Permite saber si la partida ha acabado en empate
int random_rango (int minimo, int maximo); //Recibe los extremos de un intervalo y entrega uno aleatorio
void random_coordenadas (char jugador, char origMesa[3][3], int *yFin, int *xFin); //Coloca una ficha en una casilla al azar
void ganar_coordenadas (char jugador, char origMesa[3][3], int *yFin, int *xFin); //Coloca una ficha en una casilla con el objetivo de ganar                      
int contar (char jugador, char copiaMesa[3][3]); //Permite saber la mayor puntuacion sin especificar coordenadas
void puntos_coordenadas (char jugador, char tablero[3][3], int *yFin, int *xFin, int *conteo); //Especifica en que cordenadas sera mejor poner la pieza
void IA_coordenadas (char jugador, char tablero[3][3], int *yFin, int *xFin); // La inteligencia artificial elige las coordenadas para ganar

                      
int main(int argc, char const *argv[])
{
    int mode;
 
    printf("Bienvenido, estás jugando al TRES EN RAYA!!\n");
 do{
    printf("1. Jugador1 - Jugador2\n2. Jugador - Maquina\n3.Maquina - Maquina\n4. Salir\n");
    printf("Elige una de las opciones disponibles: ");
    scanf("%d", &mode);
    }while (mode !=1 && mode !=2 && mode !=3 && mode !=4);
 
    if (mode == 4)
    {
        return 0;
    }
 Iniciar(mode);
    return 0;
}

void Iniciar(int mode){
 
int Jug_Jug= 1, Jug_IA=2, IA_IA=3;
srand(getpid());

char tablero[3][3];

clean(tablero);

char jugador_turno = Jug_X;

printf("\nEmpezará el jugador: %c\n", jugador_turno);
int x, y;

while (1)
{
    print(tablero);
    if (mode == Jug_Jug || (mode == Jug_IA && jugador_turno == Jug_X))
    {
        printf("Introduce las coordenadas Jugador %c: \n", jugador_turno);
        scanf("%d %d", &x, &y);
        x--;
        y--;
    }
    else if (mode == IA_IA || (mode == Jug_IA && jugador_turno == Jug_IA_O))
    {
        IA_coordenadas(jugador_turno, tablero, &y, &x);
    }
    jugar(y, x, jugador_turno, tablero);
 
    if (verificarVictoria(jugador_turno, tablero))
    {
        print(tablero);
        printf("Ha ganado el jugador %c !!\n", jugador_turno);
     return;
    }
    else if (tie(tablero))
    {
        print(tablero);
        printf("Habeis empatado!!");
     return;
    }
    jugador_turno = rival(jugador_turno);
}
}

void duplicarMatriz(char origMesa[3][3], char final[3][3])
{
  
    memcpy(final, origMesa, 3*3);
}

void clean(char tablero[3][3])
{
    int y;
    for (y = 0; y < 3; y++)
    {
        int x;
        for (x = 0; x < 3; x++)
        {
            tablero[y][x] = ' ';
        }
    }
}

void print(char tablero[3][3])
{
    printf("\n");
    int y;
    int x;
    printf("| ");
    for (x = 0; x < 3; x++)
    {
        printf("|%d", x + 1);
    }
    printf("|\n");
    for (y = 0; y < 3; y++)
    {
        printf("|%d", y + 1);
        for (x = 0; x < 3; x++)
        {
            printf("|%c", tablero[y][x]);
        }
        printf("|\n");
    }
}

int empty(int y, int x, char tablero[3][3])
{
 
    return tablero[y][x] == ' ';
}

void jugar(int y, int x, char pieza, char tablero[3][3])
{
    if (y < 0 || y >= 3)
    {
        printf("casilla erronea, pierdes tu turno.");
        return;
    }

    if (x < 0 || x >= 3)
    {
        printf("casilla erronea, pierdes tu turno");
        return;
    }
    if (!empty(y, x, tablero))
    {
        printf("Casilla ocupada, pierdes tu turno.");
        return;
    }
    tablero[y][x] = pieza;
}

int up(int x, int y, char jugador, char tablero[3][3])
{
    int yInicio = (y - verificar_ganador >= 0) ? y - verificar_ganador + 1 : 0;
    int contador = 0;
    for (; yInicio <= y; yInicio++)
    {
        if (tablero[yInicio][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
    }
    return contador;
}

int right(int x, int y, char jugador, char tablero[3][3])
{
    int xFin = (x + verificar_ganador < 3) ? x + verificar_ganador - 1 : 3 - 1;
    int contador = 0;
    for (; x <= xFin; x++)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
    }
    return contador;
}

int upRight(int x, int y, char jugador, char tablero[3][3])
{
    int xFin = (x + verificar_ganador < 3) ? x + verificar_ganador - 1 : 3 - 1;
    int yInicio = (y - verificar_ganador >= 0) ? y - verificar_ganador + 1 : 0;
    int contador = 0;
    while (x <= xFin && yInicio <= y)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
        x++;
        y--;
    }
    return contador;
}

int downRight(int x, int y, char jugador, char tablero[3][3])
{
    int xFin = (x + verificar_ganador < 3) ? x + verificar_ganador - 1 : 3 - 1;
    int yFin = (y + verificar_ganador < 3) ? y + verificar_ganador - 1 : 3 - 1;
    int contador = 0;
    while (x <= xFin && y <= yFin)
    {
        if (tablero[y][x] == jugador)
        {
            contador++;
        }
        else
        {
            contador = 0;
        }
        x++;
        y++;
    }
    return contador;
}

int verificarVictoria(char jugador, char tablero[3][3])
{
    int y;
    for (y = 0; y < 3; y++)
    {
        int x;
        for (x = 0; x < 3; x++)
        {
            if (
                up(x, y, jugador, tablero) >= verificar_ganador ||
                right(x, y, jugador, tablero) >= verificar_ganador ||
                upRight(x, y, jugador, tablero) >= verificar_ganador ||
                downRight(x, y, jugador, tablero) >= verificar_ganador)
            {
                return 1;
            }
        }
    }
    return 0;
}

char rival(char jugador)
{
    if (jugador == Jug_O)
    {
        return Jug_X;
    }
    else
    {
        return Jug_O;
    }
}

void imprimir_texto(char *mensaje, char jugador)
{
    printf("\nMaquina 1 (%c) dice: %s\n\n", jugador, mensaje);
}

int tie(char origMesa[3][3])
{
    int y;
    for (y = 0; y < 3; y++)
    {
        int x;
        for (x = 0; x < 3; x++)
        {
            if (origMesa[y][x] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}
int random_rango(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

void random_coordenadas(char jugador, char origMesa[3][3], int *yFin, int *xFin)
{
    int x, y;
    do
    {
        x = random_rango(0, 3 - 1);
        y = random_rango(0, 3 - 1);
    } while (!empty(y, x, origMesa));
    *yFin = y;
    *xFin = x;
}

void ganar_coordenadas(char jugador, char origMesa[3][3], int *yFin, int *xFin)
{
    char coipaMesa[3][3];
    int y, x;
    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            duplicarMatriz(origMesa, coipaMesa);
            if (empty(y, x, coipaMesa))
            {
                jugar(y, x, jugador, coipaMesa);
                if (verificarVictoria(jugador, coipaMesa))
                {
                    *yFin = y;
                    *xFin = x;
                    return;
                }
            }
        }
    }
    *yFin = *xFin = -1;
}
int contar(char jugador, char coipaMesa[3][3])
{
    int cont_tot = 0;
    int x, y;
    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            int cont_temp;
            cont_temp = up(x, y, jugador, coipaMesa);
            if (cont_temp > cont_tot)
            {
                cont_tot = cont_temp;
            }
            cont_temp = upRight(x, y, jugador, coipaMesa);
            if (cont_temp > cont_tot)
            {
                cont_tot = cont_temp;
            }

            cont_temp = right(x, y, jugador, coipaMesa);
            if (cont_temp > cont_tot)
            {
                cont_tot = cont_temp;
            }

            cont_temp = downRight(x, y, jugador, coipaMesa);
            if (cont_temp > cont_tot)
            {
                cont_tot = cont_temp;
            }
        }
    }
    return cont_tot;
}
void puntos_coordenadas(char jugador, char origMesa[3][3], int *yFin, int *xFin, int *conteo)
{

    char coipaMesa[3][3];
    int y, x;
    int cont_tot = 0,
        xcont_tot = -1,
        ycont_tot = -1;
    for (y = 0; y < 3; y++)
    {
        for (x = 0; x < 3; x++)
        {
            duplicarMatriz(origMesa, coipaMesa);
            if (!empty(y, x, coipaMesa))
            {
                continue;
            }
            jugar(y, x, jugador, coipaMesa);
            int cont_temp = contar(jugador, coipaMesa);
            if (cont_temp > cont_tot)
            {
                cont_tot = cont_temp;
                ycont_tot = y;
                xcont_tot = x;
            }
        }
    }
    *conteo = cont_tot;
    *xFin = xcont_tot;
    *yFin = ycont_tot;
}

void IA_coordenadas(char jugador, char tablero[3][3], int *yFin, int *xFin)
{
  
    int y, x, cont_Jug, cont_riv;
    char oponente = rival(jugador);
    ganar_coordenadas(jugador, tablero, &y, &x);
    if (y != -1 && x != -1)
    {
        imprimir_texto("Voy a ganar", jugador);
        *yFin = y;
        *xFin = x;
        return;
    }
    ganar_coordenadas(oponente, tablero, &y, &x);
    if (y != -1 && x != -1)
    {
        imprimir_texto("Impido que gane mi rival", jugador);
        *yFin = y;
        *xFin = x;
        return;
    }
    puntos_coordenadas(jugador, tablero, &y, &x, &cont_Jug);
    puntos_coordenadas(oponente, tablero, &y, &x, &cont_riv);
    if (cont_riv > cont_Jug)
    {
        imprimir_texto("Busco mi victoria", jugador);
        *yFin = y;
        *xFin = x;
        return;
    }
    else
    {
        imprimir_texto("Busco mi victoria", jugador);
        *yFin = y;
        *xFin = x;
        return;
    }
 if (empty(0, 0, tablero))
     {
         imprimir_texto("Tomar columna superior izquierda", jugador);
         *yFin = 0;
         *xFin = 0;
         return;
     }
     // 5
     imprimir_texto("Coordenadas aleatorias", jugador);
     random_coordenadas(jugador, tablero, yFin, xFin);
} 
                                      
                      
