/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filosophers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:34:56 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/04 09:34:56 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	init_philo(t_philosopher *philo, int i, t_condition *condition, t_thread_manage *thread_manage)
{
	philo->id = i;
	philo->last_eat_time = 0; // Initialize last meal time
	philo->num_of_eat_times = 0; // Initialize eat count
	// Additional initialization if needed
	philo->manager = thread_manage;
	philo->condition = condition;
}

void	*philosopher_routine(void *arg)
{
	t_philosopher *philo = (t_philosopher *)arg;
	printf("I am philosopher %d\n", philo->id);
	return NULL; // Return type should match the thread function signature
}

int mk_philosopher(t_philosopher *philo)
{
	philo = malloc(sizeof(t_philosopher));
	if (!philo)
	{
		perror("malloc error");
		return (EXIT_FAILURE);
	}
	philo->id = 0; // Initialize id to 0
	philo->last_eat_time = 0; // Initialize last meal time
	philo->num_of_eat_times = 0; // Initialize eat count
	// Additional initialization if needed
	philo->manager = NULL; // Set manager to NULL initially
	philo->condition = NULL; // Set condition to NULL initially
	return (EXIT_SUCCESS);
}

int philosophers(t_thread_manage *thread_manage,t_condition *condition)
{
	int i;
	t_philosopher philo;

	i = 1;
	while (i <= (thread_manage->num_of_philos))
	{
		mk_philosopher(&philo);
		init_philo(&philo, i, condition , thread_manage);
		if (pthread_create(&thread_manage->thread_id[i], NULL, &philosopher_routine, &philo) != 0)
		{
			perror("pthread_create error");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
