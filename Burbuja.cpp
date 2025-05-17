//ALGORITMO DE ORDENAMIENTO "ORDENAMIENTO DE BURBUJA"
// ordenamiento de burbuja: este se encarga de comparar dos vectores consecutivos
// y los ordena de manera creciente

#include <iostream>
#include <algorithm> // para el uso de swap()
using namespace std;

void Burbuja(int arr[], int n){
    for(int i=0; i< n-1; i++){
        for(int j=0; j<n-j-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}