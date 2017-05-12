#include <stdio.h>
#include <stdlib.h>

typedef struct Info{
	int valor;
}info;

typedef struct Nodo{
	info *ptrInfo;
	struct Nodo *izq;
	struct Nodo *der;
}nodo;

info *crearInfo(int num)
{
	info *newInfo;
	if(newInfo=(info*)malloc(sizeof(info))){
		newInfo->valor=num;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newInfo;
	free(newInfo);
}
nodo *crearNodo(int val){
	nodo *newNodo;
	info *dato=crearInfo(val);
	if(newNodo=(nodo*)malloc(sizeof(nodo))){
		newNodo->ptrInfo=dato;
		newNodo->izq=newNodo->der=NULL;
	}else{
		printf("\nError, memoria no asignada");
	}
	return newNodo;
	free(newNodo);
}
nodo *insertar(nodo *nodoI,int dato){
	if(nodoI==NULL){
		return crearNodo(dato);
	}else if (dato< nodoI->ptrInfo->valor){
				nodoI->izq=insertar(nodoI->izq,dato);
	}else if(dato>nodoI->ptrInfo->valor){
		nodoI->der=insertar(nodoI->der,dato);
		return nodoI;
	}
}
void preOrden(nodo *nodoPre){
	if(nodoPre!=NULL){
		printf("\n%d",nodoPre->ptrInfo->valor);
		preOrden(nodoPre->izq);
		preOrden(nodoPre->der);
	}
}
void inOrden(nodo *nodoIn){
	if(nodoIn!=NULL){
		inOrden(nodoIn->izq);
		printf("\n%d",nodoIn->ptrInfo->valor);
		inOrden(nodoIn->der);
	}
}
void postOrden(nodo *nodoPos){
	if(nodoPos!=NULL){
		postOrden(nodoPos->izq);
		postOrden(nodoPos->der);
		printf("\n%d",nodoPos->ptrInfo->valor);
	}
}
nodo *buscar(nodo *nodoB,int vBuscar){
	if(nodoB==NULL){
		return NULL;
	}else if(vBuscar<nodoB->ptrInfo->valor){
		return buscar(nodoB->izq,vBuscar);
	}else if(vBuscar>nodoB->ptrInfo->valor){
		return buscar(nodoB->der,vBuscar);
	}else{
		return nodoB;
	}
}

int alturaAB(nodo *arbol){
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}

int Profundidad(nodo *t)
{
 int izq=0, der = 0;
 if(t==NULL) return 0; 
 if(t->izq != NULL) izq = Profundidad(t->izq); 
 if(t->der != NULL) der = Profundidad(t->der); 
 if( izq > der) 
 return izq+1; 
 else
 return der+1; 
}


int contarHojas(nodo *arbol){
        if (arbol==NULL)
        {
                return 0;
        }
        if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
        {
        	return 1;
        }
        else
        {
        	return contarHojas(arbol->izq) + contarHojas(arbol->der);
        }
}
int calcularPeso(nodo *subArbol)
{
	if(subArbol==NULL)
		return 0;
	
	else
		return 1+calcularPeso(subArbol->izq)+calcularPeso(subArbol->der);
}

int Suma_nodos(nodo *subArbol)
{
	if(subArbol==NULL){
		return 0;
	
	}else{

		return subArbol->ptrInfo->valor + Suma_nodos(subArbol->der) + Suma_nodos(subArbol->izq);
	}
}