#include <stdio.h>
#include <stddef.h>
#include <threads.h>
  
// Mutex 
mtx_t lock;

/* Definir estructura compartida*/

// Máximo de hilos que usaremos
enum { max_threads = 5 };
 
// Código concurrente
int do_work(void *arg) {
  int *i = (int *)arg;

  // Entrada seccion critica
  if (thrd_success != mtx_lock(&lock)) {
    /* Manejar error */
  }

  printf("Hilo %d consigue la seccion criticca\n", *i);

  // Salida seccion critica
  if (thrd_success != mtx_unlock(&lock)) {
    /* Manejar error */
  }
 
  return 0;
}
 
int main(void) {
  thrd_t threads[max_threads];

  printf("Creando mutex e hilos...\n");
   
  // Crear mutex
  if (thrd_success != mtx_init(&lock, mtx_plain)) {
    /* Manejar error */
  }

  // Crear hilos y asignarles la tarea
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_create(&threads[i], do_work, &i)) {
      /* Manejar error */
    }
  }

  // Esperar finalizacion todos los hilos
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads[i], 0)) {
      /* Manejar error */
    }
  }
 
  // Destruir mutex
  mtx_destroy(&lock);

  printf("Tareas terminadas por todos los hilos y mutex destruido\n");

  return 0;
}