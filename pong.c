#include <stdio.h>
#define V 26 //V marca las dimensiones de la vertical
#define H 60 //H marca las dimensiones de la horizontal
void inicio(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia);//
void borde(char pantalla[V][H]);//dibuja los bordes de la pantalla rellenando la matriz
void raquetaj(char pantalla[V][H], int inicioj, int finj);//dibuja la raqueta del jugador
void raquetaia(char pantalla[V][H], int inicioia, int finia);//dibuja la raqueta de la ia
void pelota(char campo[V][H], int X, int Y);//dibuja la pelota
void leer(char pantalla[V][H]);//lee la matriz
int main()
{
	int X, Y, inicioj, finj, inicioia, finia; 
	//X e Y son las variables de posicion de la pelota 
	//incioj e finj indica el inicio y fin de las raquetas del jugador
	//inicioia e finia indica el inicio y fin de la raqueta de la ia (inteligencia artificial) 
	char pantalla[V][H]; //pantalla es espacio en el que se va a jugar
	X=30; //es la mitad de H
	Y=13; //es la mitad de V
	//la pelota comienza en el centro de la pantalla (se puede empezar en cualquier otro sitio)
	inicioj=10;
	finj= 14;
	//la raqueta del jugador comienza en la mitad
	inicioia= 10;
	finia=14;
	//la raqueta de la ia empieza a la mitad
	inicio(pantalla,X,Y,inicioj,finj,inicioia,finia);
	leer(pantalla);
	system ("pause");
	return 0;
}
void inicio(char pantalla[V][H], int X, int Y, int inicioj, int finj, int inicioia, int finia)
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
