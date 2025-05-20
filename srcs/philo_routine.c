/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:49:20 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/20 19:45:56 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	start_simulation()
{
	int	i;

	i = -1;
	while (++i < prog_data()->num_philos)
		pthread_create();
	i = -1;
	while (++i < prog_data()->num_philos)
		pthread_join();
}

void	philo_routine(t_philo *philos)
{
	int	i;

	i = -1;
	while (1)
	{
		
		if (prog_data()->number_of_meals > 0)
			if (prog_data()->number_of_meals == philos[i].meals_eaten)
				break;
	}
}

