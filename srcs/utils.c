/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 17:14:05 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/16 14:29:04 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

bool	ft_isnbr(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[i] == '+' || nbr[i] == '-')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (false);
		i++;
	}
	return (true);
}

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
			{
				//ft_free(nbr);
				return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

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
			count *= -1;
		i++;
		if (!nptr[i])
			return ((long)INT_MAX + 1);
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		num = num * 10 + (nptr[i] - 48);
		i++;
		if (num > INT_MAX || num < INT_MIN)
			break ;
	}
	return (num * count);
}

bool	validate_args(char **argv, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_valid(argv[1], argc));
			return (false);
		if (!ft_valid(argv[2], argc));
			return (false);
		if (!ft_valid(argv[3], argc));
			return (false);
		i++;
	}
}
