/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:49:20 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/06/02 15:33:29 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	start_simulation(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < prog_data()->num_philos)
	{
		if (pthread_create(&philos[i].thread, NULL, philo_routine, &philos[i]) != 0)
			return (write(2, "Error creating a thread\n", 25), 1);
	}
	i = -1;
	while (++i < prog_data()->num_philos)
		pthread_join(philos[i].thread, NULL);
	return (0);
}

void	*philo_routine(void	*args)
{
	int	i;
	t_philo	*philos;

	i = 0;
	philos = (t_philo*)args;
	philos->last_meal_time = get_current_time_in_ms();
	while (1)
	{
		if (prog_data()->simulation_stop == 1)
			break;
		if (!i && philos->id % 2 != 0 && prog_data()->num_philos > 5)
			usleep((philos->id % 2) * (prog_data()->time_to_eat * 975));
		else
			usleep(prog_data()->time_to_eat / 3);
		if (i && philos->id % 2 != 0)
			usleep(500);
		i = 1;
		philo_eating(philos); 
		if (prog_data()->number_of_meals > 0)	
			if (prog_data()->number_of_meals == philos->meals_eaten)
				break;
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, SLEEPING);
		death_checker(philos, prog_data()->time_to_sleep);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, THINKING);
	}
	return (NULL);
}

void	philo_eating(t_philo *philos)
{
	take_forks(philos);
	ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, EATING);
	death_checker(philos, prog_data()->time_to_eat);
	philos->last_meal_time = get_current_time_in_ms();
	philos->meals_eaten++;
	put_the_forks_down(philos);
}

void	take_forks(t_philo *philos)
{
	int	right_fork;
	int	left_fork;

	left_fork = philos->id - 1;
	right_fork = philos->id % prog_data()->num_philos;
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(&prog_data()->forks[left_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, RIGHT_FORK);
		pthread_mutex_lock(&prog_data()->forks[right_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, LEFT_FORK);
	}
	else 	
	{
		pthread_mutex_lock(&prog_data()->forks[right_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, LEFT_FORK);
		pthread_mutex_lock(&prog_data()->forks[left_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, RIGHT_FORK);
	}
}

void	put_the_forks_down(t_philo	*philos)
{
	int	right_fork;
	int	left_fork;

	left_fork = philos->id - 1;
	right_fork = philos->id % prog_data()->num_philos;
	if (philos->id % 2 == 0)
	{
		pthread_mutex_unlock(&prog_data()->forks[right_fork]);
		pthread_mutex_unlock(&prog_data()->forks[left_fork]);
	}
	else
	{
		pthread_mutex_unlock(&prog_data()->forks[left_fork]);
		pthread_mutex_unlock(&prog_data()->forks[right_fork]);
	}
}
