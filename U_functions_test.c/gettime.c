/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arforouz <arforouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:07:52 by arforouz          #+#    #+#             */
/*   Updated: 2023/09/13 15:12:46 by arforouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval current_time;
    if (gettimeofday(&current_time, NULL) == 0) {
        printf("Seconds: %ld\n", current_time.tv_sec);
        printf("Microseconds: %ld\n", current_time.tv_usec);
    } else {
        perror("gettimeofday");
    }
    return 0;
}
