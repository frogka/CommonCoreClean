/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 12:13:48 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 22:02:46 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		if (data->num_p == 1)
		{
			pthread_create(&data->philo[i].routine, NULL, routine_for_one,
				&data->philo[i]);
			break ;
		}
		pthread_create(&data->philo[i].routine, NULL, routine, &data->philo[i]);
		i++;
	}
	pthread_create(&data->check_philo, NULL, death_checker, data);
	if (data->max_meal > 0)
		pthread_create(&data->check_meal, NULL, meal_checker, data);
}

void	print_status(t_philo *philo, int i)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->print_op);
	if (i == 1)
		printf("%lld %d has taken a fork\n", timestamp() - data->time_start,
			philo->id);
	else if (i == 2)
		printf("%lld %d is eating\n", timestamp() - data->time_start,
			philo->id);
	else if (i == 3)
		printf("%lld %d is sleeping\n", timestamp() - data->time_start,
			philo->id);
	else if (i == 4)
		printf("%lld %d is thinking\n", timestamp() - data->time_start,
			philo->id);
	else if (i == 5)
	{
		printf("%lld %d is dead\n", timestamp() - data->time_start, philo->id);
	}
	pthread_mutex_unlock(&data->print_op);
}

void	*death_checker(void *arg)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	data = (t_data *)arg;
	philo = data->philo;
	while (!is_dead(data))
	{
		i = 0;
		while (i < data->num_p)
		{
			pthread_mutex_lock(&data->meal_mutex);
			if (timestamp() - philo[i].last_meal >= data->t_death)
			{
				pthread_mutex_unlock(&data->meal_mutex);
				set_dead(data);
				print_status(&philo[i], 5);
				return (NULL);
			}
			pthread_mutex_unlock(&data->meal_mutex);
			i++;
		}
		usleep(500);
	}
	return (NULL);
}

void	*meal_checker(void *arg)
{
	t_data	*data;
	int		i;
	int		meal;

	data = (t_data *)arg;
	meal = 0;
	while (!is_dead(data))
	{
		i = 0;
		meal = 0;
		while (i < data->num_p)
		{
			pthread_mutex_lock(&data->meal_mutex);
			if (data->philo[i].number_meal == 0)
				meal++;
			pthread_mutex_unlock(&data->meal_mutex);
			i++;
		}
		if (meal == data->num_p)
			set_dead(data);
		usleep(5 * 1000);
	}
	return (NULL);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5 || ac == 6)
	{
		init_values(ac, av, &data);
		if (error_range_philo(&data))
			return (1);
		if (parsing(ac, av))
			return (1);
		init_philo(&data);
		init_mutex(&data);
		create_thread(&data);
		join_and_destroy(&data);
		free(data.philo);
		free(data.tab_forks);
	}
	else
		error_input();
	return (0);
}
