#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main() {
    int n = 100000; // Tamaño del array
    long *array = (long*)malloc(n * sizeof(long)); // Cambiamos int por long para sumas más grandes
    long sum = 0;
    int i;

    // Inicializamos el array con valores
    for (i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    // Suma en paralelo con OpenMP
    #pragma omp parallel for reduction(+:sum)
    for (i = 0; i < n; i++) {
        sum += array[i];
    }

    // Mostramos el resultado
    printf("La suma total es: %ld\n", sum);

    // Liberamos memoria al terminar con la suma paralela
    free(array);
    
    return 0;
}

