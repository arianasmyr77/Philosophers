/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 12:54:29 by arforouz          #+#    #+#             */
/*   Updated: 2023/09/13 13:11:14 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2

void *imprimirNumeros(void *thread_id) {
    int id = *((int *)thread_id);

    for (int i = 1 + id; i <= 10; i += NUM_THREADS) {
        printf("Número: %d (Thread %d)\n", i, id);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        int result = pthread_create(&threads[i], NULL, imprimirNumeros, (void *)&thread_ids[i]);
        if (result) {
            printf("Error al crear el hilo %d; Código de error: %d\n", i, result);
            return -1;
        }
    }

    // Espera a que todos los hilos terminen
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
