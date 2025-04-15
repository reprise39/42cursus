/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_picture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 05:31:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 03:49:27 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	combine_image_group(t_data *data)
{
	combine_images(data->mlx_ptr, &data->wall_img, &data->floor_img);
	combine_images(data->mlx_ptr, &data->player_img, &data->floor_img);
	combine_images(data->mlx_ptr, &data->asset_img, &data->floor_img);
	combine_images(data->mlx_ptr, &data->goal_img, &data->floor_img);
	combine_images(data->mlx_ptr, &data->goal_on_player_img, &data->goal_img);
}

void	combine_images(void *mlx, t_img *b_img, t_img *a_img)
{
	int				base_offset;
	int				added_offset;
	unsigned int	base_color;
	int				x;
	int				y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			base_offset = y * (b_img->line_len) + x * ((b_img->bpp) / 8);
			added_offset = y * (a_img->line_len) + x * ((a_img->bpp) / 8);
			base_color = *(unsigned int *)((b_img->img_addr) + base_offset);
			if (base_color == 0xFF000000)
				*(unsigned int *)((b_img->img_addr)
						+ base_offset) = *(unsigned int *)((a_img->img_addr)
						+ added_offset);
			x++;
		}
		y++;
	}
}
