//BUSCAMINAS
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void modoFacil(void); //el modo facil se trata de un 6x6 con 6 minas escondidas
void modoDificil(void); //el modo dificil incluye tablero 9x9 y 9 minas escondidas

//BUSCAMINAS

int main(){
    
    char e;
    printf("Estas juugando al Buscaminas!\n");
    printf("Selecciona un modo de juego:\n");
    printf("(F)Facil\n(D)Dificil\n");
    scanf(" %c", &e);
    switch(e) //segun la eleccion del jugador, el modo es facil o dificil
    {
        case 'F':
        case 'f':
            modoFacil();
        break;
        
        case 'D':
        case 'd':
            modoDificil();
        break;
    }
    
    return 0;
}

void modoFacil()
{
    int i, j;
    int v1[2], v2[2], v3[2], v4[2], v5[2], v6[2];
    int tablero[6][6]; //tablero de minas
    int tJug[6][6]; //tablero que ve el jugador
    int jx, jy; //variables que recogen la posicion donde se mueve el jugador
    int result = 0;//identifica minas
    int nIntentos=0; //contabiliza los intentos
    
    printf("Has elegido modo dificil, por lo que tu tablero es 6x6:\n");
    
    //Este bucle permite crear el tablero inicial(8x8)
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            tablero[i][j]=0;
            printf("/ ");
                if(j==5)
                    printf("\n");
        }
    }
    printf("Recuerda de tienes 6 minas que evitar, BUENA SUERTE!!\n");
    sleep(2);
    //Se crea aqui el tablero que vera el jugador(sin las minas)
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            tJug[i][j]=0;
        }
    }
    //se generan numeros aleatorios para las posiciones de las minas, en vectores
    srand( (unsigned int) time(NULL) ); //genera posiciones aleatorias para los valores 'x' e 'y' de cada mina
    v1[0]=rand()%6;
    v1[1]=rand()%6;
    
    //permite asegurarse de que las minas no esten en la misma posicion
    //reescribe el vector v2, hasta que su componente 'x' o 'y' sea distinta a la del vector 1
    do{
        v2[0]=rand()%6;
        v2[1]=rand()%6;
    }while(v2[0]==v1[0] && v2[1]==v1[1]);
    
    //reescribe el vector v3, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1 y 2
    do{
        v3[0]=rand()%6;
        v3[1]=rand()%6;
    }while((v3[0]==v1[0] && v3[1]==v1[1]) || (v3[0]==v2[0] && v3[1]==v2[1]));
    
    //reescribe el vector v4, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2 y 3
    do{
        v4[0]=rand()%6;
        v4[1]=rand()%6;
    }while((v4[0]==v1[0] && v4[1]==v1[1]) || (v4[0]==v2[0] && v4[1]==v2[1]) || (v4[0]==v3[0] && v4[1]==v3[1]));
    
    //reescribe el vector v5, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3 y 4
    do{
        v5[0]=rand()%6;
        v5[1]=rand()%6;
    }while((v5[0]==v1[0] && v5[1]==v1[1]) || (v5[0]==v2[0] && v5[1]==v2[1]) || (v5[0]==v3[0] && v5[1]==v3[1]) || (v5[0]==v4[0] && v5[1]==v4[1]));
    
    //reescribe el vector v6, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4 y 5
    do{
        v6[0]=rand()%6;
        v6[1]=rand()%6;
    }while((v6[0]==v1[0] && v6[1]==v1[1]) || (v6[0]==v2[0] && v6[1]==v2[1]) || (v6[0]==v3[0] && v6[1]==v3[1]) || (v6[0]==v4[0] && v6[1]==v4[1]) || (v6[0]==v5[0] && v6[1]==v5[1]));
    
    //x1 = rand()%8;
    //y1 = rand()%8; ... asi hasta 12 posiciones, 6 vectores
    
    tablero[v1[0]][v1[1]] = 9; //Se inicializa un 'flag' para las minas
    tablero[v2[0]][v2[1]] = 9;
    tablero[v3[0]][v3[1]] = 9;
    tablero[v4[0]][v4[1]] = 9;
    tablero[v5[0]][v5[1]] = 9;
    tablero[v6[0]][v6[1]] = 9;
    
    //Pedir al jugador que introduzca las coordenadas(x, y) de donde quiera caer. 'x' e 'y' estan entre 0 y 5
    printf("Introduce las coordenadas Y-X (entre 0 y 5)\n");
    do
    {
        printf("\n");
        scanf(" %i %i", &jx, &jy);
        printf("\n");
        //Se comprueba si el punto introducido por el jugador coincide con una mina
        if(( ((jx==v1[0]) && (jy==v1[1])) || ((jx==v2[0]) && (jy==v2[1])) || ((jx==v3[0]) && (jy==v3[1])) || ((jx==v4[0]) && (jy==v5[1])) || ((jx==v5[0]) && (jy==v4[1])) || ((jx==v6[0]) && (jy==v6[1])) ))
        {
            for(i=0; i<6; i++) //dibuja el tablero, con las minas
            {
                for(j=0; j<6; j++)
                {
                    printf("%i ", tablero[i][j]);
                    if(j==5)
                        printf("\n");
                }
            }
            printf("Has encontrado una MINA! Mira donde estaba el resto de ellas.\n");
            result='m';//si coincide, result lo almacena como 'm'. cuando result = 'm', el jugador habrá perdido
        }
        else
        {
            tJug[jx][jy] = 1;
            for(i=0; i<6; i++) //dibuja el tablero, sin las minas
            {
                for(j=0; j<6; j++)
                {
                    printf("%i ", tJug[i][j]);
                    if(j==5)
                        printf("\n");
                }
            }
            nIntentos++; //va sumando cada vez que el jugador rellena un hueco del tablero sin perder, cuando nIntentos=8x8-4(minas), el jugador habra ganado
            if (nIntentos==60)
            {
                printf("ENHORABUENA, no has tocado ninguna mina...\n HAS GANADO LA PARTIDA\n");
            }
            else
            {
                printf("\nBien!, no has tocado ninguna mina, sigue jugando\n");
                printf("Introduce NUEVAS coordenadas Y-X (entre 0 y 5)\n");
            }
        }
    }while(result!='m');
}

