/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:18:26 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 02:03:30 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	end_thread_manage(t_thread_manage *thread_manage)
{
	int	i;

	i = 0;
	while (i < (thread_manage->num_of_philos))
	{
		if (pthread_mutex_destroy(&thread_manage->forks_mutex[i]) != 0)
		{
			perror("pthread_mutex_destroy error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(thread_manage->forks_mutex);
	free(thread_manage->thread_id);
}

static void	end_philosophers(t_simulation *sim)
{
	int i;
	i = 0;
	while (i < (sim->condition.num_of_philos))
	{
		if(pthread_mutex_destroy(&(sim->philosophers[i].last_eat_time_mutex)) != 0){
			perror("pthread_mutex_destroy error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	free(sim->philosophers);
}

void	end_simulation(t_simulation *simulation)
{
	end_thread_manage(&simulation->thread_manage);
	end_philosophers(simulation);
	if (pthread_mutex_destroy(&simulation->is_dead_mutex) != 0)
	{
		perror("pthread_mutex_destroy error");
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_destroy(&simulation->is_print_mutex) != 0)
	{
		perror("pthread_mutex_destroy error");
		exit(EXIT_FAILURE);
	}
}
