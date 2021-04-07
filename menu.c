#include <stdio.h>
int main()
{
	char opcion;
	printf("Selecciona juego: pong(p)\n ahorcado(a)\n tres en ralla(t)\n buscaminas(b)\n hundir la flota(h)\n salir(s)");
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
			case 'h';
				break;
		}
	}
	while(opcion!='s');
}
