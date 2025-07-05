/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 11:35:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 11:35:24 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void *monitor_thread(void *arg)
{
	t_simulation *sim = (t_simulation *)arg;
	struct timeval now;
	long elapsed;
	int i;

	i = 0;
	while (true)
	{
		while (i < (sim->condition.num_of_philos))
		{
			t_philosopher *ph = &(sim->philosophers[i]);

			gettimeofday(&now, NULL);
			pthread_mutex_lock(&ph->last_eat_time_mutex);
			elapsed = (now.tv_sec - ph->last_eat_time.tv_sec) * 1000000
			        + (now.tv_usec - ph->last_eat_time.tv_usec);
			pthread_mutex_unlock(&ph->last_eat_time_mutex);

			if (elapsed > (sim->condition.time_to_die))
			{
				printf("%ld_in_ms %d died\n",cal_mili_sec_time(&sim->start_time, &now) ,ph->id);
				pthread_mutex_lock(&sim->is_dead_mutex);
				sim->is_dead = true; // 哲学者が死んだ場合、シミュレーションを終了
				pthread_mutex_unlock(&sim->is_dead_mutex);
				return (NULL);
			}
		}
		usleep(MONITOR_INTERVAL); // 監視間隔をミリ秒単位で設定
		i++;
	}
	return (NULL);
}

bool is_dead(t_simulation *sim)
{
	bool dead;

	pthread_mutex_lock(&sim->is_dead_mutex);
	dead = sim->is_dead;
	pthread_mutex_unlock(&sim->is_dead_mutex);
	return (dead);
}
