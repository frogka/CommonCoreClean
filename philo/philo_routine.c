/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 14:43:18 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 21:47:41 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		if (is_dead(data) || number_meals(data, philo))
			return (NULL);
		philo_fork(philo);
		if (is_dead(data) || number_meals(data, philo))
			return (NULL);
		philo_eat(philo);
		if (is_dead(data) || number_meals(data, philo))
			return (NULL);
		print_status(philo, 3);
		usleep(data->t_sleep * 1000);
		if (is_dead(data) || number_meals(data, philo))
			return (NULL);
		print_status(philo, 4);
	}
	return (NULL);
}

void	philo_fork(t_philo *philo)
{
	if (is_dead(philo->data) || number_meals(philo->data, philo))
		return ;
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->fork_l);
		if (put_forkl(philo->data, philo))
			return ;
		print_status(philo, 1);
		pthread_mutex_lock(philo->fork_r);
		if (put_forks(philo->data, philo))
			return ;
		print_status(philo, 1);
	}
	else
	{
		usleep(500);
		pthread_mutex_lock(philo->fork_r);
		if (put_forkr(philo->data, philo))
			return ;
		print_status(philo, 1);
		pthread_mutex_lock(philo->fork_l);
		if (put_forks(philo->data, philo))
			return ;
		print_status(philo, 1);
	}
}

void	philo_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if (is_dead(data) || number_meals(data, philo))
	{
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return ;
	}
	print_status(philo, 2);
	if (!is_dead(data))
		set_time_and_nbr_meals(data, philo);
	usleep(data->t_eat * 1000);
	pthread_mutex_unlock(philo->fork_r);
	pthread_mutex_unlock(philo->fork_l);
}

void	*routine_for_one(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (!is_dead(data))
	{
		pthread_mutex_lock(philo->fork_l);
		if (is_dead(data) || number_meals(data, philo))
		{
			pthread_mutex_unlock(philo->fork_l);
			return (NULL);
		}
		print_status(philo, 1);
		if (is_dead(data) || number_meals(data, philo))
		{
			pthread_mutex_unlock(philo->fork_l);
			return (NULL);
		}
		if (!is_dead(data))
			set_time_and_nbr_meals(data, philo);
		usleep(data->t_eat * 1000);
		pthread_mutex_unlock(philo->fork_l);
	}
	return (NULL);
}
