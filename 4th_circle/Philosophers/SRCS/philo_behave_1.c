/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:15:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 18:57:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	mutex_unlock_forks(t_simulation *sim,int fork_a ,int fork_b)
{
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[fork_a]);
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[fork_b]);
}

bool	eating(t_simulation *sim, t_philosopher *philosopher)
{
	int	right_fork;
	int	left_fork;
	int	first_fork;
	int	last_fork;

	right_fork = ((philosopher->id) - 1);
	left_fork = set_left_fork((philosopher->id) - 1, sim);
	first_fork = set_first_fork((philosopher->id), right_fork, left_fork);
	last_fork = set_last_fork((philosopher->id), right_fork, left_fork);
	print_eat(sim, philosopher->id);
	if (usleep_with_check(sim->condition.time_to_eat, sim) == false)
	{
		mutex_unlock_forks(sim,first_fork,last_fork);
		return (false);
	}
	mutex_unlock_forks(sim,first_fork,last_fork);
	philosopher->num_of_eat_times++;
	check_end_must_eat(sim, (philosopher->num_of_eat_times));
	if (is_dead(sim))
	{
		mutex_unlock_forks(sim,first_fork,last_fork);
		return (false);
	}
	return (true);
}
