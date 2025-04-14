/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 21:40:24 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/15 05:08:36 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void get_collectible(t_map *map,int y,int x);
static t_floor_state check_floor_type(t_map *map,int y,int x);
static void display_player_exist(t_data *data,t_map *map,int y,int x);
static void display_player_releave(t_data* data , t_map* map , int bef_y ,int bef_x);
static void goal(t_data *data);


void move_player(t_data *data,int y ,int x)
{
	t_map *map = data->map;
	t_floor_state next_floor_type;
	static int move_count = 0;
	
	next_floor_type = check_floor_type(map,(map->player_y)+y,(map->player_x)+x);
	if(next_floor_type == WALL)
		return;
	move_count++;
	ft_printf("move_count = %d\n", move_count);
	if(next_floor_type == EMPTY)
	{
		display_player_releave(data,map,map->player_y,map->player_x);
		map->player_x += x;
		map->player_y += y;
		display_player_exist(data,map,map->player_y,map->player_x);
	}
	else if(next_floor_type == COLLECTIBLE)
	{
		display_player_releave(data,map,map->player_y,map->player_x);
		map->player_x += x;
		map->player_y += y;
		get_collectible(map,x,y);
		display_player_exist(data,map,map->player_y,map->player_x);
	}
	else if(next_floor_type == EXIT)
	{
		display_player_releave(data,map,map->player_y,map->player_x);
		if(map->collectible_count_total == map->collectible_count_current)
			goal(data);
		else
		{
			map->player_x += x;
			map->player_y += y;
			display_player_exist(data,map,map->player_y,map->player_x);
		}
	}
	else
	{
		perror("move_to_nowhere");
		exit(1);
	}
}


static t_floor_state check_floor_type(t_map *map,int y,int x)
{
	t_floor_state ans;
	if (y < 0 && y >= map->map_height && x < 0 && x >= map->map_width)
	{
		perror("check_floor_type");
		exit (1);
	}
	else
	{
		ans = map->contents[y][x].floor_type;
		return (ans);
	}
}





static void display_player_releave(t_data* data , t_map* map , int bef_y ,int bef_x)
{
	t_floor_state floor_type;
	floor_type = check_floor_type(map,bef_y,bef_x);

	if(floor_type == EXIT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->goal_img.mlx_img, bef_x * TILE_SIZE, bef_y * TILE_SIZE);
		return;
	}
	else if(floor_type == EMPTY )
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->floor_img.mlx_img, bef_x * TILE_SIZE, bef_y * TILE_SIZE);
		return;
	}
	else
	{
		perror("display_player_releave");
		exit(1);
	}
}


static void display_player_exist(t_data *data,t_map *map,int y,int x)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->player_img.mlx_img, x * TILE_SIZE, y * TILE_SIZE);
}

static void get_collectible(t_map *map,int y,int x)
{
	map->collectible_count_current++;
	map->contents[map->player_y][map->player_x].floor_type = EMPTY;
}

static void goal(t_data *data)
{
	data->state = GAME_CLEARED;
	ft_printf("Congratulation!! You clear the game! Please close window\n");
	return;
}