//escriba un programa que calcule en forma recursiva una matriz Anxn. Los elementos aij sobre la  diagonal de A son nulos
//y los elementos restantes se forman de la suma ai-1 j-1 + ai-1 j. ejemplo de salida:
/* 1 0 0 0 0
   1 1 0 0 0
   1 2 1 0 0
   1 3 3 1 0
   1 4 6 4 1     */

#include <iostream>
using namespace std;

const int n = 100;

int Calcular(int i, int j, int A[n][n]){

    if(i == 0 && j ==0) { return 1;}
    if(j < 0 || j > i) {return 0;}

    if(A[i][j] == 0){
        A[i][j] = Calcular(i-1,j-1,A) + Calcular(i-1,j,A);
    }
    return A[i][j];

}

void GeneradorMat(int len, int A[n][n]){
    for(int i =0; i<len; i++){
        for(int j=0; j<len; j++){
            A[i][j] = 0;
        }
    }

    A[0][0] = 1;
    A[len-1][len-1] = 1;

    for(int i=0; i<len;i++){
        for(int j = 0; j<i; j++){
            Calcular(i,j,A);
        }
    }

}

void Print(int len, int A[n][n]){
    for(int i = 0; i<len; i++){
        for(int j =0; j<len;j++){
            cout << A[i][j]<< "   ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int Mat[n][n];
    int lon;

    cout << "Ingrese el tamaño de la matriz: ";
    cin >> lon;

    GeneradorMat(lon,Mat);
    Print(lon,Mat);

    return 0;
}