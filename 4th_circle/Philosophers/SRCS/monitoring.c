/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:35:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/08 10:13:46 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	cal_nomeal_miq_sec(t_philosopher *philo)
{
	long			total_sec;

	pthread_mutex_lock(&philo->last_eat_time_mutex);
	total_sec = cal_miq_sec_time_now(&philo->last_eat_time);
	pthread_mutex_unlock(&philo->last_eat_time_mutex);
	return (total_sec);
}

void	is_dead_set(t_simulation *sim)
{
	pthread_mutex_lock(&sim->is_dead_mutex);
	sim->is_dead = true;
	pthread_mutex_unlock(&sim->is_dead_mutex);
}

bool	is_dead(t_simulation *sim)
{
	bool	dead;

	pthread_mutex_lock(&sim->is_dead_mutex);
	dead = sim->is_dead;
	pthread_mutex_unlock(&sim->is_dead_mutex);
	return (dead);
}

static bool	check_all_philo_ate(t_simulation *sim)
{
	pthread_mutex_lock(&sim->fin_philo_num_mutex);
	if (sim->fin_philo_num == sim->condition.num_of_philos)
	{
		pthread_mutex_unlock(&sim->fin_philo_num_mutex);
		return (true);
	}
	pthread_mutex_unlock(&sim->fin_philo_num_mutex);
	return (false);
}

void	*monitor_thread(void *arg)
{
	t_simulation	*sim;
	int				i;

	sim = (t_simulation *)arg;
	while (true)
	{
		i = 0;
		while (i < (sim->condition.num_of_philos))
		{
			if (cal_nomeal_miq_sec(&sim->philosophers[i]) > \
				(sim->condition.time_to_die))
			{
				print_die(sim, sim->philosophers[i].id);
				is_dead_set(sim);
				return (NULL);
			}
			i++;
		}
		if (check_all_philo_ate(sim) == true)
		{
			is_dead_set(sim);
			return (NULL);
		}
		usleep(MONITOR_INTERVAL);
	}
}
