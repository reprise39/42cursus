/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 04:32:12 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/21 18:33:51 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_data_mlx(t_data *data, char *map_path);
static void	set_data_img(t_data *data);
static void	set_data_img_x(t_data *data, char *xpm_path, t_img *img,
				const int *cutinfo);
void		cp_pixel(t_img full_data, t_img *cut_data, const int *cut);

t_data	*make_data(char *map_path)
{
	t_data	*data;

	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
	{
		perror("ft_calloc");
		return (NULL);
	}
	set_data_mlx(data, map_path);
	set_data_img(data);
	data->state = PLAYING;
	return (data);
}

static void	set_data_mlx(t_data *data, char *map_path)
{
	const int	map_height = get_map_height(map_path);
	const int	map_width = get_map_width(map_path);
	const int	window_width = map_width * TILE_SIZE;
	const int	window_height = map_height * TILE_SIZE;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
	{
		perror("mlx_init");
		exit(EXIT_FAILURE);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, window_width, window_height,
			"so_long");
	if (!data->win_ptr)
	{
		perror("mlx_new_window");
		exit(EXIT_FAILURE);
	}
}

static void	set_data_img(t_data *data)
{
	const int	cutinfo_player[4] = {0, 0, TILE_SIZE, TILE_SIZE};
	const int	cutinfo_asset[4] = {295, 210, TILE_SIZE, TILE_SIZE};
	const int	cutinfo_goal[4] = {984, 120, TILE_SIZE, TILE_SIZE};
	const int	cutinfo_floor[4] = {25, 25, TILE_SIZE, TILE_SIZE};
	const int	cutinfo_wall[4] = {0, 205, TILE_SIZE, TILE_SIZE};

	set_data_img_x(data, TEXTURES_PLAYER_PATH, &data->player_img,
		cutinfo_player);
	set_data_img_x(data, TEXTURES_ASSET_PATH, &data->asset_img, cutinfo_asset);
	set_data_img_x(data, TEXTURES_GOAL_PATH, &data->goal_img, cutinfo_goal);
	set_data_img_x(data, TEXTURES_PLAYER_PATH, &data->goal_on_player_img,
		cutinfo_player);
	set_data_img_x(data, TEXTURES_WALL_PATH, &data->wall_img, cutinfo_wall);
	set_data_img_x(data, TEXTURES_FLOOR_PATH, &data->floor_img, cutinfo_floor);
}

static void	set_data_img_x(t_data *data, char *xpm_path, t_img *img,
		const int *cut_info)
{
	t_img	full_data;

	full_data.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, xpm_path,
			&full_data.img_width, &full_data.img_height);
	if (!full_data.mlx_img)
		exit(EXIT_FAILURE);
	full_data.img_addr = mlx_get_data_addr(full_data.mlx_img, &full_data.bpp,
			&full_data.line_len, &full_data.endian);
	if (!full_data.img_addr)
		exit(EXIT_FAILURE);
	img->mlx_img = mlx_new_image(data->mlx_ptr, TILE_SIZE, TILE_SIZE);
	if (!img->mlx_img)
		exit(EXIT_FAILURE);
	img->img_addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len,
			&img->endian);
	if (!img->img_addr)
		exit(EXIT_FAILURE);
	cp_pixel(full_data, img, cut_info);
	mlx_destroy_image(data->mlx_ptr, full_data.mlx_img);
}

void	cp_pixel(t_img f_data, t_img *c_data, const int *cut)
{
	int	y;
	int	x;
	int	i;
	int	src_idx;
	int	dst_idx;

	y = 0;
	while (y < cut[3])
	{
		x = 0;
		while (x < cut[2])
		{
			src_idx = ((cut[1] + y) * f_data.line_len) + ((cut[0] + x)
					* (f_data.bpp / 8));
			dst_idx = (y * c_data->line_len) + (x * (f_data.bpp / 8));
			i = 0;
			while (i < (f_data.bpp / 8))
			{
				c_data->img_addr[dst_idx + i] = f_data.img_addr[src_idx + i];
				i++;
			}
			x++;
		}
		y++;
	}
}
