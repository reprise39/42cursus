/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_all_thread.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 20:01:59 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/06 00:03:40 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	wait_all_thread(t_simulation *simulation, pthread_t *monitor_thread_id)
{
	int	i;

	i = 0;
	while (i < (simulation->condition.num_of_philos))
	{
		if (pthread_join(simulation->thread_manage.thread_id[i], NULL) != 0)
		{
			perror("pthread_join error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (pthread_join(*monitor_thread_id, NULL) != 0)
	{
		perror("pthread_join error");
		exit(EXIT_FAILURE);
	}
}
