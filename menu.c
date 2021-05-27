#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define V 26 //V marca las dimensiones de la vertical
#define H 60 //H marca las dimensiones de la horizontal
#define N 100

typedef struct
{
	int x,y;
	int moverX,moverY;
	char imagen;
}snake;

typedef struct
{
	int x,y;
}comida;



void inicioP(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia);//
void borde(char pantalla[V][H]);//dibuja los bordes de la pantalla rellenando la matriz
void raquetaj(char pantalla[V][H], int inicioj, int finj);//dibuja la raqueta del jugador
void raquetaia(char pantalla[V][H], int inicioia, int finia);//dibuja la raqueta de la ia
void pelota(char pantalla[V][H], int X, int Y);//dibuja la pelota
void leer(char pantalla[V][H]);//lee la matriz
void gameloopP(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia, int moverX, int moverY, int moveria);
void dibujar(char pantalla[V][H]);
void inputP(char pantalla[V][H], int *X, int *Y, int *inicioj, int *finj, int *inicioia, int *finia, int *moverX, int *moverY, int *moveria,int *gol);
void actualizarP(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia);
void inicioS(int *longitud, char pantalla[V][H],snake a[N],comida b);
void datos(char pantalla[V][H],int longitud, snake a[N], comida b);
void inputS(char pantalla[V][H], int *longitud, int*fin, snake a[N],comida b);
void actualizarS(char pantalla[V][H], int longitud,snake a[N],comida b);
void datos2(char pantalla[V][H], int longitud, snake a[N], comida b);
void gameloopS(char pantalla[V][H], int longitud,snake a[N],comida b);



int main()
{
	int opcion;

	do
	{
	printf("Selecciona juego: \n 1.Pong\n 2.Ahorcado\n 3.Tres en ralla\n 4.Piedra, papel o tijera\n 5.Snake\n 6.Salir\n");
	scanf("%i",&opcion);
	
		switch(opcion)
		{
			case 1:
				{
//inicia el juego del pong 
	int op;
	do
	{	
	printf("Bienvenido al juego del pong. Para comenzar pulse 1, 2 para ver las instrucciones o 3 para volver al inicio");
	scanf("%i",&op);
	
	switch(op)
	{
		case 1:
			{
	int X, Y, inicioj, finj, inicioia, finia; //variables de posicion
	int moverX,moverY, moveria;//variables de movimiento
	//X e Y son las variables de posicion de la pelota 
	//incioj e finj indica el inicio y fin de las raquetas del jugador
	//inicioia e finia indica el inicio y fin de la raqueta de la ia (inteligencia artificial) 
	char pantalla[V][H]; //pantalla es espacio en el que se va a jugar
	X=30; //es la mitad de H
	Y=13; //es la mitad de V
	//la pelota comienza en el centro de la pantalla (se puede empezar en cualquier otro sitio)
	inicioj=10;
	finj= 16;
	//la raqueta del jugador comienza en la mitad
	inicioia= 5;
	finia=24;
	//la raqueta de la ia empieza a la mitad
	moverX=-1;
	moverY=-1;
	moveria=-1;
	inicioP(pantalla,X,Y,inicioj,finj,inicioia,finia);
	gameloopP(pantalla,X,Y,inicioj,finj,inicioia,finia,moverX,moverY,moveria);
	system ("pause");
	}
	break;
	case 2:
		printf("Instrucciones\n El pong consiste en que no te marquen gol, para ello dispones de una raqueta\n que se mueve hacia arriba pulsando w y abajo pulsando x\n");
		break;
}
}while(op!=3);
		system("cls");
	}
				break;
			case 2:
				{
				
				}

//inicia el juego del ahorcado

				break;
			case 3:
				{
				

				
				
				}
//inicia el juego del tres en ralla
				break;
			case 4:
				{
						
					 	int op;
					 	do
					 	{
					 		printf("\nBienvenido a piedra, papel o tijera. Para jugar pulse 1,\n para ver las instrucciones pulse 2 o pulsa 3 para volver al inicio\n\n");
					 	scanf("%i",&op);
					 	switch(op)
					 	{
					 		
					 		case 1:
					 			{
					 				int i; //Contador
								    int Jugador=0, Maquina; //Jugadas elegidas
								    int PJ=0, PM=0; // Puntuacion de cada uno
								    char Papel[]="Papel", Tijera[]="Tijera", Piedra[]="Piedra"; //Opciones de jugada
	
								    printf("Estas jugando al PIEDRA, PAPEL O TIJERA!!\n");
								    printf("Vamos a jugar al mejor de 5\n");
								    printf("¿Estas preparado?\n\n");
								    
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
								    
								    printf("-------------------------------\n\n");
								    printf("Ha terminado el juego!!\n\n ");
								    
								    if((PJ>PM)){
								        printf("Has GANADO la partida, este ha sido el resultado final:\n\n");
								        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
								    }
								    if((PJ<PM)){
								        printf("Has PERDIDO la partida, este ha sido el resultado final:\n\n");
								        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
								    }
								    if(PJ==PM){
								        printf("Habeis EMPATADO la partida, este ha sido el resultado final:\n\n");
								        printf("Jugador - Maquina : %i - %i\n", PJ, PM);
								    }
					    
					    
								 }
					 			break;
						 
					case 2:
						{
						printf("Intrucciones\nEste juego se basa en el mitico juego del piedra papel o tijera.\n Las partidas son al mejor de 5. Para elegir una opcion se pulsa1, 2 o 3\n");
						break;
					}
						
					}
				}while(op!=3);
			}


//inicia el juego del buscaminas

				break;

			case 5:
				{
					int op;
					do
					{
						printf("Bienvenido al juego del snake. Pulsa 1 para comenzar la partida, 2 para ver las instrucciones o 3 para volver al menu principal:\n");
						scanf("%i",&op);
						switch(op)
							{
								case 1:
									{
										snake a[N];
										comida b;
										int longitud;
										char pantalla[V][H];
										inicioS(&longitud,pantalla,a,b);
										leer(pantalla);
										gameloopS(pantalla,longitud,a,b);
										system("pause");
										break;
									}
								case 2:
									{
										printf("Instrucciones:\n El juego consiste en ir comiendose la comida para hacerse mas grande sin chocarse con los bordes.\nControles:\nPulsa w para desplazarte hacia arriba.\nPulsa X para desplazarte hacia abajo.\nPulsa A para moverte hacia la izquierda.\nPulsa D para moverte a la derecha.\n");
									}
							}

					}while (op!=3);
				
				}

//inicia el juego del snake

				break;
		}
	}
	while(opcion!='6');

	return 0;
}
	void inicioP(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia)
{
	borde(pantalla);
	raquetaj(pantalla, inicioj,finj);
	raquetaia(pantalla, inicioia,finia);
	pelota(pantalla, X, Y);
}

