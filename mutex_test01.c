/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_test01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:03:27 by arforouz          #+#    #+#             */
/*   Updated: 2023/09/13 15:03:41 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int shared_variable = 0;
pthread_mutex_t mutex;

void *increment_shared_variable(void *arg) {
    for (int i = 0; i < 100000; i++) {
        pthread_mutex_lock(&mutex);
        shared_variable++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&thread1, NULL, increment_shared_variable, NULL);
    pthread_create(&thread2, NULL, increment_shared_variable, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Final shared_variable value: %d\n", shared_variable);

    pthread_mutex_destroy(&mutex);
    return 0;
}
