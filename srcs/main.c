/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:42:44 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/27 15:25:06 by hcarrasq         ###   ########.fr       */
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
	print_data();
	start_simulation(philos);
	return (0);
	
}

t_data	*prog_data()
{
	static t_data	prog_data;

	return (&prog_data);
}