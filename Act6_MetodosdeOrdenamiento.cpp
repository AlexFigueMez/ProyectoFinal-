#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
const int tamano_arreglo=50;
using namespace std;
//Declaracion de funciones:
void OrdenamientoBurbuja(int [], int);
void OrdenamientoShakeSort(int [],int);
void OrdenamientoInsercionDirecta(int [], int);
void OrdenamientoInsercionBinaria(int [],int);
void OrdenamientoSeleccionDirecta (int [], int);
void Imprimir(int [], int);

//Implementacion de funciones:
void Imprimir(int arreglo[], int n){
cout<<"ARREGLO ORDENADO: "<<endl;
for (int i=0;i<n;i++){
    cout<<"[ "<<arreglo[i]<<" ]";
}
}

void OrdenamientoBurbuja(int arreglo[],int n){
int i,j,aux;
bool flag = true;
for(i=1;i<=n&&flag==true;i++){
        flag=false;
        for (j=n;j>=i;j--){
            if (arreglo[j-1]>arreglo[j]){
                flag=true;
                aux=arreglo[j-1];
                arreglo[j-1] = arreglo [j];
                arreglo[j] = aux;
                }
        }

}
}

void OrdenamientoShakeSort(int arreglo[], int n){
int i = 0 , izq = 1 , der = n-1 , k = n-1 , aux = 0;
 while( der >= izq ){
  for( i = der ; i>= izq ; i-- )
   if( arreglo[i-1] > arreglo[i]){
    aux = arreglo[i-1];
    arreglo[i-1]=arreglo[i];
    arreglo[i]=aux;
    k=i;
   }
   izq = k + 1;
   for( i = izq ; i <= der ; i++)
    if( arreglo[i-1] > arreglo[i] ){
     aux = arreglo[i-1];
     arreglo[i-1]=arreglo[i];
     arreglo[i]=aux;
     k=i;
   }
    der = k-1;
 }
}

void OrdenamientoInsercionDirecta(int arreglo[],int n){
int i,j,aux;
for (i=0;i<=n-1;i++){
    aux=arreglo[i];
    j=i-1;
    while(j>=0&&aux<arreglo[j]){
        arreglo[j+1]=arreglo[j];
        j=j-1;
    }
    arreglo[j+1]=aux;
}
}

void OrdenamientoInsercionBinaria(int arreglo[],int n){
int i,j,aux,izq,der,m;
for (i=0;i<n;i++){
    aux=arreglo[i];
    izq=0;
    der=i-1;
    while (izq<=der){
        m=((izq+der)/2);
        if (aux<arreglo[m])
            der=m-1;
        else
            izq=m+1;
    }
    j=i-1;
    while(j>=izq){
        arreglo[j+1]=arreglo[j];
        j=j-1;
    }
}
}

void OrdenamientoSeleccionDirecta(int arreglo[], int n){
int k,menor,i,j;
for (i=0;i<n;i++){
    menor=arreglo[i];
    k=i;
    for(j=i+1;j<n;j++){
        if (arreglo[j]<menor){
            menor=arreglo[j];
            k=j;
        }
    }
arreglo[k]=arreglo[i];
arreglo[i]=menor;
}

}

int main(){
int arreglo[tamano_arreglo];
srand(time(0));
for (int i=0;i<tamano_arreglo;i++)
arreglo[i]=1+rand()%500;

int opc;
    do{
cout<<"MENU DE OPCIONES"<<endl<<endl;
cout<<"1.  Intercambio directo (BURBUJA CON BANDERA)"<<endl<<endl;
cout<<"2.  Sacudida (shake sort)"<<endl<<endl;
cout<<"3.  Insercion directa"<<endl<<endl;
cout<<"4.  Insercion Binaria"<<endl<<endl;
cout<<"5.  Seleccion Directa"<<endl<<endl;
cout<<"6.  Salir"<<endl;
cout<<"Opcion------>";
cin>>opc;
switch (opc){
case 1:
    clock_t t;
    t=clock();
    cout<<"Ordenamiento Burbuja: "<<endl;
    OrdenamientoBurbuja(arreglo,tamano_arreglo);
    Imprimir(arreglo,tamano_arreglo);
    t=clock()-t;
    cout<<"\t\t\t\t\t\t\t";
    cout<<"El tiempo de ejecucion fue de: "<<float(t)/CLOCKS_PER_SEC<<"s";
    system("pause");
    break;
case 2:

    t=clock();
    cout<<"Ordenamiento sacudida: "<<endl;
    OrdenamientoShakeSort(arreglo,tamano_arreglo);
    Imprimir(arreglo,tamano_arreglo);
    t=clock()-t;
    cout<<"\t\t\t\t\t\t\t";
    cout<<"El tiempo de ejecucion fue de: "<<float(t)/CLOCKS_PER_SEC<<"s";
    system("pause");
    break;
case 3:

    t=clock();
    cout<<"Ordenamiento por insercion directa: "<<endl;
    OrdenamientoInsercionDirecta(arreglo,tamano_arreglo);
    Imprimir(arreglo,tamano_arreglo);
    cout<<"\t\t\t\t\t\t\t";
    cout<<"El tiempo de ejecucion fue de: "<<float(t)/CLOCKS_PER_SEC<<"s";
    system("pause");
    break;
case 4:

    t=clock();
    cout<<"Ordenamiento por insercion binaria: "<<endl;
    OrdenamientoInsercionBinaria(arreglo,tamano_arreglo);
    Imprimir(arreglo,tamano_arreglo);
    cout<<"\t\t\t\t\t\t\t";
    cout<<"El tiempo de ejecucion fue de: "<<float(t)/CLOCKS_PER_SEC<<"s";
    system("pause");
    break;
case 5:

    t=clock();
    cout<<"Ordenamiento por seleccion directa: "<<endl;
    OrdenamientoSeleccionDirecta(arreglo,tamano_arreglo);
    Imprimir(arreglo,tamano_arreglo);
    cout<<"\t\t\t\t\t\t\t";
    cout<<"El tiempo de ejecucion fue de: "<<float(t)/CLOCKS_PER_SEC<<"s";
    system("pause");
    break;

    case 6: default:
return 0;
break;
}
system("cls");
}while(opc!=6);
}
