/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:15:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/08 10:51:59 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static bool	mutex_unlock_forks(t_simulation *sim, int fork_a, int fork_b)
{
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[fork_a]);
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[fork_b]);
	return (false);
}

static void	set_ate_time(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->last_eat_time_mutex);
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(&philo->last_eat_time_mutex);
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
	if (is_dead(sim))
		return (mutex_unlock_forks(sim, first_fork, last_fork));
	set_ate_time(philosopher);
	print_eat(sim, philosopher->id);
	if (usleep_with_check(sim->condition.time_to_eat, sim) == false)
		return (mutex_unlock_forks(sim, first_fork, last_fork));
	mutex_unlock_forks(sim, first_fork, last_fork);
	philosopher->num_of_eat_times++;
	check_end_must_eat(sim, (philosopher->num_of_eat_times));
	if (is_dead(sim))
		return (mutex_unlock_forks(sim, first_fork, last_fork));
	return (true);
}

bool	take_forks_solo(t_simulation *sim, t_philosopher *philosopher)
{
	if (is_dead(sim))
		return (false);
	print_take_fork(sim, philosopher->id);
	while (1)
	{
		pthread_mutex_lock(&sim->is_dead_mutex);
		if (sim->is_dead == true)
		{
			pthread_mutex_unlock(&sim->is_dead_mutex);
			return (false);
		}
		pthread_mutex_unlock(&sim->is_dead_mutex);
		usleep(SOLO_MONITOR_INTERVAL);
	}
}

bool	take_forks(t_simulation *sim, t_philosopher *philosopher)
{
	int	right_fork;
	int	left_fork;
	int	first_fork;
	int	last_fork;

	if (is_dead(sim))
		return (false);
	right_fork = ((philosopher->id) - 1);
	left_fork = set_left_fork((philosopher->id) - 1, sim);
	first_fork = set_first_fork((philosopher->id), right_fork, left_fork);
	last_fork = set_last_fork((philosopher->id), right_fork, left_fork);
	if (first_fork == last_fork)
		return (take_forks_solo(sim, philosopher));
	if (take_first_fork(sim, philosopher, first_fork) == false)
		return (false);
	if (take_last_fork(sim, philosopher, first_fork, last_fork) == false)
		return (false);
	return (true);
}
