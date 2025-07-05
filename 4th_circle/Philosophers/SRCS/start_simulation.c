/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:05:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 22:21:47 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_thread_manage_mutex_initialize(t_thread_manage *thread_manage)
{
	int	i;

	i = 0;
	while (i < (thread_manage->num_of_philos))
	{
		if (pthread_mutex_init(&thread_manage->forks_mutex[i], NULL) != 0)
		{
			perror("pthread_mutex_init error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_mutex_init(&thread_manage->left_forks_mutex, NULL) != 0)
	{
		perror("pthread_mutex_init error");
		exit(EXIT_FAILURE);
	}
}

static void	set_condition(t_condition *condition, int argc, char **argv)
{
	condition->num_of_philos = ft_atoi((const char *)argv[1]);
	condition->time_to_die = ft_atoi((const char *)argv[2]) * 1000;
	condition->time_to_eat = ft_atoi((const char *)argv[3]) * 1000;
	condition->time_to_sleep = ft_atoi((const char *)argv[4]) * 1000;
	if (argc == 6)
	{
		condition->num_of_eat_times = ft_atoi((const char *)argv[5]);
		condition->optional_eat_times_flag = true;
	}
	else
	{
		condition->num_of_eat_times = -1;
		condition->optional_eat_times_flag = false;
	}
}

static void	set_thread_manage(t_thread_manage *thread_manage,
		t_condition *condition)
{
	thread_manage->num_of_philos = condition->num_of_philos;
	thread_manage->thread_id = (pthread_t *)malloc(sizeof(pthread_t)
			* condition->num_of_philos);
	if (!thread_manage->thread_id)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	thread_manage->forks_mutex = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * condition->num_of_philos);
	if (!thread_manage->forks_mutex)
	{
		perror("malloc error");
		free(thread_manage->thread_id);
		exit(EXIT_FAILURE);
	}
	thread_manage->left_forks = condition->num_of_philos;
	init_thread_manage_mutex_initialize(thread_manage);
}

static void	set_philosophers(t_simulation *simulation)
{
	int	i;
	int	philo_num;

	i = 0;
	philo_num = simulation->condition.num_of_philos;
	simulation->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* philo_num);
	if (!simulation->philosophers)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	while (i < philo_num)
	{
		simulation->philosophers[i].id = i + 1;
		simulation->philosophers[i].num_of_eat_times = 0;
		i++;
	}
}

void	start_simulatuon(t_simulation *simulation, int argc, char **argv)
{
	set_condition(&(simulation->condition), argc, argv);
	set_thread_manage(&(simulation->thread_manage), &(simulation->condition));
	set_philosophers(simulation);
	simulation->is_dead = false;
	if (pthread_mutex_init(&simulation->is_dead_mutex, NULL) != 0)
	{
		perror("pthread_mutex_init error");
		exit(EXIT_FAILURE);
	}
	gettimeofday(&simulation->start_time, NULL);
}
