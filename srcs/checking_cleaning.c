/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_cleaning.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:50:22 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/28 18:36:02 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	death_checker(t_philo *philos, long state)
{
	long	time_mark;

	pthread_mutex_lock(&prog_data()->write_lock);
	time_mark = get_current_time_in_ms() - philos->last_meal_time;
	if (time_mark + state > prog_data()->time_to_die && prog_data()->simulation_stop == 0)
	{
		if(prog_data()->time_to_die - time_mark > 0)
			usleep((prog_data()->time_to_die - time_mark) * 1000);
		printf("%ld - %d, %s\n", get_current_time_in_ms() - prog_data()->start_time, philos->id, DIED);
		prog_data()->simulation_stop = 1;
		pthread_mutex_unlock(&prog_data()->write_lock);
		return (true);
	}
	else
	{
		pthread_mutex_unlock(&prog_data()->write_lock);
		usleep(state * 1000);
	}
	return (false);
}