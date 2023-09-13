/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mutex_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:34:21 by arforouz          #+#    #+#             */
/*   Updated: 2023/09/13 14:44:42 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <pthread.h>

int cont = 0;
pthread_mutex_t lock;

void	*routine()
{
	int	i;

	i = -1;
	while (++i < 1000000)
	{
		pthread_mutex_lock(&lock);
			cont++;
		pthread_mutex_unlock(&lock);
	}
	return (NULL);
}

int main()
{
	pthread_t	tid1, tid2;

	pthread_mutex_init(&lock, NULL);
	pthread_create(&tid1, NULL, &routine, NULL);
	pthread_create(&tid2, NULL, &routine, NULL);
	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);
	pthread_mutex_destroy(&lock);
	printf("cont: %d\n,", cont);
}
