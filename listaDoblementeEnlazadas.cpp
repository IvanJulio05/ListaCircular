#include <iostream>
#include<stdlib.h>

using namespace std;


struct nodo{
int dato;
nodo *siguiente;
nodo *anterior;
}*ultimo;

void insertar(int n,nodo *&lista);
void mostrar(nodo *&lista);
void mostrar_inverso();

int main(){

nodo *lista=NULL;
int dato;
string opcion;
do{
cout<<"Digite un numero: ";cin>>dato;
insertar(dato,lista);
cout<<"seguir[1], salir[0]: ";cin>>opcion;
system("cls");
}while(opcion!="0");

cout<<"\t\nLISTA CIRCULAR"<<endl;
mostrar(lista);
//mostrar_inverso();


system("pause");
return 0;
}




void insertar(int n,nodo *&lista){

nodo *nuevoNodo=new nodo();
nuevoNodo->dato=n;
nuevoNodo->anterior=NULL;

nodo *aux1=lista;

lista=nuevoNodo;
if(aux1 == NULL){
	ultimo=lista;
}
nuevoNodo->siguiente=aux1;
if(aux1!=NULL){
aux1->anterior=nuevoNodo;
}



}

void mostrar(nodo *&lista){

nodo *aux=lista;
while(aux != NULL){

cout<<aux->dato<<"-->";
aux=aux->siguiente;


}


cout<<"Null"<<endl;

}

void mostrar_inverso(){
	nodo *aux=ultimo;
	while(aux != NULL){

	cout<<aux->dato<<"-->";
	aux=aux->anterior;


	}

cout<<"Null"<<endl;
}
