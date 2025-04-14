/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_put_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 07:26:26 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/15 05:37:31 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void mlx_put_image_start(t_data *data)
{
	int i;
	int j;
	
	i=0;
	while(i < data->map->map_height)
	{
		j=0;
		while(j < data->map->map_width)
		{
			if (data->map->contents[i][j].floor_type == WALL)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall_img.mlx_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map->contents[i][j].floor_type == EMPTY)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img.mlx_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map->contents[i][j].floor_type == COLLECTIBLE)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->asset_img.mlx_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map->contents[i][j].floor_type == PLAYER)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img.mlx_img, j * TILE_SIZE, i * TILE_SIZE);
			else if (data->map->contents[i][j].floor_type == EXIT)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->goal_img.mlx_img, j * TILE_SIZE, i * TILE_SIZE);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img.mlx_img, ((data->map->player_x) * TILE_SIZE) , ((data->map->player_y) * TILE_SIZE));
}
