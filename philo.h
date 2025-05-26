/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:07:31 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/26 18:23:34 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <stdarg.h>
# include <fcntl.h>
# include <stdbool.h>
# include <aio.h>
# include <stddef.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	long			last_meal_time;
	int				meals_eaten;
	pthread_t		thread;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write_lock;
	long			start_time;
	int				simulation_stop;
}	t_data;

//main

t_data	*prog_data();

//utils

bool	validate_args(char **argv, int argc);
long	ft_atol(const char *nptr);
bool	ft_valid(int argc, char **argv);
bool	ft_isnbr(char *nbr);
void	ft_printmessage(int	philo_id, long	time, char *str);

//data initialization

void	print_data();
t_philo	*philo_storage();
t_philo	*init_data(char **argv, int argc);
long	get_current_time_in_ms();

//philo routine

void	*philo_routine(void *args);
int		start_simulation(t_philo *philos);
void	philo_eating(t_philo *philos);
void	take_forks(t_philo *philos);
void	put_the_forks_down(t_philo	*philos);


#endif