/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:54:20 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 22:54:20 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	sleeping(t_simulation *sim, t_philosopher *philosopher)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d is sleeping\n", cal_mili_sec_time(&sim->start_time,
			&current_time), philosopher->id);
	if (usleep_with_check(sim->condition.time_to_sleep, sim) == false)
		return (false);
	return (true);
}

bool	thinking(t_simulation *sim, t_philosopher *philosopher)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	printf("%ld_in_ms %d is thinking\n", cal_mili_sec_time(&sim->start_time,
			&current_time), philosopher->id);
	if (usleep_with_check(THINK_INTERVAL, sim) == false)
		return (false);
	return (true);
}

bool	check_end_must_eat(t_simulation *sim, int num_of_eat)
{
	if (sim->condition.optional_eat_times_flag == false)
		return (false);
	if (sim->condition.num_of_eat_times <= num_of_eat)
		return (true);
	return (false);
}
