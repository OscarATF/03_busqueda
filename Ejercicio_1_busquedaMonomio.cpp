#include <iostream>
using namespace std;

struct monomio{
	float exp;
	float coef;
};

int secuencialDes(monomio[],int,monomio);

int main() {
	
	int n,pos;
	const int tam=50;
	monomio ter[tam],dato;
	
	cout<<"Se pide leer un monomio y buscar si forma parte del polinomio. Usa busqueda secuencial"<<endl;
	cout<<"Ingrese la cantidad de terminos del polinomio: "; cin>>n;
	
	for (int i=0;i<n;i++) {
		cout<<endl;
		cout<<"Ingrese el coeficiente "<<i+1<<" : "; cin>>ter[i].coef;
		cout<<"Ingrese el exponente "<<i+1<<" : "; cin>>ter[i].exp;
	}
	
	cout<<endl;
	cout<<"POLINOMIO"<<endl;
	for (int i=0;i<n;i++) {
		cout<<ter[i].coef<<"x^"<<ter[i].exp;
		if (i!=n-1) {
			cout<<" + ";
		}
	}
	
	cout<<endl;
	cout<<"\nIngrese el monomio que quiere buscar "<<endl;
	cout<<"Ingrese el coeficiente: "; cin>>dato.coef;
	cout<<"Ingrese el exponente: "; cin>>dato.exp;
	cout<<endl;
	pos=secuencialDes(ter,n,dato);
	if (pos!=-1) {
		cout<<"Monomio encontrado en el indice: "<<secuencialDes(ter,n,dato);
	} else {
		cout<<"El monomio no ha sido encontrado"<<endl;
	}
	
}

//Busqueda secuencial desordenada
int secuencialDes(monomio t[],int n,monomio x) {
	int pos=-1;
	int i=0;
	while (i<n && (t[i].coef!=x.coef || t[i].exp!=x.exp)) {
		i++;
	}
	if (i<n) {
		pos=i;
	}
	return pos;
}