/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:49:20 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/26 19:14:14 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	start_simulation(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < prog_data()->num_philos)
	{
		fprintf(stderr, "Before printf\n");
		fflush(stderr);
		printf("%d\n", philos[i].id);
		fflush(stdout);
		fprintf(stderr, "After printf\n");
		fflush(stderr);
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
	while (prog_data()->simulation_stop == 0)
	{
		if (!i && philos->id % 2 == 0)
			usleep(prog_data()->time_to_eat / 2);
		i = 1;
		philo_eating(philos);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "is sleeping");
		usleep(prog_data()->time_to_sleep * 1000);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "is thinking");
		if (prog_data()->number_of_meals > 0)
			if (prog_data()->number_of_meals == philos->meals_eaten)
				break;
	}
	return (NULL);
}

void	philo_eating(t_philo *philos)
{
	if (get_current_time_in_ms() - philos->last_meal_time <= prog_data()->time_to_die)
	{
		take_forks(philos);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "is eating");
		philos->last_meal_time = get_current_time_in_ms();
		philos->meals_eaten++;
		put_the_forks_down(philos);
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
	left_fork = philos->id - 1;
	right_fork = philos->id % prog_data()->num_philos;
	if (philos->id % 2 == 0)
	{
		pthread_mutex_lock(&prog_data()->forks[left_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "took the left fork");
		pthread_mutex_lock(&prog_data()->forks[right_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "took the right fork");
	}
	else 	
	{
		pthread_mutex_lock(&prog_data()->forks[right_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "took the right fork");
		pthread_mutex_lock(&prog_data()->forks[left_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "took the left fork");
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
		pthread_mutex_unlock(&prog_data()->forks[left_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "dropped the left fork");
		pthread_mutex_unlock(&prog_data()->forks[right_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "dropped the right fork");
	}
	else
	{
		pthread_mutex_unlock(&prog_data()->forks[right_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "dropped the right fork");
		pthread_mutex_unlock(&prog_data()->forks[left_fork]);
		ft_printmessage(philos->id, get_current_time_in_ms() - prog_data()->start_time, "dropped the left fork");
	}
}
