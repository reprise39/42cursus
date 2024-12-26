/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2024/12/26 20:57:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h> // iro?
# include <fcntl.h>
# include "mlx.h"
# include "./libft_added_ftprintf/libft.h"

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFF
# define MLX_ERROR -1

//for_error
# define ERROR_MAP_EXISTS -1
# define ERROR_MAP_CHARACTOR -2
# define ERROR_MAP_SHAPE -3
# define ERROR_MAP_INWALL -4
# define ERROR_MAP_ELEMENTS -5
# define ERROR_MAP_CANT_PLAY -6



# define MAP_PATH "./maps.txt"

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

int check_map(void);

#endif