void borde(char pantalla[V][H])
{
	int i, j;
	for(i=0;i<V;i++)
	{
		for(j=0;j<H;j++)
		{
			if(i==0||i==V-1)
			pantalla[i][j]='-';
			else if (j==0||j==H-1)
			pantalla[i][j]='|';
			else
			pantalla[i][j]=' ';
		
		}
	}
}

void raquetaj(char pantalla[V][H], int inicioj, int finj)
{
	int i, j;
	for(i=inicioj;i<finj;i++)
	{
		for(j=1;j<=2;j++)
		{
			pantalla[i][j]='+'; //rellena la matriz con +
		}
	}
}

void raquetaia(char pantalla[V][H], int inicioia, int finia)
{
	int i, j;
	for(i=inicioia;i<=finia;i++)
	{
		for(j= H-3;j<=H-2;j++)
		{
			pantalla[i][j]='+'; //rellena la matriz con +
		}
	}
}

void pelota(char pantalla[V][H], int X, int Y)
{
	pantalla[Y][X]='O';
}

void leer(char pantalla[V][H])
{
	int i, j;
	for (i=0;i<V;i++)
	{
		for (j=0;j<H;j++)
		{
		printf("%c",pantalla[i][j]);
		}
		printf("\n");
	}
}
void gameloopP(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia, int moverX, int moverY, int moveria)
{
	int gol;
	gol= 0;
	do
	{
		dibujar(pantalla);//dibuja en pantalla
		inputP(pantalla,&X,&Y,&inicioj,&finj,&inicioia,&finia,&moverX,&moverY,&moveria,&gol);//verificacion y modificacion de posiciones
		actualizarP(pantalla,X,Y,inicioj,finj,inicioia,finia);//actualiza la pantalla
	}while (gol==0);
}

void dibujar(char pantalla[V][H])
{
	system("cls");
	leer(pantalla);
}

void inputP(char pantalla[V][H], int *X, int *Y, int *inicioj, int *finj, int *inicioia, int *finia, int *moverX, int *moverY, int *moveria,int*gol)
{
	int i;
	char tecla;
	if(*Y==1 || *Y==V-2)//comprueba si la pelota choca arriba o abajo
	{
		*moverY *= -1;//cambia la direccion vertical
	}
	if(*X== 1 || *X== H-2)//comprueba si choca a los lados y no habia raqueta
	{
		*gol = 1;//modifica gol para salir del programa
	}
	if(*X==4)//comprueba que la pelota choca con la raqueta del jugador
	{
		for(i=(*inicioj);i<=(*finj);i++)
		{
			if(i==(*Y))
			{
				*moverX *= -1;//cambia la direccion horizontal de la pelota
			}
		}
	}
	if(*X == H-5)//comprueba que la pelota choca con la raqueta de la ia
	{
		for(i=(*inicioia);i<=(*finia);i++)
		{
			if(i==(*Y))
			{
				*moverX *= -1;//cambia la direccion horizontal de la pelota
			}
		}
	}
	if(*inicioia == 1 || *finia == V-1)
	{
		*moveria *= -1;
	}
	if(*gol==0)
	{
		*X += (*moverX);
		*Y += (*moverY);
		
		*inicioia += (*moveria);
		*finia +=(*moveria);
		
		if(kbhit()==1)
		{
			tecla=getch();//igual scanf pero sin pulsar intro
			if(tecla=='w')
			{
				if(*inicioj != 1)
				{
					*inicioj -= 1;
					*finj -= 1;
				}
			}
		}
		if(tecla =='x')
		{
			if(*finj !=V-2)
			{
				*inicioj += 1;
				*finj += 1;
			}
		}
	}
}

