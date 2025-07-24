/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdutille <jdutille@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:08:04 by jdutille          #+#    #+#             */
/*   Updated: 2025/07/22 22:20:10 by jdutille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define RED "\033[31m"
# define CYAN "\033[36m"
# define PURPLE "\033[35m"
# define BLUE "\033[34m"
# define JADE "\033[92m"
# define RESET "\033[0m"

typedef struct s_philo
{
	int				id;
	int				number_meal;
	long long		last_meal;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_t		routine;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_p;
	int				t_death;
	int				t_eat;
	int				t_sleep;
	long long		time_start;
	int				max_meal;
	pthread_mutex_t	*tab_forks;
	pthread_mutex_t	print_op;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	death;
	pthread_t		check_philo;
	pthread_t		check_meal;
	int				philo_died;
	t_philo			*philo;
}					t_data;

///////////////////ROUTINE//////////////////
void				*routine(void *arg);
void				philo_fork(t_philo *philo);
void				philo_eat(t_philo *philo);
void				*routine_for_one(void *arg);

//////////////////PARSING//////////////////
int					is_digit(char *str);
int					ft_len(char *str);
long long			ft_atoi(char *str);
int					parsing(int ac, char **av);

/////////////////INIT/////////////////////
long long			timestamp(void);
void				init_philo(t_data *data);
void				init_values(int ac, char **av, t_data *data);
void				init_mutex(t_data *data);
void				join_and_destroy(t_data *data);

/////////////////MUTEX//////////////////
int					is_dead(t_data *data);
int					number_meals(t_data *data, t_philo *philo);
void				set_dead(t_data *data);
void				set_time_and_nbr_meals(t_data *data, t_philo *philo);

////////////////ERROR////////////////////
void				error_input(void);
void				error_max_int(void);
int					error_range_philo(t_data *data);

///////////////FORKS////////////////////
int					put_forkl(t_data *data, t_philo *philo);
int					put_forkr(t_data *data, t_philo *philo);
int					put_forks(t_data *data, t_philo *philo);

///////////////PHILO//////////////////////
void				create_thread(t_data *data);
void				print_status(t_philo *philo, int i);
void				*death_checker(void *arg);
void				*meal_checker(void *arg);

#endif