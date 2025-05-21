/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:49:20 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/21 16:20:01 by hcarrasq         ###   ########.fr       */
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
	int		i;

	i = -1;
	while (prog_data()->simulation_stop == 0)
	{
		philo_eating();
		ft_printmessage(philo[i].id, get_current_time_in_ms - prog_data()->start_time, "is sleeping");
		usleep(prog_data()->time_to_sleep * 1000);
		ft_printmessage(philo[i].id, get_current_time_in_ms - prog_data()->start_time, "is thinking");
		i++;
		if (prog_data()->number_of_meals > 0)
			if (prog_data()->number_of_meals == philos[i].meals_eaten)
				break;
	}
}

void	ft_printmessage(int	philo_id, long	time, char *str)
{
	pthread_mutex_lock(&prog_data()->write_lock);
	printf("philo %d, %s at %ld\n", philo_id, time, str);
	pthread_mutex_unlock(&prog_data()->write_lock);
}

void	take_forks(t_philo *philos)
{
	int	i;
	int	right_fork;
	int	left_fork;

	i = 0;
	left_fork = philos[i - 1].id;
	right_fork = philos[i - 1].id % prog_data()->num_philos;
	if (philos[i].id % 2 == 0)
	{
		pthread_mutex_lock(&left_fork);
		ft_printmessage();
		pthread_mutex_lock(&right_fork);
		ft_printmessage();
	}
	else
	{
		pthread_mutex_lock(&left_fork);
		ft_printmessage();
		pthread_mutex_lock(&right_fork);
		ft_printmessage();
	}
}

void	put_the_forks_down(t_philo	*philos)
[
	
]