void modoDificil()
{
    int i, j;
    int v1[2], v2[2], v3[2], v4[2], v5[2], v6[2], v7[2], v8[2], v9[2];
    int tablero[9][9]; //tablero de minas
    int tJug[9][9]; //tablro que ve el jugador
    int jx, jy; //variables que recogen la posicion donde se mueve el jugador
    int result = 0;
    char m; //identifica minas
    int nIntentos=0; //contabiliza los intentos
    
    printf("Has elegido modo dificil, por lo que tu tablero es 9x9:\n");
    
    //Este bucle permite crear el tablero inicial(10x10)
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            tablero[i][j]=0;
            printf("/ ");
                if(j==8)
                    printf("\n");
        }
    }
    printf("Recuerda de tienes 9 minas que evitar, BUENA SUERTE!!\n");
    sleep(2);
    //Se crea aqui el tablero que vera el jugador(sin las minas)
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            tJug[i][j]=0;
        }
    }
    //se generan numeros aleatorios para las posiciones de las minas, en vectores
    srand( (unsigned int) time(NULL) ); //genera posiciones aleatorias para los valores 'x' e 'y' de cada mina
    v1[0]=rand()%9;
    v1[1]=rand()%9;
    
    //permite asegurarse de que las minas no esten en la misma posicion
    //reescribe el vector v2, hasta que su componente 'x' o 'y' sea distinta a la del vector 1
    do{
        v2[0]=rand()%9;
        v2[1]=rand()%9;
    }while(v2[0]==v1[0] && v2[1]==v1[1]);
    
    //reescribe el vector v3, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1 y 2
    do{
        v3[0]=rand()%9;
        v3[1]=rand()%9;
    }while((v3[0]==v1[0] && v3[1]==v1[1]) || (v3[0]==v2[0] && v3[1]==v2[1]));
    
    //reescribe el vector v4, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2 y 3
    do{
        v4[0]=rand()%9;
        v4[1]=rand()%9;
    }while((v4[0]==v1[0] && v4[1]==v1[1]) || (v4[0]==v2[0] && v4[1]==v2[1]) || (v4[0]==v3[0] && v4[1]==v3[1]));
    
    //reescribe el vector v5, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3 y 4
    do{
        v5[0]=rand()%9;
        v5[1]=rand()%9;
    }while((v5[0]==v1[0] && v5[1]==v1[1]) || (v5[0]==v2[0] && v5[1]==v2[1]) || (v5[0]==v3[0] && v5[1]==v3[1]) || (v5[0]==v4[0] && v5[1]==v4[1]));
    
    //reescribe el vector v6, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4 y 5
    do{
        v6[0]=rand()%9;
        v6[1]=rand()%9;
    }while((v6[0]==v1[0] && v6[1]==v1[1]) || (v6[0]==v2[0] && v6[1]==v2[1]) || (v6[0]==v3[0] && v6[1]==v3[1]) || (v6[0]==v4[0] && v6[1]==v4[1]) || (v6[0]==v5[0] && v6[1]==v5[1]));
    
    //reescribe el vector v7, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4, 5 y 6
    do{
        v7[0]=rand()%9;
        v7[1]=rand()%9;
    }while((v7[0]==v1[0] && v7[1]==v1[1]) || (v7[0]==v2[0] && v7[1]==v2[1]) || (v7[0]==v3[0] && v7[1]==v3[1]) || (v7[0]==v4[0] && v7[1]==v4[1]) ||
    (v7[0]==v5[0] && v7[1]==v5[1]) || (v7[0]==v6[0] && v7[1]==v6[1]) );
    
    //reescribe el vector v8, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4, 5, 6 y 7
    do{
        v8[0]=rand()%9;
        v8[1]=rand()%9;
    }while((v8[0]==v1[0] && v8[1]==v1[1]) || (v8[0]==v2[0] && v8[1]==v2[1]) || (v8[0]==v3[0] && v8[1]==v3[1]) || (v8[0]==v4[0] && v8[1]==v4[1]) ||
    (v8[0]==v5[0] && v8[1]==v5[1]) || (v8[0]==v6[0] && v8[1]==v6[1]) || (v8[0]==v7[0] && v8[1]==v7[1]));
    
    //reescribe el vector v9, hasta que sus componente 'x' o 'y' sean distintas a las del vector 1, 2, 3, 4, 5, 6, 7 y 8
    do{
        v9[0]=rand()%9;
        v9[1]=rand()%9;
    }while((v9[0]==v1[0] && v9[1]==v1[1]) || (v9[0]==v2[0] && v9[1]==v2[1]) || (v9[0]==v3[0] && v9[1]==v3[1]) || (v9[0]==v4[0] && v9[1]==v4[1]) ||
    (v9[0]==v5[0] && v9[1]==v5[1]) || (v9[0]==v6[0] && v9[1]==v6[1]) || (v9[0]==v7[0] && v9[1]==v7[1]) || (v9[0]==v7[0] && v9[1]==v7[1]));
    
    tablero[v1[0]][v1[1]] = 9; //Se inicializa un 'flag' para las minas
    tablero[v2[0]][v2[1]] = 9;
    tablero[v3[0]][v3[1]] = 9;
    tablero[v4[0]][v4[1]] = 9;
    tablero[v5[0]][v5[1]] = 9;
    tablero[v6[0]][v6[1]] = 9;
    tablero[v7[0]][v7[1]] = 9;
    tablero[v8[0]][v8[1]] = 9;
    tablero[v9[0]][v9[1]] = 9;
    
    //Pedir al jugador que introduzca las coordenadas(x, y) de donde quiera caer. 'x' e 'y' estan entre 0 y 8
    printf("Introduce las coordenadas Y-X (entre 0 y 8)\n");
    do
    {
        printf("\n");
        scanf(" %i %i", &jx, &jy);
        printf("\n");
        //Se comprueba si el punto introducido por el jugador coincide con una mina
        if(( ((jx==v1[0]) && (jy==v1[1])) || ((jx==v2[0]) && (jy==v2[1])) || ((jx==v3[0]) && (jy==v3[1])) || ((jx==v4[0]) && (jy==v4[1])) || ((jx==v5[0]) && (jy==v5[1])) ||
            ((jx==v6[0]) && (jy==v6[1])) || ((jx==v7[0]) && (jy==v7[1])) || ((jx==v8[0]) && (jy==v8[1])) || ((jx==v9[0]) && (jy==v9[1])) ))
        {
            for(i=0; i<9; i++) //dibuja el tablero, con las minas
            {
                for(j=0; j<9; j++)
                {
                    printf("%i ", tablero[i][j]);
                    if(j==8)
                        printf("\n");
                }
            }
            printf("Has encontrado una MINA! Mira donde estaba el resto de ellas.\n");
            result='m';//si coincide, result lo almacena como 'm'. cuando result = 'm', el jugador habrá perdido
        }
        else
        {
            tJug[jx][jy] = 1;
            for(i=0; i<9; i++) //dibuja el tablero, sin las minas
            {
                for(j=0; j<9; j++)
                {
                    printf("%i ", tJug[i][j]);
                    if(j==8)
                        printf("\n");
                }
            }
            nIntentos++; //va sumando cada vez que el jugador rellena un hueco del tablero sin perder, cuando nIntentos=8x8-4(minas), el jugador habra ganado
            if (nIntentos==72)
            {
                printf("ENHORABUENA, no has tocado ninguna mina ... \n HAS GANADO LA PARTIDA\n");
            }
            else
            {
                printf("\nBien!, no has tocado ninguna mina, sigues jugando\n");
                printf("Introduce NUEVAS coordenadas Y-X (entre 0 y 8)\n");
            }
        }
    }while(result!='m');
}
