/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:40:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 19:58:54 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_floor_state	check_floor_type(t_map *map, int y, int x);
static void				display_player_exist(t_data *data, t_map *map, int y,
							int x);
static void				display_player_releave(t_data *data, t_map *map,
							int bef_y, int bef_x);

static void				move_to(t_data *data, int y, int x,
							t_floor_state next_floor_type);

void	move_player(t_data *data, int y, int x)
{
	t_map			*map;
	t_floor_state	next_floor_type;
	static int		move_count = 0;

	map = data->map;
	next_floor_type = check_floor_type(map, (map->player_y) + y, (map->player_x)
			+ x);
	if (next_floor_type == WALL)
		return ;
	move_count++;
	ft_printf("move_count = %d\n", move_count);
	move_to(data, y, x, next_floor_type);
}

static void	move_to(t_data *data, int y, int x, t_floor_state next_floor_type)
{
	t_map	*map;

	map = data->map;
	display_player_releave(data, map, map->player_y, map->player_x);
	if (next_floor_type == EXIT
		&& map->collectible_count_total == map->collectible_count_current)
		goal(data);
	map->player_x += x;
	map->player_y += y;
	if (next_floor_type == COLLECTIBLE)
		get_collectible(map);
	display_player_exist(data, map, map->player_y, map->player_x);
}

static t_floor_state	check_floor_type(t_map *map, int y, int x)
{
	t_floor_state	ans;

	if (y < 0 && y >= map->map_height && x < 0 && x >= map->map_width)
	{
		perror("check_floor_type");
		exit(1);
	}
	else
	{
		ans = map->contents[y][x].floor_type;
		return (ans);
	}
}

static void	display_player_releave(t_data *data, t_map *map, int bef_y,
		int bef_x)
{
	t_floor_state	floor_type;

	floor_type = check_floor_type(map, bef_y, bef_x);
	if (floor_type == EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->goal_img.mlx_img, bef_x * TILE_SIZE, bef_y * TILE_SIZE);
		return ;
	}
	else if (floor_type == EMPTY)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img.mlx_img, bef_x * TILE_SIZE, bef_y * TILE_SIZE);
		return ;
	}
	else
	{
		perror("display_player_releave");
		exit(1);
	}
}

static void	display_player_exist(t_data *data, t_map *map, int y, int x)
{
	t_floor_state	floor_type;

	floor_type = check_floor_type(map, y, x);
	if (floor_type == EMPTY)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player_img.mlx_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (floor_type == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->goal_on_player_img.mlx_img, x * TILE_SIZE, y * TILE_SIZE);
	else
	{
		perror("display_player_exist");
		exit(1);
	}
}
