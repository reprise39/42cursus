/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 16:02:41 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/11 10:42:31 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char    *pixel;
// 	int		i;

// 	i = img->bpp - 8;
//     pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		/* big endian, MSB is the leftmost bit */
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		/* little endian, LSB is the leftmost bit */
// 		else
// 			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
// 		i -= 8;
// 	}
// }

/* The x and y coordinates of the rect corresponds to its upper left corner. */

// int render_rect(t_img *img, t_rect rect)
// {
// 	int	i;
// 	int j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

// void	render_background(t_img *img, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 		{
// 			img_pix_put(img, j++, i, color);
// 		}
// 		++i;
// 	}
// }



// int	render(t_data *data)
// {
// 	if (data->win_ptr == NULL)
// 		return (1);
// 	render_background(&data->img, WHITE_PIXEL);
// 	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100, 100, 100, GREEN_PIXEL});
// 	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
// 	render_rect(&data->img, (t_rect){50, 50, 100, 100, 0xFFFFFF});

// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
// 	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
// 	return (0);
// }


const char *get_error_message(int error_num) {
    const char *error_messages[] =
	{
		"Map error : Map no exist",
		"Map error : Charactor other {0,1,C,E,P} is anavaiable",
		"Map error : Map is need to be rector",
		"Map error : Map is need to be grounded wall (in map 1 indicate wall )",
		"Map error : Map is need to one {C,P} and more than one {P}",
		"Map error : Map is need to playable"
    };
    static const int num_errors = sizeof(error_messages) / sizeof(error_messages[0]);
	// ft_printf("num_errors = %d\n",num_errors);
    if (error_num < 0 || error_num >= num_errors) {
        return "Invalid error code";
    }
    return (error_messages[error_num]);
}


void print_error_message(int error_num)
{
	ft_printf("%s\n", get_error_message(error_num - 1));
}

int	main(void)
{
	int error_num;
	
	error_num = check_maps();
	if(error_num != 0 )
	{
		ft_printf("errornum = %d\n",error_num);
		print_error_message(error_num);
		return (-1);
	}
	error_num = check_textures();
	if(error_num != 0 )
	{
		return (-1);
	}
	error_num = exec_mlx();
	{
		if(error_num != 0 )
		{
			ft_printf("errornum = %d\n",error_num);
		}
	}
	return (0);
}
