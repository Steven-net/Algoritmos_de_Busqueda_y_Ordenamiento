// ALGORITMO DE ORDENAMIENTO "QUICK SORT"
// quick sort: selecciona un pivote el cual tomara como referencia, se pondra a izquierda
//a los elementos mayores al pivote y a la derecha a los menores quedandose en el medio 
// el elemento pivote, recursivamente se aplica en ambos lados hasta tener el arreglo ordenado

#include <iostream>
#include <algorithm>
using namespace std;

int particion(int arr[],int inicio, int fin, int pivote){
	int indpiv = inicio; // indice en donde se pondra el siguiente numero menor al pivote
	for(int i = inicio; i<fin; i++){
		if(arr[i] < pivote){
			swap(arr[i], arr[indpiv]); 
            indpiv++;
        }
    }
    //al terminar el buble el pivote estara en arr[fin], este se movera a la posicion indpiv
    swap(arr[indpiv], arr[fin]);

    //devuelve la posicion final del pivote, que ya esta ordenado
    return indpiv;
}


void QuickSort(int arr[], int inicio, int fin){

    // se pone la condicion para que trabaje cuando tiene almenos dos elementos
	if(inicio<fin){
        //el pivote se puede elijir arbitrariamente pero si lo elijes mal podria traerte problemas
		int pivote = arr[fin]; //usa el ultimo elemento como pivote

		int indpiv = particion(arr,inicio,fin,pivote);

        // se aplica recursividad para que se haga lo mismo en ambos lados del pivote
        //y asi tener el arreglo ordenado 
        // RECORDEMOS: este se va a detener cuando halla menos de 2 elementos en el arreglo a analizar
		QuickSort(arr[],inicio,indpiv -1);
		QuickSort(arr[],indpiv + 1,fin);
	}
}
