/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:14:05 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/28 18:53:17 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

bool	ft_isnbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	if (!nbr[i])
		return (false);
	while (nbr[i])
	{
		if (nbr[i] < '0' && nbr[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
/// @brief check if its a number or not
/// @param argc 
/// @param argv 
bool	ft_valid(int argc, char **argv)
{
	char	**nbr;
	int		i;
	int		j;

	i = 0;
	while (i < argc)
	{
		nbr = argv;
		j = 0;
		while (argv[j])
		{
			if (!ft_isnbr(argv[j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}
/// @brief 
/// @param nptr string thats gonna be converted to an int
/// @return only positive numbers
long	ft_atol(const char *nptr)
{
	int		count;
	int		i;
	long	num;

	num = 0;
	i = 0;
	count = 1;
	while ((nptr[i] >= '\t' && nptr[i] <= '\r') || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			return (-1);
		i++;
		if (!nptr[i])
			return ((long)INT_MAX + 1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
		if (num > INT_MAX || num < INT_MIN)
			return ((long)INT_MAX + 1);
	}
	return (num * count);
}
/// @brief function to check if all the arguments are valid
/// @param argv 
/// @param argc 
bool	validate_args(char **argv, int argc)
{
	int	i;

	i = 0;
	if (!ft_valid(argc, &argv[1]))
		return (false);
	while (i < argc)
	{
		if ((ft_atol(argv[1]) < 0 || ft_atol(argv[1]) > 200))
			return (false);
		if ((ft_atol(argv[2]) < 0 || ft_atol(argv[2]) > INT_MAX))
			return (false);
		if ((ft_atol(argv[3]) < 0 || ft_atol(argv[3]) > INT_MAX))
			return (false);
		if ((ft_atol(argv[4]) < 0 || ft_atol(argv[4]) > INT_MAX))
			return (false);
		if (argc == 6)
			if ((ft_atol(argv[5]) < 0 || ft_atol(argv[5]) > INT_MAX))
				return (false);
		i++;
	}
	return (true);
}

/// @brief print the message of what the philosopher is doing
/// @param philo_id 
/// @param time 
/// @param str 
void	ft_printmessage(int	philo_id, long	time, char *str)
{
	pthread_mutex_lock(&prog_data()->write_lock);
	if(!prog_data()->simulation_stop)
		printf("%ld %d %s\n", time, philo_id, str);
	pthread_mutex_unlock(&prog_data()->write_lock);
}
