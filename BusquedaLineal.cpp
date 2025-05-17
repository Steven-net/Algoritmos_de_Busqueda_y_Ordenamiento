//ALGORITMO DE BUSQUEDA "BUSQUEDA LINEAL"
// busqueda binaria: este se recorre todo el arreglo comparando si es igual al valor buscado
// y si no se encuentra retorna -1

#include <iostream>
using namespace std;

int BusqLineal(int arr[], int n, int valor){

    for(int i = 0; i<n ; i++){

        if(arr[i] == valor)
            return i;

    }

    return -1; // retorna -1 si el el valor no se encuentra en el arreglo
}