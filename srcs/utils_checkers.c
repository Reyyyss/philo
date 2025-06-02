/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_checkers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 14:50:22 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/06/02 15:22:21 by henrique-re      ###   ########.fr       */
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

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(&prog_data()->forks[philo->id - 1]);
	ft_printmessage(philo->id, get_current_time_in_ms() - prog_data()->start_time, LEFT_FORK);
	pthread_mutex_unlock(&prog_data()->forks[philo->id - 1]);
	usleep(prog_data()->time_to_die * 1000);
	printf("%ld %d %s\n", get_current_time_in_ms() - prog_data()->start_time, philo->id, DIED);
	return ;
}

void	destroy_mutexes(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < prog_data()->num_philos)
	{
		pthread_mutex_destroy(&prog_data()->forks[i]);
		i++;	
	}
	free(prog_data()->forks);
	free(philos);	
}