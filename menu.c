#include <stdio.h>
int main()
{
	int opcion;
	printf("Selecciona juego: \n 1.Pong\n 2.Ahorcado\n 3.Tres en ralla\n 4.Buscaminas\n 5.Hundir la flota\n 6.Snake\n 7.Salir\n");
	do
	{
		scanf("%i",&opcion);
		switch(opcion)
		{
			case '1':
//inicia el juego del pong 
				break;
			case '2':

//inicia el juego del ahorcado

				break;
			case '3':
//inicia el juego del tres en ralla
				break;
			case '4':

//inicia el juego del buscaminas

				break;
			case '5':

//inicia el juego de hundir la flota

				break;
			case '6':

//inicia el juego del snake

				break;
		}
	}
	while(opcion!='7');

	return 0;
}
