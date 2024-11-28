#include <stdio.h>
#include <stddef.h>
#include <omp.h>

// Máximo de hilos que queremos usar
#define MAX_THREADS 5

void do_work(int arg) { 
  // Una sección critica de OpenMP es equivalente a un área protegida
  // por un mutex. Solo un hilo permanecerá dentro a la vez
  #pragma omp critical
  {
    /* Acceso estructuras de datos comparidas */
    printf("Hilo %d consigue la seccion criticca\n", arg);
  }
}

int main(void) {
    printf("Creando mutex e hilos...\n");
    
    // Se inicia una sección paralela de OpenMP, lo que hace que cada hilo
    // ejecute el código de su interior de forma independiente. 
    // De esta forma se están intentando usar MAX_THREADS hilos, aunque en caso 
    // de no tener tantos cores disponibles solo se usarán los que sí lo estén.
    // Todas las variables externas usadas dentro de esta sección paralela
    // por defecto serán compartidas, mientras que las creadas dentro por defecto
    // serán privadas de cada hilo.
    #pragma omp parallel num_threads(MAX_THREADS)
    {
        int thread_id = omp_get_thread_num();
        do_work(thread_id);
    }

    printf("Tareas terminadas por todos los hilos y mutex destruido\n");

    return 0;
}
