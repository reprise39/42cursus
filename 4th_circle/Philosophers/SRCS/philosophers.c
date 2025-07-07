/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 09:34:56 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/07 22:33:21 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	set_philo_born_time(t_philosopher *philosopher)
{
	if (pthread_mutex_lock_s(&philosopher->last_eat_time_mutex) == EXIT_FAILURE)
		return (false);
	if (gettimeofday_s(&philosopher->last_eat_time, NULL) == EXIT_FAILURE)
		return (false);
	if (pthread_mutex_unlock_s(&philosopher->last_eat_time_mutex)
		== EXIT_FAILURE)
		return (false);
	return (true);
}

static void	do_cicle(t_simulation *sim, t_philosopher *philosopher)
{
	if (set_philo_born_time(philosopher) == false)
	{
		printf("do_cicle initialize error\n");
		is_dead_set(sim);
		return ;
	}
	while (1)
	{
		if (take_forks(sim, philosopher) == false)
			return ;
		if (eating(sim, philosopher) == false)
			return ;
		if (sleeping(sim, philosopher) == false)
			return ;
		if (thinking(sim, philosopher) == false)
			return ;
	}
}

void	*philosopher_routine(void *arg)
{
	static int		i = -1;
	t_simulation	*sim;

	i++;
	sim = (t_simulation *)arg;
	do_cicle(sim, &(sim->philosophers[i]));
	return (NULL);
}

int	philosophers(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < (sim->condition.num_of_philos))
	{
		if (pthread_create(&sim->thread_manage.thread_id[i], NULL,
				&philosopher_routine, sim) != 0)
		{
			printf("pthread_create error");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
