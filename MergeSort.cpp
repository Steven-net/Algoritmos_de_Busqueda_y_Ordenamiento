// ALGORITMO DE ORDENAMIENTO "MERGE SORT"
// MergeSort: divide el arreglo recursivamente en dos mitades de forma 
// dependiente y luego las fuciona con el orden correcto

#include <iostream>
using namespace std;

void merge(int arr, int inicio,int mitad, int final){
    int i,j,k;
    int elemIzq = mitad - inicio - 1; // Limite del arreglo Izquierda
    int elemDer = final - mitad; // Limite del arreglo Derecha

    int izquierda[elemIzq];
    int derecha[elemDer];

    for(int i = 0; i<elemDer; i++)
        derecha[i] = arr[mitad + 1 + i];
    for(int j = 0; j<elemIzq; j++)
        izquierda[j] = arr[inicio + i];

    i = 0; j = 0; k = inicio;

    // Se ordena de manera creciente nuevamennte en el arreglo principal.

    while(i < elemIzq && j < elemDer){
        if(izquierda[i] <= derecha[j]){
            arr[k]= izquierda[i];
            i++;
        }else{
            arr[k] = derecha[j];
            j++;
        }
        k++;
    }
    
    // En caso quede elementos, se pasaran para los ultimos elementos 
    // ya que se supone que son mayores a los que ya se arreglo anteriormente
    
    while(j < elemDer){
        arr[k] = derecha[j];
        j++;
        k++;
    }
    while(i < elemIzq){
        arr[k] = izquierda[i];
        i++;
        k++;
    }
}

// Funcion recursiva que divide en dos hasta tener un arreglo unitario
// y luego ordenandolo de forma ordenada

void MergeSort(int arr, int inicio, int final){
    if(inicio < final){
        int mitad = inicio +(final - inicio)/2;
        MergeSort(arr, mitad +1, final);
        MergeSort(arr, inicio, mitad);
        merge(arr, inicio, mitad,final);
    }
}
