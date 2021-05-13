#include <stdio.h>
#include <stdlib.h>
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
void gameloop(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia, int moverX, int moverY, int moveria);
void dibujar(char pantalla[V][H]);
void input(char pantalla[V][H], int *X, int *Y, int *inicioj, int *finj, int *inicioia, int *finia, int *moverX, int *moverY, int *moveria,int *gol);
void actualizar(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia);
void inicioS(int *longitud, char pantalla[V][H]);
void datos(char pantalla[V][H],int longitud);



int main()
{
	int opcion;

	do
	{
	printf("Selecciona juego: \n 1.Pong\n 2.Ahorcado\n 3.Tres en ralla\n 4.Buscaminas\n 5.Hundir la flota\n 6.Snake\n 7.Salir\n");
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
	gameloop(pantalla,X,Y,inicioj,finj,inicioia,finia,moverX,moverY,moveria);
	system ("pause");
	}
	break;
	case 2:
		printf("Instrucciones\n");
		break;
}
}while(op!=3);
		system("cls");
	}
				break;
			case 2:

//inicia el juego del ahorcado

				break;
			case 3:
//inicia el juego del tres en ralla
				break;
			case 4:

//inicia el juego del buscaminas

				break;
			case 5:

//inicia el juego de hundir la flota

				break;
			case 6:
				{
					snake a[N];
					comida b;
					int longitud;
					char pantalla[V][H];
					inicioS(&longitud,pantalla);
					dibujar(pantalla);
					system("pause");
				}

//inicia el juego del snake

				break;
		}
	}
	while(opcion!='7');

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
void gameloop(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia, int moverX, int moverY, int moveria)
{
	int gol;
	gol= 0;
	do
	{
		dibujar(pantalla);//dibuja en pantalla
		input(pantalla,&X,&Y,&inicioj,&finj,&inicioia,&finia,&moverX,&moverY,&moveria,&gol);//verificacion y modificacion de posiciones
		actualizar(pantalla,X,Y,inicioj,finj,inicioia,finia);//actualiza la pantalla
	}while (gol==0);
}

void dibujar(char pantalla[V][H])
{
	system("cls");
	leer(pantalla);
}

void input(char pantalla[V][H], int *X, int *Y, int *inicioj, int *finj, int *inicioia, int *finia, int *moverX, int *moverY, int *moveria,int*gol)
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

void actualizar(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia)
{
	borde(pantalla);
	raquetaj(pantalla, inicioj,finj);
	raquetaia(pantalla, inicioia,finia);
	pelota(pantalla, X, Y);
}

void inicioS(int *longitud, char pantalla[V][H])
{
	int i;
	snake a[N];
	comida b;
	a[0].x =21;//coordenadas inicio serpiente
	a[0].y = 5;
	*longitud=3;//longitud inicial serpiente
	srand(time(NULL));//coordenadas comida
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
	//al inicio avanza hacia la izquierda
	for(i=0;i<*longitud;i++)
	{
		a[i].moverX=-1;
		a[i].moverY=0;
	}
	borde(pantalla);
	datos(pantalla,*longitud);
}

void datos(char pantalla[V][H],int longitud)
{
	int i;
	snake a[N];
	comida b;
	for(i=1;i<longitud;i++)
	{
		a[i].x=a[i-1].x+1;//cuerpo de la serpiente
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
