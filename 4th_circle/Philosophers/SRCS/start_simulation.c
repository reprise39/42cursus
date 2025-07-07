/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:05:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/07 18:55:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	init_thread_manage_mutex_initialize(t_thread_manage *thread_manage)
{
	int	i;

	i = 0;
	while (i < (thread_manage->num_of_philos))
	{
		if (pthread_mutex_init(&thread_manage->forks_mutex[i], NULL) != 0)
		{
			printf("pthread_mutex_init error : ");
			printf("at thread_manage forks_mutex[%d]\n",i);
			return(false);
		}
		i++;
	}
	return (true);
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

static bool	set_thread_manage(t_thread_manage *thread_manage,
		t_condition *condition)
{
	thread_manage->num_of_philos = condition->num_of_philos;
	thread_manage->thread_id = (pthread_t *)malloc(sizeof(pthread_t)
			* condition->num_of_philos);
	if (!thread_manage->thread_id)
	{
		printf("malloc error");
		return (false);
	}
	thread_manage->forks_mutex = (pthread_mutex_t *)malloc
		(sizeof(pthread_mutex_t) * condition->num_of_philos);
	if (!thread_manage->forks_mutex)
	{
		printf("malloc error");
		return (false);
	}
	if (init_thread_manage_mutex_initialize(thread_manage) == false)
		return (false);
	return (true);
}

static bool	set_philosophers(t_simulation *simulation)
{
	int	i;
	int	philo_num;

	i = 0;
	philo_num = simulation->condition.num_of_philos;
	simulation->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher)
			* philo_num);
	if (!simulation->philosophers)
	{
		printf("malloc error");
		return(false);
	}
	while (i < philo_num)
	{
		simulation->philosophers[i].id = i + 1;
		simulation->philosophers[i].num_of_eat_times = 0;
		if(pthread_mutex_init_s(&(simulation->philosophers[i].last_eat_time_mutex), NULL) == EXIT_FAILURE)
			return(false);
		i++;
	}
	return (true);
}

int	start_simulatuon(t_simulation *simulation, int argc, char **argv)
{
	set_condition(&(simulation->condition), argc, argv);
	if(set_thread_manage(&(simulation->thread_manage), &(simulation->condition)) == false)
		return (EXIT_FAILURE);
	if(set_philosophers(simulation) == false)
		return (EXIT_FAILURE);
	simulation->is_dead = false;
	if (pthread_mutex_init_s(&simulation->is_dead_mutex, NULL) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	if (pthread_mutex_init_s(&simulation->is_print_mutex, NULL) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	if (pthread_mutex_init_s(&simulation->fin_philo_num_mutex, NULL) == EXIT_FAILURE)
		return(EXIT_FAILURE);
	if (gettimeofday_s(&simulation->start_time, NULL) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
