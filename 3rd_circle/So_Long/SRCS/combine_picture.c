/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine_picture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 05:31:34 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/15 06:02:53 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void combine_images(void *mlx, t_img *base_img, t_img *added_img)
{
    int x, y;
    int bpp, line_length, endian;
    char *base_pixels = mlx_get_data_addr(base_img, &bpp, &line_length, &endian);
    char *added_pixels = mlx_get_data_addr(added_img, &bpp, &line_length, &endian);

    for (y = 0; y < TILE_SIZE; y++)
    {
        for (x = 0; x < TILE_SIZE; x++)
        {
            int pixel_offset = y * line_length + x * (bpp / 8);
            unsigned int added_color = *(unsigned int *)(added_pixels + pixel_offset);
            unsigned int base_color = *(unsigned int *)(base_pixels + pixel_offset);
            if (base_color == 0xFF000000 )
            {
                *(unsigned int *)(base_pixels + pixel_offset) = added_color;
            }
        }
    }
}
