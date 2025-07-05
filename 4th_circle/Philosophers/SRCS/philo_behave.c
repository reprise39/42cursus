/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:15:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 10:15:34 by mkuida           ###   ########.fr       */
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

bool	take_forks(t_simulation *sim, t_philosopher *philosopher)
{
	int				right_fork;
	int				left_fork;
	int				first_fork;
	int				last_fork;
	struct timeval	current_time;

	right_fork = ((philosopher->id) - 1);
	left_fork = set_left_fork((philosopher->id) - 1, sim);
	if (((philosopher->id) - 1) % 2 == 0)
	{
		first_fork = right_fork;
		last_fork = left_fork;
	}
	else
	{
		first_fork = left_fork;
		last_fork = right_fork;
	}
	if (is_dead(sim))
		return (false);
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[first_fork]);
	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d has taken (%d) fork\n",
		cal_mili_sec_time(&sim->start_time, &current_time), philosopher->id,
		first_fork);
	if (is_dead(sim))
		return (false);
	pthread_mutex_lock(&sim->thread_manage.forks_mutex[last_fork]);
	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d has taken (%d) fork\n",
		cal_mili_sec_time(&sim->start_time, &current_time), philosopher->id,
		last_fork);
	if (is_dead(sim))
		return (false);
	return (true);
}

bool	eating(t_simulation *sim, t_philosopher *philosopher)
{
	int				right_fork;
	int				left_fork;
	int				first_fork;
	int				last_fork;
	struct timeval	current_time;

	right_fork = ((philosopher->id) - 1);
	left_fork = set_left_fork((philosopher->id) - 1, sim);
	if (((philosopher->id) - 1) % 2 == 0)
	{
		first_fork = right_fork;
		last_fork = left_fork;
	}
	else
	{
		first_fork = left_fork;
		last_fork = right_fork;
	}
	pthread_mutex_lock(&philosopher->last_eat_time_mutex);
	gettimeofday(&philosopher->last_eat_time, NULL);
	pthread_mutex_unlock(&philosopher->last_eat_time_mutex);
	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d is eating\n", cal_mili_sec_time(&sim->start_time,
			&current_time), philosopher->id);
	if (usleep_with_check(sim->condition.time_to_eat, sim) == false)
	{
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
		pthread_mutex_unlock(&sim->thread_manage.forks_mutex[last_fork]);
		return (false); // Exit if usleep fails
	}
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[first_fork]);
	pthread_mutex_unlock(&sim->thread_manage.forks_mutex[last_fork]);
	philosopher->num_of_eat_times++;
	if (sim->condition.optional_eat_times_flag == 1
		&& philosopher->num_of_eat_times == sim->condition.num_of_eat_times)
	{
		printf("Philosopher %d has finished eating %d times\n ~fin~ \n",
			philosopher->id, philosopher->num_of_eat_times);
		pthread_exit(NULL);
			// Exit the thread if the philosopher has eaten enough
	}
	return (true);
}

bool	sleeping(t_simulation *sim, t_philosopher *philosopher)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d is sleeping\n", cal_mili_sec_time(&sim->start_time,
			&current_time), philosopher->id);
	if (usleep_with_check(sim->condition.time_to_sleep, sim) == false)
	{
		return (false);
	}
	return (true);
}

bool	thinking(t_simulation *sim, t_philosopher *philosopher)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d is thinking\n", cal_mili_sec_time(&sim->start_time,
			&current_time), philosopher->id);
	if (usleep_with_check(THINK_INTERVAL, sim) == false)
	{
		return (false); // Exit if usleep fails
	}
	return (true);
}
