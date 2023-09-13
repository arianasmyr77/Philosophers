/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   race_condition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:23:59 by arforouz          #+#    #+#             */
/*   Updated: 2023/09/13 14:24:17 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <pthread.h>

int cont = 0;

void  *routine()
{
  int i;

  i = -1;
  while (++i < 1000000)
  	  cont++;
  return (NULL);
}

int main()
{
  pthread_t tid1, tid2;

  pthread_create(&tid1, NULL, &routine, NULL);
  pthread_create(&tid2, NULL, &routine, NULL);

  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  printf("cont: %d\n", cont);
}
