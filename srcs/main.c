/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: henrique-reis <henrique-reis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:42:44 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/31 16:21:26 by henrique-re      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_philo	*philos;
	if (argc < 5 || argc > 6)
		return (printf("Error: Expected 4 or 5 arguments\n"), 1);
	if (!validate_args(argv, argc))
		return (printf("Error: Arguments are not valid\n"), 1);
	philos = init_data(argv, argc);
	if (prog_data()->num_philos == 1)
	{
		one_philo(philos);
		return (0);
	}
	print_data();
	start_simulation(philos);
	destroy_mutexes(philos);		
	return (0);
	
}

t_data	*prog_data()
{
	static t_data	prog_data;

	return (&prog_data);
}

int absolute_value(int number) 
{
	if (number < 0)
		return (-number);
	else 
		return (number);
}