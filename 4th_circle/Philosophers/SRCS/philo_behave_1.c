/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:15:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 23:10:04 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	set_left_fork(int i, t_simulation *sim)
{
	if (i == 0)
		return (sim->condition.num_of_philos - 1);
	else
		return (i - 1);
}

static int	set_first_fork(int philo_id, int right_fork, int left_fork)
{
	if ((philo_id - 1) % 2 == 0)
		return (right_fork);
	return (left_fork);
}

static int	set_last_fork(int philo_id, int right_fork, int left_fork)
{
	if ((philo_id - 1) % 2 == 0)
		return (left_fork);
	return (right_fork);
}

bool	take_forks(t_simulation *sim, t_philosopher *philosopher)
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
		return (false);
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[first_fork]);
	printf("%ld_in_ms %d has taken (%d) fork\n",
		cal_mili_sec_time_now(&sim->start_time), philosopher->id, first_fork);
	if (is_dead(sim))
		return (false);
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[last_fork]);
	printf("%ld_in_ms %d has taken (%d) fork\n",
		cal_mili_sec_time_now(&sim->start_time), philosopher->id, last_fork);
	if (is_dead(sim))
		return (false);
	return (true);
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
	pthread_mutex_lock(&philosopher->last_eat_time_mutex);
	gettimeofday(&philosopher->last_eat_time, NULL);
	pthread_mutex_unlock(&philosopher->last_eat_time_mutex);
	printf("%ld_in_ms %d is eating\n", cal_mili_sec_time_now(&sim->start_time),
		philosopher->id);
	if (usleep_with_check(sim->condition.time_to_eat, sim) == false)
		return (false);
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[last_fork]);
	philosopher->num_of_eat_times++;
	if (check_end_must_eat(sim, (philosopher->num_of_eat_times)) == true)
		return (false);
	return (true);
}
