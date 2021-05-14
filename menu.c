#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define V 26 //V marca las dimensiones de la vertical
#define H 60 //H marca las dimensiones de la horizontal
#define N 100
#define E 40
#define D 20

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

typedef struct{
	char palabra[E];
}pal;

typedef struct{
	char nombre[E];
	int punt;
}usuario;

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
void principal(char adivinapalabra[E], char cadena[E]);
int numaleatorio(int n);
int ahorcado(char adivinapalabra[E], char cadena[E]);
int imprime_ahorcado(int intentos);
void Puntuaciones(usuario lista_punt[D],FILE *leer);
void modoPrincipiante(void);
void modoExperto(void);
void loop (char c[3][3]);
void PrimeraVez (char c[3][3]);
void mesa (char c[3][3]);
void Yo (char c[3][3], int jugador);
void Inteligencia_Artificial (char c[3][3]);
int winner (char c[3][3]);
void cas_ocupada (char c[3][3], char aux, char signo);


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
	gameloopP(pantalla,X,Y,inicioj,finj,inicioia,finia,moverX,moverY,moveria);
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
				{
				int aleatorio=0;
	
				pal peliculas[10]={"INTERSTELLAR" , "INFILTRADOS" , "HARRY POTTER" , "TITANIC" , "TRANSFORMERS" , "STAR WARS" , "GLADIATOR" , "JURASSIC PARK" , "EL CABALLERO OSCURO" , "TOY STORY"};
				pal series[10]={"JUEGO DE TRONOS" , "STRANGER THINGS" , "RIVERDALE" , "FRIENDS" , "VIKINGOS" , "LA QUE SE AVECINA" , "LA CASA DE PAPEL" , "PEAKY BLINDERS" , "CASTLE" , "THE BIG BANG THEORY"};
				pal musica[10]={"DUA LIPA" , "JUSTIN BIEBER" , "DRAKE" , "MICHAEL JACKSON" , "J BALVIN" , "LADY GAGA" , "AVICII" , "MADONNA" , "RIHANNA" , "EMINEM"};
				pal deportes[10]={"FUTBOL" , "BALONCESTO" , "PADEL" , "ESCALADA" , "TENIS" , "BOXEO" , "CICLISMO" , "SURF" , "RUGBY" , "NATACION"};
				char letra;
				char letrausuario[E]=" ";
				printf("Bienvenido al Ahorcado\n");
				system ("PAUSE");
				system("CLS");
				printf("El objetivo es adivinar la palabra con el minimo numero de fallos\n");
				system("PAUSE"); 
				system("CLS");
				printf("Selecciona la categoria de la frase:\na.Peliculas\nb.Series\nc.Artistas Musicales\nd.Deportes\n");
					switch(getch()){
						
						case 'a':
						case 'A':
							system("CLS");
							printf("Has elegido la categoria de Peliculas\n");
							aleatorio = numaleatorio(10);
							principal(peliculas[aleatorio].palabra, letrausuario);
							break;
							
						case 'b':
						case 'B':
							system("CLS");
							printf("Has elegido la categoria de Series\n");
							aleatorio = numaleatorio(10);
							principal(series[aleatorio].palabra, letrausuario);
							break;
							
						case 'c':
						case 'C':
							system("CLS");
							printf("Has elegido la categoria de Artistas Musicales\n");
							aleatorio = numaleatorio(10);
							principal(musica[aleatorio].palabra, letrausuario);
							break;
							
						case 'd':
						case 'D':
							system("CLS");
							printf("Has elegido la categoria de Deportes\n");
							aleatorio = numaleatorio(10);
							principal(deportes[aleatorio].palabra, letrausuario);
							break;
							
						default:
						printf("Escoge una opcion valida\n");
						system("PAUSE");		
					}
					
				}

//inicia el juego del ahorcado

				break;
			case 3:
				{
				
				    char c[3][3];
				    
				    loop (c);
				
				    system ("pause");
				
				
				}
//inicia el juego del tres en ralla
				break;
			case 4:
				{
				   int o;
				    printf("Estas jugando al Buscaminas!\n");
				    printf("Selecciona un modo de juego:\n");
				    printf("(1)Principiante \n(2)Experto\n");
				    scanf(" %i", &o);
				    switch(o)
				    {
				        case 1:
				            modoPrincipiante();
				        break;
				        
				        case 2:
				            modoExperto();
				        break;
				    }
				}

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
					inicioS(&longitud,pantalla,a,b);
					leer(pantalla);
					gameloopS(pantalla,longitud,a,b);
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
		
		dibujar(pantalla);
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

