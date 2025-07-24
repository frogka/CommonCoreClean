/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:38:52 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 22:21:57 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_digit(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

long long	ft_atoi(char *str)
{
	int			i;
	long long	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int	parsing(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_len(av[i]) > 10)
		{
			error_max_int();
			return (1);
		}
		if (!is_digit(av[i]) || ft_atoi(av[i]) < 1)
		{
			printf(RED "Error\n" RESET);
			printf("Please enter only numbers with positive values\n");
			return (1);
		}
		if (ft_atoi(av[i]) > INT_MAX)
		{
			error_max_int();
			return (1);
		}
		i++;
	}
	return (0);
}
