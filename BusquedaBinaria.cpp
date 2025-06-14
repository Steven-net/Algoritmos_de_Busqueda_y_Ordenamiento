// ALGORITMO DE BUSQUEDA "BUSQUEDA BINARIA"
// busqueda binaria: primeramente debemos tener el arreglo ordenado, este algoritmo 
// trata de buscar el valor en tu arreglo  agarrando el elemento del medio como referencia 
// y si es menor entonces este realiza lo mismo con el arreglo de la izquierda en caso contrario
// analiza el de la derecha hasta que el elemento medio sea igual al valor.

#include <iostream>
#include <algorithm>
using namespace std;

int BusqBinaria(int arr[], int n, int valor){
    int inicio = 0;
    int fin = n-1;
    int medio;

    while(inicio<=fin){
        medio = inicio + (fin-inicio)/2; // toma el valor medio del arreglo
        if(arr[medio] == valor){
            return medio; // retorna el valor medio si es igual al valor deseado
        }else if(arr[medio] < valor){
            inicio = medio +1; // vuelve a analizar pero ahora toma como otro valor de inicio y medio
        }else
            fin = medio -1;// vuelve a analizar pero toma otro valor de medio y de final
    }

    return -1; // si el valor no se encuentra en el arreglo se retorna -1
}
