#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main() {

	srand(time(NULL));
	
	char palabras[][30] = {
		
		"coche", 
		"moto",
		"bicicleta",
		"musica",
		"esfuerzo",
		"cuaderno",
		"bloquear",
		"regla",
		"atletismo",
		"molecular",
		"respuesta",
		"armario",
		"altavoz",
		"botella",
		"galleta",
		"mapamundi",
		"tornado",
		"autobus",
		"pantalla",
		"cuaderno",
		"pincel",
		"soplete",
		"bombero",
		"edificio",
		"manguera",
		"zapatillas",
		"microfono",
		"artista",
		"libreria",
		"lavadora",
		"platano",
		"manzana",
		"zanahoria",
		"cartera",
		"tarjeta",
		"pintura",
		"monedero",
		"moneda",
		"hospital",
		"medico",
		"auriculares",
		"mochila",
		"camiseta",
		"pantalones",
		"profesor",
		"informatica",
		"galleta",
		"comida",
		"cargador",
		"habitacion",
		"estanteria",
		"esternocleidomastoideo",
		"otorrinolaringologo",
		"desoxirribonucleico",
		"hipopotamo",
		"estimulacion",
		"contractura",
		"fisioterapeuta",
		"juvenil",
		"retraso",
			
	};
	
	// para palabra aleatoria
	int azar = rand() % 60;
	
	int vidas = 5;
	int numAciertos = 0;
	int segCorrecta = 0;
	
	int longitud = strlen(palabras[azar]);
	
	
	int palabraoculta[30] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int i=0;
	int salir = 0;	
	
	int bucle = 0;
	int preadivinada = 0;
	
	char adivina[30];
	char letraintro;	
	
    // bucle del juego	
	while ( numAciertos < longitud ) {
		
		printf("\nNUEVO TURNO!!");
		printf("\n\nEscribe ''salir'' para abandonar la partida");
		printf("\nNumero de vidas: %i",vidas);
		printf("\nPalabra oculta: ");
		
		for( bucle = 0; bucle < longitud; bucle++) {
		
			if(palabraoculta[bucle] == 1) {
				printf("%c",palabras[azar][bucle]);	
							
			} else {
				printf("-");
			}
		
		}	
		
		printf("\n");
	
		printf("Numero de Aciertos:%d\n",numAciertos);
		printf("Introduce una letra:");
		//scanf("%c",&adivina);
		
		fgets(adivina, 16, stdin);
		//fflush(stdin);
		

		
		if( strncmp(adivina, "salir", 4) == 0) {
			salir = 1;
			break;
		}
		
		letraintro = adivina[0];
		preadivinada = 0; 
		system("cls");
		
		printf("\nLetra Introducida:%c\n",letraintro);
		
		
		segCorrecta = numAciertos;
		
		for( bucle = 0; bucle < longitud; bucle++) {
		
			if(palabraoculta[bucle] == 1) {
				
				if(palabras[azar][bucle] == letraintro) {
					preadivinada = 1; 
					break;
				} 
				//continue;
			}
		
			if( letraintro == palabras[azar][bucle] ) {
				palabraoculta[bucle] = 1;
				numAciertos++;				
			}		
		
		}	
		
		if( segCorrecta == numAciertos && preadivinada == 0) {
			vidas--;
			printf("Lo siento, no es correcta\n");
			
			if (vidas == 0) {
				break;
			}
			
		} else if( preadivinada == 1) {
			printf("Ya adivinada!!\n");
			
		} else {
			printf("Es correcta!! :)\n");
		}
		
	}
	
	if( salir == 1 ) {	
		printf("\nHas abandonado la partida\n");
		
	} else if (vidas == 0) {
		printf("\nLo siento has perdido, la palabra era: %s\n",
		palabras[azar]);	
		
	} else  {	
		printf("\nHAS GANADO!!! :)\n");
	} 
	
		
	return 0;
}

