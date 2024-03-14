#include<iostream>

using namespace std;

struct nodo{
	int dato;
	nodo *siguiente;
}*ultimo;

void insertar(int n,nodo *&lista);
void mostrar(nodo *&lista);
int sumaTotal(nodo *&lista);
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
	cout<<"\nSuma total: "<<sumaTotal(lista);
	
	
	return 0;
}

void insertar(int n,nodo *&lista){
	
	nodo *nuevoNodo=new nodo();
	nuevoNodo->dato=n;
	nodo *aux1=lista;
	nodo *aux2;
	
	if(lista==NULL){
		ultimo=nuevoNodo;
		ultimo->siguiente=nuevoNodo;
	}
	else{
		nuevoNodo->siguiente=aux1;
		ultimo->siguiente=nuevoNodo;
		
	}
	
	lista=nuevoNodo;
	
	
	
}

void mostrar(nodo *&lista){
	bool entro=false;
	nodo *buscar = lista;
	bool inicio;
	if(buscar->siguiente!=buscar){
		entro=true;
	}
	cout<<buscar->dato<<" -> ";
	buscar=buscar->siguiente;

	while(buscar!=ultimo){
		
		cout<<buscar->dato<<" -> ";		
		buscar=buscar->siguiente;	
			
	}
	if(entro){
		cout<<buscar->dato<<endl;//mostrando el ultimo
	}

	

}

int sumaTotal(nodo *&lista){
	int suma=0;
	nodo *aux=lista;
	bool entro=false;
	
	if(aux->siguiente!=aux){
		entro=true;
	}
	suma=aux->dato;
	aux=aux->siguiente;
	
	while(aux!=ultimo){		
		suma+=aux->dato;
		aux=aux->siguiente;
		entro=true;
	}
	if(entro){
		suma+=aux->dato;//sumando el ultimo
	}
	
	return suma;
}

