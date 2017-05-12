#include <stdio.h>
#include <stdlib.h>
#include "funcarbol.h"
int main(int argc, char const *argv[])
{
	nodo *raiz= NULL;
	nodo *temp;
	int datos[]={1,9,3,10,5,6,7,11,2,4},i,numB,peso;
	for (i=0;i<10;i++)
	{
		raiz = insertar(raiz,datos[i]);
	}
	printf("Recorrido pre-orden :");
	preOrden(raiz);
	printf("\nRecorrido in-orden :\n");
	inOrden(raiz);	
	printf("\nRecorrido post-orden :\n");
	postOrden(raiz);
	printf("\nIngrese un elemento para buscarlo en el arbol: \n");
	scanf("%d",&numB);
	temp=buscar(raiz,numB);
	if(temp==NULL)
		{
		printf("El elemento NO esta el arbol\n");
		}
	else{
		printf("El elemento SI esta en el arbol\n");
	}
	int profu=Profundidad(raiz);
	printf("\nProfundidad del arbol es: %d \n",profu);
	int altura=alturaAB(raiz);
	printf("\nAltura del arbol es: %d \n",altura);
	peso=calcularPeso(raiz);
	printf("\nPeso del arbol es: %d \n",peso);
	int hojas=contarHojas(raiz);
	printf("\nCantidad de  hojas: %d \n",hojas);
	int sumaN=Suma_nodos(raiz);
	printf("\nSuma de todos los nodos es: %d \n",sumaN);
	
	return 0;
}