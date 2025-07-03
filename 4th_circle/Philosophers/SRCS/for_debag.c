/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_debag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:41:00 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/03 18:41:00 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_condition(t_condition *condition)
{
	printf("number_of_philosophers: %d\n", condition->num_of_philos);
	printf("time_to_die: %ld\n", condition->time_to_die);
	printf("time_to_eat: %ld\n", condition->time_to_eat);
	printf("time_to_sleep: %ld\n", condition->time_to_sleep);
	if (condition->optional_eat_times_flag)
		printf("number_of_times_each_philosopher_must_eat: %d\n",
			condition->num_of_eat_times);
	else
		printf("number_of_times_each_philosopher_must_eat: not set\n");
}
