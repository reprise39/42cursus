/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:41 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 21:20:31 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

const char	*get_error_message(int error_num)
{
	const char	*error_messages[] = {"Need one valid map-path-argument (.ber)",
		"Map error : Map no exist at given path",
		"Map error : Charactor other {0,1,C,E,P} is anavaiable",
		"Map error : Map is need to be rector",
		"Map error : Map is too big",
		"Map error : Map is need to be grounded wall (in map 1 indicate wall )",
		"Map error : Map is need to one {E,P} and at least one {C}",
		"Map error : Map is needed to be playable"};
	int			num_errors;

	num_errors = sizeof(error_messages) / sizeof(error_messages[0]);
	if (error_num < 0 || error_num >= num_errors)
	{
		return ("Invalid error code");
	}
	return (error_messages[error_num]);
}

static void	print_error_message(int error_num)
{
	ft_printf("Error\n%s\n", get_error_message(error_num - 1));
}

int	main(int argc, char **argv)
{
	int	error_num;

	error_num = check_textures();
	if (error_num != 0)
	{
		ft_printf("Error\n");
		ft_printf("Textures error : Texture no exist or cant read\n");
		return (-1);
	}
	error_num = check_maps(argc, argv);
	if (error_num != 0)
	{
		print_error_message(error_num);
		return (-1);
	}
	error_num = exec_mlx(argv[1]);
	{
		if (error_num != 0)
		{
			ft_printf("errornum = %d\n", error_num);
		}
	}
	return (0);
}
