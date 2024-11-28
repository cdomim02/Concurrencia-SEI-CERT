#include <stddef.h>
#include <stdio.h>
#include <threads.h>
  
// Mutex 
mtx_t lock;

/* Definir estructura compartida*/

// Máximo de hilos que usaremos
enum { max_threads = 5 };
 
// Código concurrente
int do_work(void *arg) {
  int *i = (int *)arg;
 
  if (*i == 0) { // El primer hilo (id más bajo) crea el mutex
    if (thrd_success != mtx_init(&lock, mtx_plain)) {
      /* Manejar error */
    }
    printf("Hilo 0 crea mutex\n");

  } else if (*i < max_threads - 1) { // Hilos intermedios acceden a la sección crítica
    // Bloquear acceso a un solo hilo "reteniendo" el lock
    if (thrd_success != mtx_lock(&lock)) {
      /* Manejar error */
    }

    // Acceso secuencial protegido por el mutex (lock)
    // Acceder a una estructura de datos compartida
    printf("Hilo %d consigue la seccion criticca\n", *i);

    // Liberar acceso para que entre el siguiente hilo que está esperando
    if (thrd_success != mtx_unlock(&lock)) {
      /* Manejar error */
    }
  } else { // El último hilo (id más alto) destruye el mutex
    mtx_destroy(&lock);
    printf("Hilo %d destruye mutex\n", *i);
  }
  return 0;
}
  
int main(void) {
  thrd_t threads[max_threads];

  printf("Creando hilos...\n");

  //Crear y asignar una tarea a cada hilo
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_create(&threads[i], do_work, &i)) {
      /* Manejar error */
    }
  }

  // Esperamos a que los hilos acaben sus respectivas ejecuciones
  for (size_t i = 0; i < max_threads; i++) {
    if (thrd_success != thrd_join(threads[i], 0)) {
      /* Manejar error */
    }
  }

  printf("Tareas terminadas por todos los hilos\n");

  return 0;
}