/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:40:54 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/19 15:18:39 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

long long	timeval(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long long milis, t_philo *info)
{
	long long	time;

	time = timeval() * 1000;
	while (1)
	{
		if (check_end(info) == 1)
			break ;
		usleep(50);
		if (timeval() * 1000 - time >= milis)
			break ;
	}
}

void	print_val(char *str, t_philo *phil)
{
	long	ms;

	pthread_mutex_lock(&phil->print[0]);
	ms = 0;
	ms = (timeval() - phil->time_to_start);
	if (ms >= 0 && phil->compteur[0] != phil->nb_philo)
		printf("%ld, %d, %s\n", ms, phil->id, str);
	pthread_mutex_unlock(&phil->print[0]);
}
