/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mlx_hook.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 09:02:38 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 01:02:37 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_close(t_data *data);
static int	key_handle(int keysym, t_data *data);

static int	destroy_image_before_close(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->player_img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->asset_img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->goal_img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->wall_img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->floor_img.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->goal_on_player_img.mlx_img);
}

static int	expose_hook(t_data *data)
{
	static int	first_time = 1;

	if (first_time == 1)
	{
		first_time = 0;
		return (0);
	}
	handle_close(data);
}

static int	handle_close(t_data *data)
{
	destroy_image_before_close(data);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->win_ptr = NULL;
	free(data->mlx_ptr);
	free_map(data->map);
	free(data);
	exit(0);
}

void	set_mlx_hook(t_data *data)
{
	mlx_hook(data->win_ptr, Expose, ExposureMask, &expose_hook, data);
	mlx_hook(data->win_ptr, DestroyNotify, StructureNotifyMask, &handle_close,
		data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_handle, data);
}

static int	key_handle(int keysym, t_data *data)
{
	if (keysym == (int) 's' && data->state == PLAYING)
		move_player(data, 1, 0);
	else if (keysym == (int) 'a' && data->state == PLAYING)
		move_player(data, 0, -1);
	else if (keysym == (int) 'w' && data->state == PLAYING)
		move_player(data, -1, 0);
	else if (keysym == (int) 'd' && data->state == PLAYING)
		move_player(data, 0, 1);
	else if (keysym == XK_Escape)
		handle_close(data);
	return (0);
}
