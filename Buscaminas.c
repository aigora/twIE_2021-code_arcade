//BUSCAMINAS
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void modoFacil(void);
void modoDificil(void);

int main(){
    
    char e;
    printf("Estas jugando al Buscaminas!\n");
    printf("Selecciona un modo de juego:\n");
    printf("(F)Facil\n(D)Dificil\n");
    scanf(" %c", &e);
    switch(e)
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
    int a1[2], a2[2], a3[2], a4[2], a5[2], a6[2];
    int mesa[6][6];
    int mesaInicial[6][6];
    int py, px;
    int resultado = 0;
    int numIntentos=0;
    
    printf("Has elegido modo dificil, por lo que tu mesa es 6x6:\n");
    
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            mesa[i][j]=0;
            printf("/ ");
                if(j==5)
                    printf("\n");
        }
    }
    printf("Recuerda de tienes 6 minas que evitar, BUENA SUERTE!!\n");
    sleep(2);
    
    for(i=0; i<6; i++)
    {
        for(j=0; j<6; j++)
        {
            mesaInicial[i][j]=0;
        }
    }
    srand( (unsigned int) time(NULL) );
    a1[0]=random()%6;
    a1[1]=random()%6;
    
    do{
        a2[0]=random()%6;
        a2[1]=random()%6;
    }while(a2[0]==a1[0] && a2[1]==a1[1]);
    
    do{
        a3[0]=random()%6;
        a3[1]=random()%6;
    }while((a3[0]==a1[0] && a3[1]==a1[1]) || (a3[0]==a2[0] && a3[1]==a2[1]));
    
    do{
        a4[0]=random()%6;
        a4[1]=random()%6;
    }while((a4[0]==a1[0] && a4[1]==a1[1]) || (a4[0]==a2[0] && a4[1]==a2[1]) || (a4[0]==a3[0] && a4[1]==a3[1]));
    
    do{
        a5[0]=random()%6;
        a5[1]=random()%6;
    }while((a5[0]==a1[0] && a5[1]==a1[1]) || (a5[0]==a2[0] && a5[1]==a2[1]) || (a5[0]==a3[0] && a5[1]==a3[1]) || (a5[0]==a4[0] && a5[1]==a4[1]));
    
    do{
        a6[0]=random()%6;
        a6[1]=random()%6;
    }while((a6[0]==a1[0] && a6[1]==a1[1]) || (a6[0]==a2[0] && a6[1]==a2[1]) || (a6[0]==a3[0] && a6[1]==a3[1]) || (a6[0]==a4[0] && a6[1]==a4[1]) || (a6[0]==a5[0] && a6[1]==a5[1]));
    
    mesa[a1[0]][a1[1]] = 9;
    mesa[a2[0]][a2[1]] = 9;
    mesa[a3[0]][a3[1]] = 9;
    mesa[a4[0]][a4[1]] = 9;
    mesa[a5[0]][a5[1]] = 9;
    mesa[a6[0]][a6[1]] = 9;
    
    printf("Introduce las coordenadas Y-X (entre 0 y 5)\n");
    do
    {
        printf("\n");
        scanf(" %i %i", &py, &px);
        printf("\n");
        
        if(( ((py==a1[0]) && (px==a1[1])) || ((py==a2[0]) && (px==a2[1])) || ((py==a3[0]) && (px==a3[1])) || ((py==a4[0]) && (px==a5[1])) || ((py==a5[0]) && (px==a4[1])) || ((py==a6[0]) && (px==a6[1])) ))
        {
            for(i=0; i<6; i++)
            {
                for(j=0; j<6; j++)
                {
                    printf("%i ", mesa[i][j]);
                    if(j==5)
                        printf("\n");
                }
            }
            printf("Has encontrado una MINA! Mira donde estaba el resto de ellas.\n");
            resultado='m';
        }
        else
        {
            mesaInicial[py][px] = 1;
            for(i=0; i<6; i++)
            {
                for(j=0; j<6; j++)
                {
                    printf("%i ", mesaInicial[i][j]);
                    if(j==5)
                        printf("\n");
                }
            }
            numIntentos++;
            if (numIntentos==60)
            {
                printf("ENHORABUENA, no has tocado ninguna mina...\n HAS GANADO LA PARTIDA\n");
            }
            else
            {
                printf("\nBien!, no has tocado ninguna mina, sigue jugando\n");
                printf("Introduce NUEVAS coordenadas Y-X (entre 0 y 5)\n");
            }
        }
    }while(resultado!='m');
}

