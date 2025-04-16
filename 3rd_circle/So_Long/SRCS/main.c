/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:41 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 17:37:56 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*get_error_message(int error_num)
{
	const char			*error_messages[] = {"Map error : Map no exist",
		"Map error : Charactor other {0,1,C,E,P} is anavaiable",
		"Map error : Map is need to be rector",
		"Map error : Map is need to be grounded wall (in map 1 indicate wall )",
		"Map error : Map is need to one {E,P} and at least one {C}",
		"Map error : Map is needed to be playable"};
	static const int	num_errors = sizeof(error_messages)
		/ sizeof(error_messages[0]);

	if (error_num < 0 || error_num >= num_errors)
	{
		return ("Invalid error code");
	}
	return (error_messages[error_num]);
}

static void	print_error_message(int error_num)
{
	ft_printf("%s\n", get_error_message(error_num - 1));
}

int	main(void)
{
	int	error_num;

	error_num = check_maps();
	if (error_num != 0)
	{
		ft_printf("errornum = %d\n", error_num);
		print_error_message(error_num);
		return (-1);
	}
	error_num = check_textures();
	if (error_num != 0)
	{
		ft_printf("errornum = %d\n", error_num);
		ft_printf("Textures error : Texture no exist or cant read\n");
		return (-1);
	}
	error_num = exec_mlx();
	{
		if (error_num != 0)
		{
			ft_printf("errornum = %d\n", error_num);
		}
	}
	return (0);
}
