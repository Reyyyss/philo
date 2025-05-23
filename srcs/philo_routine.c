/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:49:20 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/23 15:48:06 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include "philo_routine.h"

void	start_simulation(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < prog_data()->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0);
			return (write(2, "Error creating a thread\n", 25), 1);
	}
	i = -1;
	while (++i < prog_data()->num_philos)
		pthread_join(philos[i].thread, NULL);
}

void	*philo_routine(void	*args)
{
	int	i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo*)args;
	while (prog_data()->simulation_stop == 0)
	{
		if (!i && philos->id % 2 == 0)
			usleep(prog_data()->time_to_eat / 2);
		i = 1;
		philo_eating();
		ft_printmessage(philos->id, get_current_time_in_ms - prog_data()->start_time, "is sleeping");
		usleep(prog_data()->time_to_sleep * 1000);
		ft_printmessage(philos->id, get_current_time_in_ms - prog_data()->start_time, "is thinking");
		if (prog_data()->number_of_meals > 0)
			if (prog_data()->number_of_meals == philos[i].meals_eaten)
				break;
	}
	return (NULL);
}

void	philo_eating(t_philo *philos)
{
	int	i;

	i = 0;
	if (prog_data()->time_to_eat > get_current_time_in_ms - philos[i].last_meal_time)
	{
		take_forks(philos);
		ft_printmessage();
		philos[i].last_meal_time = get_current_time_in_ms;
		philos[i].meals_eaten++;
		put_the_forks_down();
	}
	else
	{
		pthread_mutex_lock(&prog_data()->write_lock);
		prog_data()->simulation_stop = 1;
		pthread_mutex_unlock(&prog_data()->write_lock);
	}
	
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
		pthread_mutex_lock(&right_fork);
		ft_printmessage();
		pthread_mutex_lock(&left_fork);
		ft_printmessage();
	}
}

void	put_the_forks_down(t_philo	*philos, int right_fork, int left_fork)
{
	int	i;
	int	right_fork;
	int	left_fork;

	i = 0;
	left_fork = philos[i - 1].id;
	right_fork = philos[i - 1].id % prog_data()->num_philos;
	if (philos[i].id % 2 == 0)
	{
		pthread_mutex_unlock(&left_fork);
		ft_printmessage();
		pthread_mutex_unlock(&right_fork);
		ft_printmessage();
	}
	else
	{
		pthread_mutex_unlock(&right_fork);
		ft_printmessage();
		pthread_mutex_unlock(&left_fork);
		ft_printmessage();
	}
}
