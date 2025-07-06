/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave_takefork.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:25:04 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 18:25:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	set_left_fork(int i, t_simulation *sim)
{
	if (i == 0)
		return (sim->condition.num_of_philos - 1);
	else
		return (i - 1);
}

int	set_first_fork(int philo_id, int right_fork, int left_fork)
{
	if ((philo_id - 1) % 2 == 0)
		return (right_fork);
	return (left_fork);
}

int	set_last_fork(int philo_id, int right_fork, int left_fork)
{
	if ((philo_id - 1) % 2 == 0)
		return (left_fork);
	return (right_fork);
}

bool	take_first_fork(t_simulation *sim, t_philosopher *philosopher,int first_fork)
{
	if (is_dead(sim))
		return (false);
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[first_fork]);
	if (is_dead(sim))
	{
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
		return (false);
	}
	print_take_fork(sim, philosopher->id);
	if (is_dead(sim))
	{
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
		return (false);
	}
	return (true);
}

bool	take_last_fork(t_simulation *sim, t_philosopher *philosopher,int first_fork,int last_fork)
{
	if (is_dead(sim))
	{
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
		return (false);
	}
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[last_fork]);
	if (is_dead(sim))
	{
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[last_fork]);
		return (false);
	}
	print_take_fork(sim, philosopher->id);
	if (is_dead(sim))
	{
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[last_fork]);
		return (false);
	}
	return (true);
}
