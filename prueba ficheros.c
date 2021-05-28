#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
	char a[200];
}instr;
void vaciar(char temp[]);
void copiar(char temp[], int i, instr p[]);
int main()
{
	instr *p;
	int cont=0;
	char temp[100];
	char aux;
	int i,j;
	FILE *pf;
	pf=fopen("Instrucciones.txt","r");
	if(pf==NULL)
	{
		printf("No se ha padido abrir el fichero\n");
		exit(-1);
	}
	while(!feof(pf))
	{
		fgets(temp,100,pf);
		cont++;
	}
	rewind(pf);
	p=(instr*)malloc(cont*sizeof(instr));
	if(p==NULL)
	{
		printf("No se ha podido reservar memoria\n");
		exit(-1);
	}
	for(i=0;!feof(pf);i++)
	{
		vaciar(temp);
		aux='O';
		for(j=0;aux!='\n';j++)
		{
			aux=fgetc(pf);
			if(aux!='\n')
			{
				temp[j]=aux;
			}
		}
		copiar(temp,i,p);
		fclose(pf);
		printf("Instrucciones: %s \n",p[i].a);
	}
}
void vaciar(char temp[])
{
	int i;
	for(i=0;i<100;i++)
	{
		temp[i]='\0';
	}
}
void copiar(char temp[], int i, instr p[])
{

	strcpy(p[i].a,temp);
}
