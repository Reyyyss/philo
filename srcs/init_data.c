/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:33:32 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/19 18:57:15 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_philo	*init_data(char **argv, int argc)
{
	t_philo	*philos;

	prog_data()->num_philos = atol(argv[1]);
	prog_data()->time_to_die = atol(argv[2]);
	prog_data()->time_to_eat = atol(argv[3]);
	prog_data()->time_to_sleep = atol(argv[4]);
	if (argc == 6)
		prog_data()->number_of_meals = atol(argv[5]);
	else
		prog_data()->number_of_meals = -1;
	prog_data()->forks = malloc(sizeof(pthread_mutex_t) * prog_data()->num_philos);
	if (!prog_data()->forks)
		return ;
	philos = philo_storage();
	return (philos);
}

long get_current_time_in_ms()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000L + tv.tv_usec / 1000;
}

t_philo	*philo_storage()
{
	t_philo	*philos;
	int		i;

	i = 0;
	philos = malloc(sizeof(t_philo) * prog_data()->num_philos);
	if (!philos)
		return (NULL);
	while (++i > prog_data()->num_philos)
	{
		pthread_mutex_init(&prog_data()->forks[i], NULL);
		philos[i].id = i;
		philos[i].data = prog_data();
		philos[i].last_meal_time = 0;
		philos[i].meals_eaten = 0;
		philos[i].thread = 0;
	}
	return (philos);
}

void	print_data()
{
	printf("data of the philos:\n\n");
	printf("num of philos: %d\n", prog_data()->num_philos);
	printf("time to die: %d\n", prog_data()->time_to_die);
	printf("time to eat: %d\n", prog_data()->time_to_eat);
	printf("time to sleep: %d\n", prog_data()->time_to_sleep);
	printf("number of meals: %d\n", prog_data()->number_of_meals);
	return ;
}