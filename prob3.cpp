/*Dado dos arreglos arr1[] y arr2[] de numeros enteros ordenados de forma ascendente, cuyos tamaños son n1 y n2 respectivamente
(tamaño maximo 20). Escribe un funcion llamada mezcla que fusione ambos arreglos en un solo arreglo ordenado. Ejemplo:
Entrada:
arr1[]={1,4,6,9}
arr2[]={2,3,7,8,10}
Salida:
arr[]{1,2,3,4,7,8,9,10}     */

#include <iostream>
#include <algorithm>
using namespace std;

void Burbuja(int arr[], int n){
    for(int i =0; i < n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void Mezclar(int arr[],int arr1[], int arr2[], int n1, int n2){
    
    int i=0, j=0, k=0;

    while(i< n1 && j<n2){
        if(arr1[i] < arr2[j]){
            arr[k] = arr1[i];
            i++;
        }else{
            arr[k] = arr2[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = arr1[i];
        k++;
        i++;
    }

    while(j<n2){
        arr[k] = arr2[j];
        k++;
        j++;
    }

}

void print(int arr[], int n){
    for(int i =0; i<n;i++){
        cout << arr[i]<<" ";
    }
    cout << endl;
}

int main(){
    int arr1[20];
    int arr2[20];
    int arr[40];
    int n1,n2;

    cout << "Ingrese el tamaño del primer arreglo: ";
    cin >> n1;
    cout << "Ingrese el tamaño del segundo arreglo: ";
    cin >> n2;

    for(int i =0; i<n1; i++){
        cout << "Arr["<<i<<"]: ";
        cin >> arr1[i];
    }
    
    for(int i =0; i<n2; i++){
        cout << "Arr["<<i<<"]: ";
        cin >> arr2[i];
    }

    cout << "Arreglo 1: "<<endl;
    print(arr1,n1);
    cout << "Arreglo 2:"<<endl;
    print(arr2,n2);

    Burbuja(arr1,n1);
    Burbuja(arr2,n2);

    Mezclar(arr,arr1,arr2,n1,n2);
    
    cout << "Arreglo 1+2: "<<endl;
    print(arr,n1+n2);

    return 0;
}
