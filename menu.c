#include <stdio.h>
int main()
{
	char opcion;
	printf("Selecciona juego: \n Pong(p)\n Ahorcado(a)\n Tres en ralla(t)\n Buscaminas(b)\n Hundir la flota(h)\n Salir(s)\n");
	do
	{
		scanf("%c",&opcion);
		switch(opcion)
		{
			case 'p':
				break;
			case 'a':
				break;
			case 't':
				break;
			case 'b':
				break;
			case 'h':
				break;
		}
	}
	while(opcion!='s');

	return 0;
}
