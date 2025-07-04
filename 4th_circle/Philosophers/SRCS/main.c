/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:41 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/04 15:14:55 by mkuida           ###   ########.fr       */
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

static void	set_thread_manage(t_thread_manage *thread_manage ,t_condition *condition)
{
	thread_manage->num_of_philos = condition->num_of_philos;
	thread_manage->thread_id = (pthread_t *)malloc(sizeof(pthread_t) * condition->num_of_philos);
	if (!thread_manage->thread_id)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	thread_manage->forks_mutex = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * condition->num_of_philos);
	if (!thread_manage->forks_mutex)
	{
		perror("malloc error");
		free(thread_manage->thread_id);
		exit(EXIT_FAILURE);
	}
	thread_manage->left_forks = condition->num_of_philos;
	init_thread_manage_mutex_initialize(thread_manage);
	
}

static void	set_condition(t_condition *condition ,int argc, char **argv)
{
	condition->num_of_philos = ft_atoi((const char*)argv[1]);
	condition->time_to_die = ft_atoi((const char*)argv[2]);
	condition->time_to_eat = ft_atoi((const char*)argv[3]);
	condition->time_to_sleep = ft_atoi((const char*)argv[4]);
	if (argc == 6)
	{
		condition->num_of_eat_times = ft_atoi((const char*)argv[5]);
		condition->optional_eat_times_flag = true;
	}
	else
	{
		condition->num_of_eat_times = -1;
		condition->optional_eat_times_flag = false;
	}
}

static int	check_args(int argc, char **argv)
{
	if (check_argc_num(argc) == 1)
		return (1);
	if (check_input_is_num(argc, argv) == 1)
		return (1);
	if ((check_input_is_posi_int(argc, argv)) == 1)
		return (1); 
	return (0);
}

void set_philosophers(t_simulation *simulation)
{
	int i;
	int philo_num;

	i = 0;
	philo_num = simulation->condition.num_of_philos;
	simulation->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * philo_num);
	if(!simulation->philosophers)
	{
		perror("malloc error");
		exit(EXIT_FAILURE);
	}
	while(i < philo_num)
	{
		simulation->philosophers[i].id = i + 1; // Philosopher IDs start from 1
		simulation->philosophers[i].num_of_eat_times = 0; // Initialize eat count
		simulation->philosophers[i].last_eat_time = 0; // Initialize last meal time
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;

	if (check_args(argc,argv) == 1)
		return (1);
	set_condition(&(simulation.condition), argc, argv);
	print_condition(&simulation.condition);//
	set_thread_manage(&(simulation.thread_manage) , &(simulation.condition));
	set_philosophers(&simulation);
	if (philosophers(&simulation) == 1)
	{
		return (1);
	}
	usleep(5000000);
	return (0);
}
