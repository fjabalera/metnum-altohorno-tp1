#ifndef GAUSS_H
#define GAUSS_H

#include "misc.h"
#include "Matriz.h"
#include "defines.h"

//Triangulacion de la parte inferior.
template<class T>
void gaussInf(Matriz<T>& A, vector<T>& b, int piv = PIV, int lu = NO_LU){
	// Voy iterando la matriz fila por fila.
	int cant_filas = A.cantFilas();
	int cant_columnas = A.cantColumnas();
	for(int i = 0; i < cant_filas-1; i++){
		// Uso de pivoteo parcial para reducir el error, agarro la fila con elemento maximo en la columna actual.
		// Se deben intercambiar las filas
		if(piv == PIV && lu == NO_LU){
            int max_pos = maxPos(A, i, INF);
            A.intercambiar(max_pos, i);
            swap(b[max_pos], b[i]);
		}
		if(esCero(A[i][i])){cerr << "Gauss: la matriz no se puede triangular" << endl;  return;}  // Error, la matriz no se puede triangular
		//  Aplico gauss fila por fila a partir de la fila siguiente a la fila pivot.
		for(int j = i+1; j < cant_filas; j++){
			T m = A[j][i]/A[i][i];
			// Si ya hay un cero, no hago nada.
			if(!esCero(m)){
                for(int k = i; k < cant_columnas; k++){
                    // Aplico gauss en toda la fila. Con k = i se cancelan los valores.
                    A[j][k] = A[j][k]- m*A[i][k];

                }
                // Actualizo b.
                if(lu == NO_LU ){b[j] = b[j] - m*b[i];}
                // Mando un cero porque no confio en los double y ni se si van a ser double.
                if(lu == LU){A[j][i] = m;}
                else{A[j][i] = 0;}
			}
		}
	}
}

//Triangulacion de la parte superior.
template<class T>
void gaussSup(Matriz<T>& A, vector<T>& b, int piv = PIV, int lu = NO_LU){
	// Voy iterando la matriz fila por fila.
	int cant_filas = A.cantFilas();
	int cant_columnas = A.cantColumnas();
	for(int i=cant_filas-1; i+1 > 0; i--){
		// Uso de pivoteo parcial para reducir el error, agarro la fila con elemento maximo en la columna actual.
		// Se deben intercambiar las filas
		if(piv == PIV && lu == NO_LU){
            int max_pos = maxPos(A, i, SUP);
            A.intercambiar(max_pos, i);
            swap(b[max_pos], b[i]);
		}
		if(esCero(A[i][i])){cerr << "Gauss: la matriz no se puede triangular" << endl; return;}  // Error, la matriz no se puede triangular
		//  Aplico gauss fila por fila a partir de la fila siguiente a la fila pivot.
		for(int j = i-1; j+1 > 0; j--){
            T m = A[j][i]/A[i][i];
            // Si ya hay un cero, no hago nada.
            if(!esCero(m)){
                for(int k = i; k > cant_columnas; k--){
                    // Aplico gauss en toda la fila. Con k = i se cancelan los valores.
                    A[j][k] = A[j][k] - m*A[i][k];
                }
                // Actualizo b.
                if(lu == NO_LU){b[j] = b[j] - m*b[i];}
                // Mando un cero porque no confio en los double y ni se si van a ser double.
                if(lu == LU){A[j][i] = m;}
                else{A[j][i] = 0;}
            }
		}
	}
}


#endif
