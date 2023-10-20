/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:51:30 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/20 14:48:04 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	free_resources(t_inf *inf)
{
	int	i;

	i = -1;
	while (++i < inf->nb_philo)
	{
		if (pthread_mutex_destroy(&inf->fork[i]) == 1)
			printf("une fonction a echoue\n");
		if (inf->phiphi[i]->last_eat[0] != 0)
			free(inf->phiphi[i]->last_eat);
	}
	if (pthread_mutex_destroy(&inf->glob[0]) != 0)
		printf("une fonction a echoue\n");
	if (pthread_mutex_destroy(&inf->print[0]) != 0)
		printf("une fonction a echoue\n");
	if (inf->compteur != NULL)
		free(inf->compteur);
	if (inf->stop != NULL)
		free(inf->stop);
	free(inf->phiphi);
	free(inf);
	return (0);
}