void principal(char adivinapalabra[30], char cadena[30])
	{
	int intentos=7, fallos=0, i, puntuacion,si_perdido;
	i=0;
	
	char nombre[20]="";
	usuario lista_puntuaciones[D]={{"iniciar",0}};
	FILE *agregar=fopen("puntuacion_ahorcado.txt","a");
	
		if(agregar==NULL){
		printf("\n\t Error");
		exit(1);
	}
	
	float t1=clock(), t2, tiempo_total;
	
	while(1){
		fallos=ahorcado(adivinapalabra, cadena);
		
		if(fallos==-1){
			printf("\nHAS GANADO!!\n");
			t2=clock();
			tiempo_total = (t2-t1)/CLOCKS_PER_SEC;
			puntuacion=1000000/(int)tiempo_total*intentos;
			printf("Has tardado %f\nTu puntuacion ha sido de %i\n", tiempo_total, puntuacion);
			printf("Introduce tu nombre:\n");
			scanf(" %[^\n]", nombre);
			fprintf(agregar, "%s.%i\n", nombre, puntuacion);
			fclose(agregar);
			FILE *leer=fopen("puntuacion_ahorcado.txt","r");
			Puntuaciones(lista_puntuaciones, leer);
			break;
		}
		intentos-=fallos;
		printf("\n\n");
		si_perdido=imprime_ahorcado(intentos);
		
		if(si_perdido==1) break;
		printf("\nLas letras introducidas que llevas son: %s\n", cadena);
		printf("Introduce una letra:\n");
		cadena[i]=getch();
		system("CLS");				
		i++;					
	}
}

int numaleatorio(int n){
srand(time(NULL));
int i;
	i = rand()%n;
	return i;
}

int ahorcado(char adivinapalabra[30], char letrausuario[30]){
	
	int i, n,Pregunta_fallo, iguales, ganado=1, dif='A'-'a',ultima_letra_usuario=strlen(letrausuario);
	
	for(i=0; adivinapalabra[i]!='\0'; i++){
		
		for(n=0, iguales=0; n<ultima_letra_usuario; n++){
			if(letrausuario[n]==adivinapalabra[i] || letrausuario[n]==adivinapalabra[i]-dif){
				iguales = 1;
			}
		}
		if(iguales==1){
			printf("%c ", adivinapalabra[i]);
		}
		else if(adivinapalabra[i]==' '){
			printf("   "); 
		}
		else{
			ganado=0;
					
			if( adivinapalabra[i]>= 'A' &&  adivinapalabra[i]<= 'Z'){
				printf("_ ");	
			}
		
			if(adivinapalabra[i] >= 'a' && adivinapalabra[i] <= 'z'){
				printf("_ ");
			}
		}
	}
	if(ganado==1){
		
		return -1;
	}
	if(strlen(adivinapalabra)!=1)
		for(i=0,Pregunta_fallo=1;adivinapalabra[i]!='\0';i++)
			if(letrausuario[ultima_letra_usuario-1]==adivinapalabra[i] || letrausuario[ultima_letra_usuario-1]==adivinapalabra[i]-dif)
				Pregunta_fallo=0;
		
	return Pregunta_fallo;
}
int imprime_ahorcado(int intentos){
	if(intentos==7){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|\n|\n|\n|\n|\n|__\n");	
	}
	
	if(intentos==6){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|\n|\n|\n|\n|__\n");	
	}
	
	if(intentos==5){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|        |\n|\n|\n|\n|__\n");
	}
	
	if(intentos==4){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _| \n|       \n|\n|\n|__\n");
	}
																				
	if(intentos==3){																				 
	printf("Te quedan %d intentos\n\n", intentos);					 
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|       \n|\n|\n|__\n");
	}
				
	if(intentos==2){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        |\n|\n|\n|__\n");
	}
	
	if(intentos==1){
	printf("Te quedan %d intentos\n\n", intentos);
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        | \n|       |  \n|\n|__\n");
	}
	
	if(intentos==0){
				printf(" _______\n/        |\n|      (x_x)\n|       _|_ \n|        | \n|       | |\n|\n|__\n");
	printf("HAS PERDIDO :(\n");	
	return 1;
	}
	
	return 0;
}

void Puntuaciones(usuario lista_punt[D],FILE *leer_archivo){
	usuario aux;
	int i=0,j;
	
	while(fscanf(leer_archivo,"%[^.].%i\n",lista_punt[i].nombre,&lista_punt[i].punt)!=EOF)
		i++;
		
	for(i=0;lista_punt[i].punt!=0;i++)
		for(j=i+1;lista_punt[j].punt!=0;j++)
			if(lista_punt[i].punt<lista_punt[j].punt){
				aux=lista_punt[i];
				lista_punt[i]=lista_punt[j];
				lista_punt[j]=aux;
			}
						system("cls");
		printf("\t   Nombre \t Puntuacion");
		for(i=0;lista_punt[i].punt!=0&&i<10;i++)
			printf("\n\t%i- %s \t %i",i+1,lista_punt[i].nombre,lista_punt[i].punt);
}

