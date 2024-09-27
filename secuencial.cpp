#include <iostream>
using namespace std;

int secuencialDes(int[],int,int);
int secuencialOrd(int[],int,int);
void interDirDer(int[],int);
void imprimirArreglo(int[],int);
int secuencialOrd(int[],int,int);

int main() {
	int n,op,dato;
	cout<<"\tMETODOS DE BUSQUEDA\n"<<endl;
	cout<<"Ingrese la capacidad del arreglo: "; cin>>n;
	int arreglo[n];
	for (int i=0;i<n;i++) {
		cout<<"Ingrese el elemento "<<i+1<<" : "; cin>>arreglo[i];
	}
	cout<<"Ingrese el dato que quiere buscar: "; cin>>dato;
	cout<<endl;
	
		cout<<"\nMetodos de Busqueda"<<endl
			<<"1. Busqueda secuencial desordenada"<<endl
			<<"2. Busqueda secuencial ordenada"<<endl
			<<"3. Salir del programa"<<endl;
		cout<<"\nIngrese una opcion: "; cin>>op;
		cout<<endl;
		switch (op) {
			case 1:
				if (secuencialDes(arreglo,n,dato)!=-1) {
					cout<<"Resultado de la busqueda indice: ";
					cout<<secuencialDes(arreglo,n,dato);
				} else {
					cout<<"No se encontro el dato";
				}
				break;
			case 2:
				interDirDer(arreglo,n-1);
				imprimirArreglo(arreglo,n);
				cout<<"\nResultado de la busqueda indice: ";
				cout<<secuencialOrd(arreglo,n,dato);
				break;
			case 3:
				return 0;
				break;
			default:
				cout<<"\nIngrese una opcion valida\n"<<endl;
		} 
}

//Busqueda secuencial desordenada
int secuencialDes(int A[],int n,int dato) {
	int pos=-1;
	int i=0;
	while (i<n && A[i]!=dato) {
		i++;
	}
	if (i<n) {
		pos=i;
	}
	return pos;
}

//Intercambio Directo Derecha
void interDirDer(int arr[],int n) {
	int aux;
	for (int i=0;i<n;i++) {
		for (int j=0;j<n-i;j++) {
			if(arr[j]>arr[j+1]) {
				aux=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=aux;
			}	
		}
	}
}

//busqueda secuencial ordenada
int secuencialOrd(int A[],int n,int dato) {
	int i=0;
	int pos;
	while (i<n && A[i]<dato) {
		i++;
	}
	if (i>n-1 || A[i]>dato) {
		pos=-i;
	} else {
		pos=i;
	}
	return pos;
}

//Imprimir los elementos del arreglo ordenado
void imprimirArreglo(int arr[],int n) {
	cout<<"Elementos del arreglo ordenado: ";
	for (int i=0;i<n;i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
