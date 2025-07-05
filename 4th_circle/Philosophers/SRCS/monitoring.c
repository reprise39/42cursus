/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:35:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 21:43:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static long	cal_nomeal_miq_sec(t_philosopher *philo)
{
	long			total_sec;
	struct timeval	now;

	gettimeofday(&now, NULL);
	pthread_mutex_lock(&philo->last_eat_time_mutex);
	total_sec = cal_miq_sec_time(&philo->last_eat_time, &now);
	pthread_mutex_unlock(&philo->last_eat_time_mutex);
	return (total_sec);
}

static void	is_dead_set(t_simulation *sim)
{
	pthread_mutex_lock(&sim->is_dead_mutex);
	sim->is_dead = true;
	pthread_mutex_unlock(&sim->is_dead_mutex);
}

void	*monitor_thread(void *arg)
{
	t_simulation	*sim;
	long			no_meal_miq_time;
	t_philosopher	*philo;
	int				i;

	sim = (t_simulation *)arg;
	while (true)
	{
		i = 0;
		while (i < (sim->condition.num_of_philos))
		{
			philo = &(sim->philosophers[i]);
			no_meal_miq_time = cal_nomeal_miq_sec(philo);
			if (no_meal_miq_time > (sim->condition.time_to_die))
			{
				printf("%ld_in_ms %d died\n",
					cal_mili_sec_time_now(&sim->start_time), philo->id);
				is_dead_set(sim);
				return (NULL);
			}
		}
		usleep(MONITOR_INTERVAL);
		i++;
	}
	return (NULL);
}

bool	is_dead(t_simulation *sim)
{
	bool	dead;

	pthread_mutex_lock(&sim->is_dead_mutex);
	dead = sim->is_dead;
	pthread_mutex_unlock(&sim->is_dead_mutex);
	return (dead);
}
