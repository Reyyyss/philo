/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcarrasq <hcarrasq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:42:44 by hcarrasq          #+#    #+#             */
/*   Updated: 2025/05/14 17:38:47 by hcarrasq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 4 || argc >5)
		return (printf("Error: Expected 4 or 5 arguments\n"), 1);
	//buscar o ft_valid do push swap porque todos os argumentos precisam de
	//ser numeros e precisam todos de ser maiores que 0 menos o ultimo 
	//pois e opcional, posso tambem colocar um limite de filosofos para 200 
	//porque diz que nao e suposto testar
	
}