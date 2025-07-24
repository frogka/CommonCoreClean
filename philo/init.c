/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:04:50 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 21:48:03 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timestamp(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->num_p);
	if (!data->philo)
		return ;
	while (i < data->num_p)
	{
		data->philo[i].id = i + 1;
		data->philo[i].number_meal = data->max_meal;
		data->philo[i].last_meal = data->time_start;
		data->philo[i].fork_l = &data->tab_forks[i];
		data->philo[i].fork_r = &data->tab_forks[(i + 1) % data->num_p];
		data->philo[i].data = data;
		i++;
	}
}

void	init_values(int ac, char **av, t_data *data)
{
	data->num_p = ft_atoi(av[1]);
	data->t_death = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->time_start = timestamp();
	data->philo_died = 0;
	data->tab_forks = malloc(sizeof(pthread_mutex_t) * data->num_p);
	if (ac == 6)
		data->max_meal = ft_atoi(av[5]);
	else if (ac == 5)
		data->max_meal = -1;
}

void	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		pthread_mutex_init(&data->tab_forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&data->meal_mutex, NULL);
	pthread_mutex_init(&data->print_op, NULL);
	pthread_mutex_init(&data->death, NULL);
}

void	join_and_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_p)
	{
		pthread_join(data->philo[i].routine, NULL);
		i++;
	}
	pthread_join(data->check_philo, NULL);
	if (data->max_meal > 0)
		pthread_join(data->check_meal, NULL);
	i = 0;
	while (i < data->num_p)
	{
		pthread_mutex_destroy(&data->tab_forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->meal_mutex);
	pthread_mutex_destroy(&data->print_op);
	pthread_mutex_destroy(&data->death);
}
