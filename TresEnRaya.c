#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void loop (char c[3][3]);
void PrimeraVez (char c[3][3]);
void mesa (char c[3][3]);
void Yo (char c[3][3], int jugador);
void Inteligencia_Artificial (char c[3][3]);
int winner (char c[3][3]);
void cas_ocupada (char c[3][3], char aux, char signo);

int main (){

    char c[3][3];
    
    loop (c);

    system ("pause");

    return 0;

}

void loop (char c[3][3]) {

   int i, j, a, jugador;
  
   
   do {
       PrimeraVez (c);
       
       printf("Estas jugando al TRES EN RAYA! \n\n");
       
       do{
       printf ("Escoge una opcion (introduce el numero 1 o 2):\
               \n 1) Jugar contra la maquina.\
               \n 2) Jugar con personas a la vez.\
               \n 3) Salir del juego.\n");
       scanf ("%i", &a);
       
       } while (a!=1 && a!=2 && a!=3);
       
       switch (a)
       {
           case 1:
               i=0;
               do{
           system ("cls");
           mesa(c);
           
           if(i% 2==0){
               jugador=1;
               Yo (c, jugador);
        }
        else {
            Inteligencia_Artificial(c);
        }
        j=winner(c);
        
        i++;
               
               } while (i<=8 && j==2);
   
    system ("cls");
    mesa(c);
   
   if (j==0){
           printf("Eres el ganador! \n\n");
   }
   else
   if(j==1){
           printf("Oh No! Has Perdido!!\n\n");
   }
   else if (j==2){
           printf("Habeis empatado! Intentalo de Nuevo!!");
   }
       break;
       
   case 2:
               i=0;
               do{
                   mesa (c);
           
                   if (i % 2 == 0) {
                   jugador=1;
                       Yo (c,jugador);
                   }
           
                   else {
                   jugador=2;
                       Yo (c,jugador);
                   }
           
                      j = winner (c);
                   i++;
           
                  } while (i<=8 && j==2);
       
               mesa (c);
       
               if (j==0)
               {
                   printf ("Enhorabuena! Ha ganado el jugador 1.\n\n");
               }
                else if (j==1)
                {
                   printf ("Enhorabuena! Ha ganado el jugador 2.\n\n");
               }
               else
               {
                   printf ("Habeis empatado.\n\n");
               }
           break;
       }
       } while (a!=3);
   }


void PrimeraVez (char c[3][3]){

    int i, j;
    char aux;

    aux = '1';

    for (i = 0; i<3; i++){

        for(j = 0; j<3; j++){

            c[i][j] = aux++;

        }
    }

}

void Yo (char c[3][3], int jugador){
    int i;
    char signo, cas;
    
    if (jugador==1)
    signo = 'X';
    
    else
        signo = 'O';
        
    do{
        printf ("Turno del jugador %i: ",jugador);
            fflush(stdin);
        scanf ("%c", &cas);
    }while (cas<'1' || cas>'9');
        
    cas_ocupada(c,cas,signo);
}

void cas_ocupada (char c[3][3], char aux, char signo){
    
    int i, j, k;
    
    do{
        k=0;
        
        switch (aux){
            case '1':{
                i=0;
                j=0;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            }
            case '2':
                i=0;
                j=1;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '3':
                i=0;
                j=2;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '4':
                i=1;
                j=0;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '5':
                i=1;
                j=1;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '6':
                i=1;
                j=2;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '7':
                i=2;
                j=0;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '8':
                i=2;
                j=1;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
            
            case '9':
                i=2;
                j=2;
                if(c[i][j]== 'X' || c[i][j]=='O'){
                    k=1;
                    printf("La casilla ya esta ocupada, prueba en una diferente. \n\n");
                    fflush(stdin);
                    scanf ("%c", &aux);
                }
                break;
        }
        
    } while (k==1);
    
    c[i][j]= signo;
}

void Inteligencia_Artificial (char c[3][3]){
    
    int i, j, k;
    
    srand (time(NULL));
    do{
        i=random() % 3;
        j=random() % 3;
        
        k=0;
        
        if(c[i][j]=='X' || c[i][j]=='O'){
            k=1;
        }
    } while (k==1);
    
    c[i][j]= 'O';
}

void mesa (char c[3][3]){

    int i, j;

    for(i=0; i<3; i++){

        for(j=0; j<3; j++){

            if(j<2){
                printf(" %c |", c[i][j]);
            }

            else{

                printf(" %c ", c[i][j]);
            }
        }
        if (i<2){
             printf("\n-----------\n");
        }
    }
    printf("\n\n");
}

int winner (char c[3][3]){
    
    if(c[0][0]=='X' || c[0][0]=='O'){
        if(c[0][0]==c[0][1] && c[0][0]==c[0][2]){
            if (c[0][0]=='X'){
                return 0; // Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
        if(c[0][0]==c[1][0] && c[0][0]==c[2][0]){
            if (c[0][0]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
    }
    
    if (c[1][1]=='X' ||c[1][1]=='O'){
        if (c[1][1]==c[0][0] && c[1][1]==c[2][2]){
            if (c[1][1]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
        if(c[1][1]==c[1][0] && c[1][1]==c[1][2]){
            if(c[1][1]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
        if(c[1][1]==c[2][0] && c[1][1]==c[0][2]){
            if(c[1][1]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
        if(c[1][1]==c[0][1] && c[1][1]==c[2][1]){
            if(c[1][1]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
    }
    if (c[2][2]=='X' ||c[2][2]=='O'){
        if (c[2][2]==c[2][0] && c[2][2]==c[2][1]){
            if (c[2][2]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
        if(c[2][2]==c[0][2] && c[2][2]==c[1][2]){
            if(c[2][2]=='X'){
                return 0; //Gana jugador 1
            }
            else {
                return 1; //Gana jugador 2
            }
        }
    }
    return 2; //Hemos empatado
}

