/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 20:52:50 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 20:53:26 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	put_forkl(t_data *data, t_philo *philo)
{
	if (is_dead(data) || number_meals(data, philo))
	{
		pthread_mutex_unlock(philo->fork_l);
		return (1);
	}
	return (0);
}

int	put_forkr(t_data *data, t_philo *philo)
{
	if (is_dead(data) || number_meals(data, philo))
	{
		pthread_mutex_unlock(philo->fork_r);
		return (1);
	}
	return (0);
}

int	put_forks(t_data *data, t_philo *philo)
{
	if (is_dead(data) || number_meals(data, philo))
	{
		pthread_mutex_unlock(philo->fork_l);
		pthread_mutex_unlock(philo->fork_r);
		return (1);
	}
	return (0);
}
