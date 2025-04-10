/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:14:19 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/11 08:55:22 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exec_mlx()
{
	t_data *data;
	data = make_data();
	if(data == NULL)
	{
		perror("make_data");
		exit(EXIT_FAILURE);
	}
	
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img.mlx_img, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->asset_img.mlx_img, 32, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->goal_img.mlx_img, 0, 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_img.mlx_img, 32, 32);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img.mlx_img, 64, 0);
	
	mlx_loop(data->mlx_ptr);
	return (0);
}