void modoDificil()
{
    int i, j;
    int a1[2], a2[2], a3[2], a4[2], a5[2], a6[2], a7[2], a8[2], a9[2];
    int mesa[9][9];
    int mesaInicial[9][9];
    int py, px;
    int resultado = 0;
    char m;
    int numIntentos=0;
    
    printf("Has elegido modo dificil, por lo que tu mesa es 9x9:\n");
    
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            mesa[i][j]=0;
            printf("/ ");
                if(j==8)
                    printf("\n");
        }
    }
    printf("Recuerda de tienes 9 minas que evitar, BUENA SUERTE!!\n");
    sleep(2);

    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            mesaInicial[i][j]=0;
        }
    }
    
    srand( (unsigned int) time(NULL) );
    a1[0]=random()%9;
    a1[1]=random()%9;
    
    do{
        a2[0]=random()%9;
        a2[1]=random()%9;
    }while(a2[0]==a1[0] && a2[1]==a1[1]);
    
    do{
        a3[0]=random()%9;
        a3[1]=random()%9;
    }while((a3[0]==a1[0] && a3[1]==a1[1]) || (a3[0]==a2[0] && a3[1]==a2[1]));
    
    do{
        a4[0]=random()%9;
        a4[1]=random()%9;
    }while((a4[0]==a1[0] && a4[1]==a1[1]) || (a4[0]==a2[0] && a4[1]==a2[1]) || (a4[0]==a3[0] && a4[1]==a3[1]));
    
    do{
        a5[0]=random()%9;
        a5[1]=random()%9;
    }while((a5[0]==a1[0] && a5[1]==a1[1]) || (a5[0]==a2[0] && a5[1]==a2[1]) || (a5[0]==a3[0] && a5[1]==a3[1]) || (a5[0]==a4[0] && a5[1]==a4[1]));
    
    do{
        a6[0]=random()%9;
        a6[1]=random()%9;
    }while((a6[0]==a1[0] && a6[1]==a1[1]) || (a6[0]==a2[0] && a6[1]==a2[1]) || (a6[0]==a3[0] && a6[1]==a3[1]) || (a6[0]==a4[0] && a6[1]==a4[1]) || (a6[0]==a5[0] && a6[1]==a5[1]));
    
    do{
        a7[0]=random()%9;
        a7[1]=random()%9;
    }while((a7[0]==a1[0] && a7[1]==a1[1]) || (a7[0]==a2[0] && a7[1]==a2[1]) || (a7[0]==a3[0] && a7[1]==a3[1]) || (a7[0]==a4[0] && a7[1]==a4[1]) ||
    (a7[0]==a5[0] && a7[1]==a5[1]) || (a7[0]==a6[0] && a7[1]==a6[1]) );
    
    do{
        a8[0]=random()%9;
        a8[1]=random()%9;
    }while((a8[0]==a1[0] && a8[1]==a1[1]) || (a8[0]==a2[0] && a8[1]==a2[1]) || (a8[0]==a3[0] && a8[1]==a3[1]) || (a8[0]==a4[0] && a8[1]==a4[1]) ||
    (a8[0]==a5[0] && a8[1]==a5[1]) || (a8[0]==a6[0] && a8[1]==a6[1]) || (a8[0]==a7[0] && a8[1]==a7[1]));
    
    do{
        a9[0]=random()%9;
        a9[1]=random()%9;
    }while((a9[0]==a1[0] && a9[1]==a1[1]) || (a9[0]==a2[0] && a9[1]==a2[1]) || (a9[0]==a3[0] && a9[1]==a3[1]) || (a9[0]==a4[0] && a9[1]==a4[1]) ||
    (a9[0]==a5[0] && a9[1]==a5[1]) || (a9[0]==a6[0] && a9[1]==a6[1]) || (a9[0]==a7[0] && a9[1]==a7[1]) || (a9[0]==a7[0] && a9[1]==a7[1]));
    
    mesa[a1[0]][a1[1]] = 9;
    mesa[a2[0]][a2[1]] = 9;
    mesa[a3[0]][a3[1]] = 9;
    mesa[a4[0]][a4[1]] = 9;
    mesa[a5[0]][a5[1]] = 9;
    mesa[a6[0]][a6[1]] = 9;
    mesa[a7[0]][a7[1]] = 9;
    mesa[a8[0]][a8[1]] = 9;
    mesa[a9[0]][a9[1]] = 9;
    
    printf("Introduce las coordenadas Y-X (entre 0 y 8)\n");
    do
    {
        printf("\n");
        scanf(" %i %i", &py, &px);
        printf("\n");
       
        if(( ((py==a1[0]) && (px==a1[1])) || ((py==a2[0]) && (px==a2[1])) || ((py==a3[0]) && (px==a3[1])) || ((py==a4[0]) && (px==a4[1])) || ((py==a5[0]) && (px==a5[1])) ||
            ((py==a6[0]) && (px==a6[1])) || ((py==a7[0]) && (px==a7[1])) || ((py==a8[0]) && (px==a8[1])) || ((py==a9[0]) && (px==a9[1])) ))
        {
            for(i=0; i<9; i++)
            {
                for(j=0; j<9; j++)
                {
                    printf("%i ", mesa[i][j]);
                    if(j==8)
                        printf("\n");
                }
            }
            printf("Has encontrado una MINA! Mira donde estaba el resto de ellas.\n");
            resultado='m';
        }
        else
        {
            mesaInicial[py][px] = 1;
            for(i=0; i<9; i++)
            {
                for(j=0; j<9; j++)
                {
                    printf("%i ", mesaInicialrun[i][j]);
                    if(j==8)
                        printf("\n");
                }
            }
            numIntentos++;
            if (numIntentos==72)
            {
                printf("ENHORABUENA, no has tocado ninguna mina ... \n HAS GANADO LA PARTIDA\n");
            }
            else
            {
                printf("\nBien!, no has tocado ninguna mina, sigues jugando\n");
                printf("Introduce NUEVAS coordenadas Y-X (entre 0 y 8)\n");
            }
        }
    }while(resultado!='m');
}
