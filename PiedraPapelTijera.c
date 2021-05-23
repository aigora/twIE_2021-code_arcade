#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int i; //Contador
    int Jugador=0, Maquina; //Jugadas elegidas
    int PJ=0, PM=0; // Puntuacion de cada uno
    char Papel[]="Papel", Tijera[]="Tijera", Piedra[]="Piedra"; //Opciones de jugada
    
    printf("Estas jugando al PIEDRA, PAPEL O TIJERA!!\n");
    printf("Vamos a jugar al mejor de 5\n");
    printf("¿Estas preparado?\n");
    
    for(i=1; i<6; i++){
    do{
    printf("-Elige tu jugada:\n");
    printf("1. Papel\n2. Tijera\n3. Piedra\n\n");
    scanf("%d", &Jugador);
    } while(Jugador!=1 && Jugador!=2 && Jugador!=3);
    
    Maquina=(rand()%3)+1;
    
    if(Jugador==1 && Maquina==1){
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Papel, Papel);
        printf("\nHabeis EMPATADO en esta ronda\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if(Jugador==2 && Maquina==2){
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Tijera, Tijera);
        printf("\nHabeis EMPATADO en esta ronda\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if(Jugador==3 && Maquina==3){
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Piedra, Piedra);
        printf("\nHabeis EMPATADO en esta ronda\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if((Jugador==1) && (Maquina==2)){
        PM++;
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Papel, Tijera);
        printf("\nLo siento, has PERDIDO esta ronda!\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if((Jugador==1) && (Maquina==3)){
        PJ++;
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Papel, Piedra);
        printf("\nEnhorabuena, has GANADO esta ronda!\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if((Jugador==2) && (Maquina==1)){
        PJ++;
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Tijera, Papel);
        printf("\nEnhorabuena, has GANADO esta ronda!\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if((Jugador==2) && (Maquina==3)){
        PM++;
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Tijera, Piedra);
        printf("\nLo siento, has PERDIDO esta ronda!\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
    if((Jugador==3) && (Maquina==2)){
        PJ++;
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Piedra, Tijera);
        printf("\nEnhorabuena, has GANADO esta ronda!\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
        
    }
    if((Jugador==3) && (Maquina==1)){
        PM++;
        printf("\n%i.----------------\n", i);
        printf("Tu opcion fue %s y la de tu oponente fue %s", Piedra, Papel);
        printf("\nLo siento, has PERDIDO esta ronda!\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
        printf("%i.----------------\n\n", i);
    }
        PJ=PJ;
        PM=PM;
    }
    
    printf("-------------------------------\n");
    printf("Ha terminado el juego!!\n ");
    
    if((PJ>PM)){
        printf("Has GANADO la partida, este ha sido el resultado final:\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
    }
    if((PJ<PM)){
        printf("Has PERDIDO la partida, este ha sido el resultado final:\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
    }
    if(PJ==PM){
        printf("Habeis EMPATADO la partida, este ha sido el resultado final:\n");
        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
    }
    
    return 0;
}
