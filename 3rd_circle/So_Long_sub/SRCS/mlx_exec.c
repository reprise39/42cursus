/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:14:19 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 18:33:27 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exec_mlx(char *map_path)
{
	t_data	*data;

	data = make_data(map_path);
	if (data == NULL)
	{
		perror("make_data");
		exit(EXIT_FAILURE);
	}
	data->map = make_map(map_path);
	if (data->map == NULL)
	{
		perror("make_map");
		exit(EXIT_FAILURE);
	}
	combine_image_group(data);
	mlx_put_image_start(data);
	set_mlx_hook(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
