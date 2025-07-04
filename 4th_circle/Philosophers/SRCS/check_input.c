/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 07:06:45 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/03 07:06:45 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int check_argc_num(int argc)
{
	if(argc != 5 && argc != 6)
	{
		printf("input error : wrong number of arguments\n");
		printf("this app accept only 5 or 6 arguments (include appname)\n");
		printf("[1] ./philosophers\n[2] <number_of_philosophers>\n[3] ");
		printf("<time_to_die> \n[4] <time_to_eat> \n[5] <time_to_sleep>\n");
		printf("[6] {optionbal}<number_of_times_each_philosopher_must_eat>\n");
		return (1);
	}
	return (0);
}

int check_input_is_num(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (ft_isdigit_str((const char*)argv[i]) == 1)
		{
			printf("input error : argument %d is not number\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}

int check_input_is_posi_int(int argc, char **argv)
{
	int i;

	i = 1;
	while (i < argc)
	{
		if (!ft_isposiint_str(argv[i]))
		{
			printf("input error : argument %d is not positive int\n", i);
			return (1);
		}
		i++;
	}
	return (0);
}