void modoPrincipiante()
{
    int i, j;
    int a1[2], a2[2], a3[2], a4[2], a5[2], a6[2];
    int mesa[6][6];
    int mesaInicial[6][6];
    int py, px;
    int resultado = 0;
    int numIntentos=0;
    
    printf("Has elegido modo Principiante, por lo que tu mesa es 6x6:\n");
    
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
    a1[0]=rand()%6;
    a1[1]=rand()%6;
    
    do{
        a2[0]=rand()%6;
        a2[1]=rand()%6;
    }while(a2[0]==a1[0] && a2[1]==a1[1]);
    
    do{
        a3[0]=rand()%6;
        a3[1]=rand()%6;
    }while((a3[0]==a1[0] && a3[1]==a1[1]) || (a3[0]==a2[0] && a3[1]==a2[1]));
    
    do{
        a4[0]=rand()%6;
        a4[1]=rand()%6;
    }while((a4[0]==a1[0] && a4[1]==a1[1]) || (a4[0]==a2[0] && a4[1]==a2[1]) || (a4[0]==a3[0] && a4[1]==a3[1]));
    
    do{
        a5[0]=rand()%6;
        a5[1]=rand()%6;
    }while((a5[0]==a1[0] && a5[1]==a1[1]) || (a5[0]==a2[0] && a5[1]==a2[1]) || (a5[0]==a3[0] && a5[1]==a3[1]) || (a5[0]==a4[0] && a5[1]==a4[1]));
    
    do{
        a6[0]=rand()%6;
        a6[1]=rand()%6;
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

void modoExperto()
{
    int i, j;
    int a1[2], a2[2], a3[2], a4[2], a5[2], a6[2], a7[2], a8[2], a9[2];
    int mesa[9][9];
    int mesaInicial[9][9];
    int py, px;
    int resultado = 0;
    char m;
    int numIntentos=0;
    
    printf("Has elegido modo Experto, por lo que tu mesa es 9x9:\n");
    
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
    a1[0]=rand()%9;
    a1[1]=rand()%9;
    
    do{
        a2[0]=rand()%9;
        a2[1]=rand()%9;
    }while(a2[0]==a1[0] && a2[1]==a1[1]);
    
    do{
        a3[0]=rand()%9;
        a3[1]=rand()%9;
    }while((a3[0]==a1[0] && a3[1]==a1[1]) || (a3[0]==a2[0] && a3[1]==a2[1]));
    
    do{
        a4[0]=rand()%9;
        a4[1]=rand()%9;
    }while((a4[0]==a1[0] && a4[1]==a1[1]) || (a4[0]==a2[0] && a4[1]==a2[1]) || (a4[0]==a3[0] && a4[1]==a3[1]));
    
    do{
        a5[0]=rand()%9;
        a5[1]=rand()%9;
    }while((a5[0]==a1[0] && a5[1]==a1[1]) || (a5[0]==a2[0] && a5[1]==a2[1]) || (a5[0]==a3[0] && a5[1]==a3[1]) || (a5[0]==a4[0] && a5[1]==a4[1]));
    
    do{
        a6[0]=rand()%9;
        a6[1]=rand()%9;
    }while((a6[0]==a1[0] && a6[1]==a1[1]) || (a6[0]==a2[0] && a6[1]==a2[1]) || (a6[0]==a3[0] && a6[1]==a3[1]) || (a6[0]==a4[0] && a6[1]==a4[1]) || (a6[0]==a5[0] && a6[1]==a5[1]));
    
    do{
        a7[0]=rand()%9;
        a7[1]=rand()%9;
    }while((a7[0]==a1[0] && a7[1]==a1[1]) || (a7[0]==a2[0] && a7[1]==a2[1]) || (a7[0]==a3[0] && a7[1]==a3[1]) || (a7[0]==a4[0] && a7[1]==a4[1]) ||
    (a7[0]==a5[0] && a7[1]==a5[1]) || (a7[0]==a6[0] && a7[1]==a6[1]) );
    
    do{
        a8[0]=rand()%9;
        a8[1]=rand()%9;
    }while((a8[0]==a1[0] && a8[1]==a1[1]) || (a8[0]==a2[0] && a8[1]==a2[1]) || (a8[0]==a3[0] && a8[1]==a3[1]) || (a8[0]==a4[0] && a8[1]==a4[1]) ||
    (a8[0]==a5[0] && a8[1]==a5[1]) || (a8[0]==a6[0] && a8[1]==a6[1]) || (a8[0]==a7[0] && a8[1]==a7[1]));
    
    do{
        a9[0]=rand()%9;
        a9[1]=rand()%9;
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
                    printf("%i ", mesaInicial[i][j]);
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
        i=rand() % 3;
        j=rand() % 3;
        
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

