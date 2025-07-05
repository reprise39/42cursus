/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:41 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/05 20:42:32 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_args(int argc, char **argv)
{
	if (check_argc_num(argc) == 1)
		return (1);
	if (check_input_is_num(argc, argv) == 1)
		return (1);
	if ((check_input_is_posi_int(argc, argv)) == 1)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;
	pthread_t		monitor_thread_id;

	if (check_args(argc, argv) == 1)
		return (1);
	start_simulatuon(&simulation, argc, argv);
	if (philosophers(&simulation) == 1)
	{
		// thread syori
		return (EXIT_FAILURE);
	}
	if (pthread_create(&monitor_thread_id, NULL, &monitor_thread,
			&simulation) != 0)
	{
		return (EXIT_FAILURE);
	}
	wait_all_thread(&simulation, &monitor_thread_id);
	end_simulation(&simulation);
	printf("Simulation ended successfully.\n");
	return (0);
}
