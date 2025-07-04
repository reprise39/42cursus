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

int set_reft_fork(int i, t_simulation *sim)
{
	if (i == 0)
		return (sim->condition.num_of_philos - 1);
	else
		return (i - 1);
}

static void take_forks(t_simulation *sim, t_philosopher *philosopher)
{
	int right_fork;
	int left_fork;
	int first_fork;
	int last_fork;

	right_fork = ((philosopher->id)-1);
	left_fork = set_reft_fork((philosopher->id)-1, sim);
	if (((philosopher->id)-1) % 2 == 0)
	{
		first_fork = right_fork;
		last_fork = left_fork;
	}
	else
	{
		first_fork = left_fork;
		last_fork = right_fork;
	}
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[first_fork]);
	printf("Philosopher %d has taken (%d) fork\n", philosopher->id , first_fork);
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[last_fork]);
	printf("Philosopher %d has taken (%d) fork\n", philosopher->id ,last_fork);
}
static void eating(t_simulation *sim, t_philosopher *philosopher)
{
	int right_fork;
	int left_fork;
	int first_fork;
	int last_fork;

	right_fork = ((philosopher->id)-1);
	left_fork = set_reft_fork((philosopher->id)-1, sim);
	if (((philosopher->id)-1) % 2 == 0)
	{
		first_fork = right_fork;
		last_fork = left_fork;
	}
	else
	{
		first_fork = left_fork;
		last_fork = right_fork;
	}
	printf("Philosopher %d is eating\n", philosopher->id);
	usleep(sim->condition.time_to_eat); // Simulate eating time
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[last_fork]);
}

static void sleeping(t_simulation *sim, t_philosopher *philosopher)
{
	printf("Philosopher %d is sleeping\n", philosopher->id);
	usleep(sim->condition.time_to_sleep); // Simulate sleeping time
}

static void thinking(t_philosopher *philosopher)
{
	printf("Philosopher %d is thinking\n", philosopher->id);
	usleep(200); // Simulate thinking time
}

static void	do_cicle(t_simulation *sim, t_philosopher *philosopher)
{
	while (1)
	{
		take_forks(sim, philosopher);
		eating(sim, philosopher);
		sleeping(sim, philosopher);
		thinking(philosopher);
	}
}

void	*philosopher_routine(void *arg)
{
	static int i = -1;

	i++;
	t_simulation *sim = (t_simulation *)arg;
	// printf("I am philosopher %d\n", i);
	// printf(" %d\n", sim->condition.num_of_philos);
	do_cicle(sim,&(sim->philosophers[i]));
	return (NULL);
}

int philosophers(t_simulation *sim)
{
	int i;

	i = 0;
	while (i < (sim->condition.num_of_philos))
	{
		if (pthread_create(&sim->thread_manage.thread_id[i], NULL, &philosopher_routine, sim) != 0)
		{
			perror("pthread_create error");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
