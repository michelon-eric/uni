#include <stdio.h>
#include <basic/array.h>
#include <string.h>

/*
 * Scrivete un programma che dato un array di interi positivi, calcoli quante 
 * sono le occorrenze di ogni valore presente nell'array.
 * Notate che i valori dell'array, purché positivi, 
 * possono essere grandi a piacere. 
 * Il programma deve poi stampare quanto trovato, utilizzando il comando:
 * printf("il valore %d appare %d volte\n", A[i], freq[i]);
 * 
 * Per esempio se l'array è [1,1,2,3,1,2] si ottiene il seguente output:
 * il valore 1 appare 3 volte
 * il valore 2 appare 2 volte
 * il valore 3 appare 1 volte
 * 
 */

int array_contains(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) return 1;
    }
    return 0;
}

int main()
{
    // Per testare più velocemente il vostro algoritmo potete 
    // usare gli array sotto (modificandoli secondo le vostre necessità)
    // invece di leggerli da input con scanf. Quando siete pronti a
    // consegnare potete ricommentare le 2 righe seguenti.
    
	// int dim=6;
	// int A[6] = {1,2,3,1,1,3};
	
    // leggi array e dimensioni
    int dim;
    scanf("%d", &dim);
    
    int A[dim];
    //funzione libreria
    leggi_array(A, dim);

    int read[dim];
    int last_read = 0, freq = 0;
    memset(read, 0, dim * sizeof(int));
    for (int i = 0 ; i < dim; i++) {
        if (array_contains((int*)read, last_read, A[i])) {
            continue;
        }
        read[last_read++] = A[i];

        freq = 1;
        for (int j = i + 1; j < dim; j++) {
            if (A[j] == A[i]) {
                freq++;
            }
        }

        printf("il valore %d appare %d volte\n", A[i], freq);
    }
    
    return 0;
}