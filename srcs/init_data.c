/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:33:32 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/16 14:48:12 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_data(char **argv)
{
	prog_data()->num_philos = atol(argv[1]);
	prog_data()->time_to_die = atol(argv[2]);
	prog_data()->time_to_eat = atol(argv[3]);
	prog_data()->time_to_sleep = atol(argv[4]);
	if (argv[5])
		prog_data()->number_of_meals = atol(argv[5]);
	else
		prog_data()->number_of_meals = -1;
}
