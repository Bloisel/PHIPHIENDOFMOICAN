/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:41:03 by bloisel           #+#    #+#             */
/*   Updated: 2023/10/20 01:19:00 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int argc, char **argv)
{
	t_inf	*info;

	info = malloc(sizeof(t_inf));
	if (!info)
		return (1);
	if (argc != 6 && argc != 5)
		return (1);
	if ((ft_atoi(argv[1]) == 0))
	{
		printf("Argument invalide\n");
		return (1);
	}
	if (check_num(argv))
	{
		printf("Argument invalide\n");
		return (1);
	}
	if (init_struct(info, argv) == 0)
	{
		if (init_philo(info) != 1)
			init_thread(info);
	}
	if (free_resources(info) != 0)
		return (1);
	return (0);
}
