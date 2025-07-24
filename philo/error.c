/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:54:19 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/23 14:45:42 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_input(void)
{
	printf(RED "Error\n" RESET);
	printf("Please enter: ./philo number_of_philosophers time_to_die");
	printf("time_to_eat time_to_sleep ");
	printf("[number_of_times_each_philosopher_must_eat]\n");
}

void	error_max_int(void)
{
	printf(RED "Error\n" RESET);
	printf("A number is greater than an int\n");
}

int	error_range_philo(t_data *data)
{
	if (data->num_p < 1 || data->num_p > 200)
	{
		printf(RED "Error\n" RESET);
		printf("Numbers of philosophers must be between 1 and 200\n");
		return (1);
	}
	return (0);
}
