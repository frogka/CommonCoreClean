/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:06:23 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 20:57:12 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// FONCTOIN INIT MUTEX
// FONCTION DESTROY MUTEX

#include "philo.h"

int	is_dead(t_data *data)
{
	int	value;

	pthread_mutex_lock(&data->death);
	value = data->philo_died;
	pthread_mutex_unlock(&data->death);
	return (value);
}

int	number_meals(t_data *data, t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&data->meal_mutex);
	stop = (data->max_meal > 0 && philo->number_meal == 0);
	pthread_mutex_unlock(&data->meal_mutex);
	return (stop);
}

void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->death);
	data->philo_died = 1;
	pthread_mutex_unlock(&data->death);
}

void	set_time_and_nbr_meals(t_data *data, t_philo *philo)
{
	pthread_mutex_lock(&data->meal_mutex);
	if (data->max_meal > 0 && philo->number_meal > 0)
		philo->number_meal -= 1;
	philo->last_meal = timestamp();
	pthread_mutex_unlock(&data->meal_mutex);
}