void actualizarP(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia)
{
	borde(pantalla);
	raquetaj(pantalla, inicioj,finj);
	raquetaia(pantalla, inicioia,finia);
	pelota(pantalla, X, Y);
}

void inicioS(int *longitud, char pantalla[V][H],snake a[N],comida b)
{
	int i;
	a[0].x =30;//coordenadas inicio serpiente
	a[0].y = 13;
	*longitud=4;//longitud inicial serpiente
	srand(time(NULL));//coordenadas comida
	b.x=rand()%20;
	b.y=rand()%20;
	//controla que la comida no aparezca en los bordes
	while(b.x==0)
	{
		b.x=rand()%(H-1);	
	}
	while(b.y==0)
	{
		b.y=rand()%(V-1);
	}
	//al inicio avanza hacia la izquierda
	for(i=0;i<*longitud;i++)
	{
		a[i].moverX=1;
		a[i].moverY=0;
	}
	borde(pantalla);
	datos(pantalla,*longitud,a,b);
}

void datos(char pantalla[V][H],int longitud, snake a[N], comida b)
{
	int i;
	for(i=1;i<longitud;i++)
	{
		a[i].x=a[i-1].x-1;//cuerpo de la serpiente
		a[i].y=a[i-1].y;
		a[i].imagen='Z';
	}
	a[0].imagen='O';
	for(i=0;i<longitud;i++)
	{
		pantalla[a[i].y][a[i].x]=a[i].imagen;//meto imagen de la serpiente
	}
	pantalla[b.y][b.x]='S';

}

void gameloopS(char pantalla[V][H], int longitud,snake a[N],comida b)
{
	int fin;
	fin=0;
	do
	{
		system("cls");
		leer(pantalla);
		inputS(pantalla,&longitud,&fin,a,b);
		actualizarS(pantalla,longitud,a,b);
	}while(fin==0);
}

void inputS(char pantalla[V][H], int *longitud, int *fin, snake a[N],comida b)
{
	int i;
	char tecla;
	if(a[0].x==0||a[0].x==(H-1)||a[0].y==0||a[0].y==(V-1))//comprueba si se choca con los bordes
	{
		*fin =1;
	}
	for (i=1;i<*longitud&&*fin==0;i++)
	{
		if(a[0].x==a[i].x&&a[0].y==a[i].y)//comprueba si la serpiente se choca con si misma
		{
			*fin=1;
		}
	}
	if(a[0].x==b.x&&a[0].y==b.y)
	{
		*longitud +=1;
		a[*longitud-1].imagen='Z';
		b.x=rand()%(H-1);
		b.y=rand()%(V-1);
		//controla que la comida no aparezca en los bordes
		while(b.x==0)
		{
			b.x=rand()%(H-1);	
		}
		while(b.y==0)
		{
			b.y=rand()%(V-1);
		}
		
	}
	if(*fin==0)
	{
		if(kbhit()==1)
		{
			tecla = getch();
			if(tecla=='x'&&a[0].moverY!=-1)
			{
				a[0].moverX=0;
				a[0].moverY=1;
			}
			if(tecla=='w'&&a[0].moverY!=1)
			{
				a[0].moverX=0;
				a[0].moverY=-1;
			}
			if(tecla=='a'&&a[0].moverX!=1)
			{
				a[0].moverY=-1;
				a[0].moverY=0;
			}
			if(tecla=='d'&&a[0].moverX!=-1)
			{
				a[0].moverY=1;
				a[0].moverY=0;
			}
		}
	}
}

void actualizarS(char pantalla[V][H], int longitud,snake a[N],comida b)
{
	borde(pantalla);
	datos2(pantalla,longitud,a,b);
}

void datos2(char pantalla[V][H], int longitud, snake a[N], comida b)
{
	int i;
	for(i=(longitud-1);i>0;i--)
	{
		a[i].x=a[i-1].x;
		a[i].y=a[i-1].y;
	}
	a[0].x +=a[0].moverX;
	a[0].y +=a[0].moverY;
	for(i=0;i<longitud;i++)
	{
		pantalla[a[i].y][a[i].x]=a[i].imagen;
	}
	pantalla[b.y][b.x]='S';
}

