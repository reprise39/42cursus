/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_behave_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 22:54:20 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 18:58:28 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	sleeping(t_simulation *sim, t_philosopher *philosopher)
{
	print_sleep(sim, philosopher->id);
	if (usleep_with_check(sim->condition.time_to_sleep, sim) == false)
		return (false);
	return (true);
}

bool	thinking(t_simulation *sim, t_philosopher *philosopher)
{
	print_think(sim, philosopher->id);
	if (usleep_with_check(THINK_INTERVAL, sim) == false)
		return (false);
	return (true);
}

void	check_end_must_eat(t_simulation *sim, int num_of_eat)
{
	if (sim->condition.optional_eat_times_flag == false)
		return ;
	if ((sim->condition.num_of_eat_times) == num_of_eat)
	{
		pthread_mutex_lock(&sim->fin_philo_num_mutex);
		sim->fin_philo_num++;
		pthread_mutex_unlock(&sim->fin_philo_num_mutex);
	}
	return ;
}
