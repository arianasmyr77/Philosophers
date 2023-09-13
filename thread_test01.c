/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_test01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:17:46 by arforouz          #+#    #+#             */
/*   Updated: 2023/09/13 14:02:11 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

void	*imprimirPares(void *arg)
{
	int	i;

	i = 2;
	while (i <= 10)
	{
		printf("Numero Par: %d\n", i);
		i += 2;
	}
	pthread_exit(NULL);
}

void	*imprimirImpares(void *arg)
{
	int	i;

	i = 1;
	while (i <= 9)
	{
		printf("Numero Impar: %d\n", i);
		i += 2;
	}
	pthread_exit(NULL);
}

int main()
{
	pthread_t thread1, thread2;
	
	//crear dos hilos separados
	pthread_create(&thread1, NULL, imprimirPares, NULL);
	pthread_create(&thread2, NULL, imprimirImpares, NULL);

	//Esperar a que ambos hilos terminen
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}
