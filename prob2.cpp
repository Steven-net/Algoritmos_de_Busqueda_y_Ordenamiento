/*Ingrese por teclado una lista de numeros diferentes(maximo 30) de tal forma que la lista
tenga en los indices pares una secuencia ascendente y en los indices impares otra secuencia
ordenada en forma descendente. Implemente el metodo de busqueda binaria que permita encontrar 
el indice de un numero buscado en dicha lista*/

#include <iostream>
#include <algorithm>
using namespace std;

void Ordenamiento(int arr[], int n){
    int pares[100] = {};
    int impares[100] = {};
    int I =0, P =0;

    for(int i =0; i < n; i++){
        if(i%2 == 0){
            pares[P] = arr[i];
            P++;
        }else{
            impares[I] = arr[i];
            I++;
        }
    }
    
    //ordenamiento ascendente para los pares
    for(int i =0; i<P; i++){
        for(int j=0; j<P - i - 1; j++){
            if(pares[j] > pares[j+1]){
                swap(pares[j],pares[j+1]);
            }
        }
    }

    //ordenamiento descendente para los impares
    for(int i =0; i<I; i++){
        for(int j=0; j<I - i - 1; j++){
            if(impares[j] < impares[j+1]){
                swap(impares[j],impares[j+1]);
            }
        }
    }

    int i=0, j=0,k=0;

    while(i<P && j<I){
        if(k%2 ==0){
            arr[k] = pares[i];
            i++;
        }else{
            arr[k] = impares[j];
            j++;
        }
        k++;
    }
    while(i < P){
        arr[k] = pares[i];
        i++;
        k++;
    }

    while(j < I){
        arr[k] = impares[j];
        j++;
        k++;
    }
}

int BusqueBinaria(int arr[], int n, int valor){
    int inicio= 0;
    int fin = n-1;
    int medio;

    while(inicio <= fin){
        medio = inicio + (fin-inicio)/2;
        if(arr[medio] == valor){
            return medio;
        }else if(arr[medio] < valor){
            inicio = medio +1;
        }else   
            fin = medio -1;
    }

    return -1; //si no encuentra el valor en el arreglo retorna -1
}

void print(int arr[], int n){
    for(int i =0; i<n;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main(){
    int arr[30];
    int valor;
    int n;

    cout << "Ingrese el tamañño del arreglo: ";
    cin >> n;

    for(int i =0; i<n; i++){
        cout << "Ingrese el "<<i<<" elemento: ";
        cin >> arr[i];
    }
    print(arr,n);
    Ordenamiento(arr,n);

    cout << "El arreglo ordenado segun lo pedido: "<<endl;
    print(arr,n);

    cout << "Ingrese el valor que quiere encontrar: ";
    cin >> valor;

    int posicion = BusqueBinaria(arr,n,valor);

    if(posicion == -1){
        cout << "El valor no se encuentra en el arreglo"<<endl;
    }else
        cout << "El valor esta en la "<<posicion<<" posicion del arreglo ordenado"<<endl;

    return 0;
}