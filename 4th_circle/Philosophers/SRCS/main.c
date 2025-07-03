/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:41 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/03 20:06:01 by mkuida           ###   ########.fr       */
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

static void	set_condition(t_condition *condition ,int argc, char **argv)
{
	condition->num_of_philos = ft_atoi((const char*)argv[1]);
	condition->time_to_die = ft_atoi((const char*)argv[2]);
	condition->time_to_eat = ft_atoi((const char*)argv[3]);
	condition->time_to_sleep = ft_atoi((const char*)argv[4]);
	if (argc == 6)
	{
		condition->num_of_eat_times = ft_atoi((const char*)argv[5]);
		condition->optional_eat_times_flag = true;
	}
	else
	{
		condition->num_of_eat_times = -1;
		condition->optional_eat_times_flag = false;
	}
	
}

int	main(int argc, char **argv)
{
	t_condition	condition;

	if (check_args(argc,argv) == 1)
		return (1);
	set_condition(&condition, argc, argv);
	print_condition(&condition);
	
	return (0);
}
