/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/02/12 16:33:55 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h> // iro?
# include <stdint.h>
# include <fcntl.h>
# include "mlx.h"
# include "libft.h"


# define BUFFER_SIZE 42

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFF
# define MLX_ERROR -2

//for_error
# define ERROR_MAP_EXISTS 1
# define ERROR_MAP_CHARACTOR 2
# define ERROR_MAP_SHAPE 3
# define ERROR_MAP_INWALL 4
# define ERROR_MAP_ELEMENTS 5
# define ERROR_MAP_CANT_PLAY 6

# define ERROR_TEXTURES_EXISTS 10

# define MAP_PATH "./maps/map1.txt"
# define TEXTURES_MAP_PATH "./textures/cobblestone_tiles_brown.xpm"
# define TEXTURES_PLAYER_PATH "./textures/food_merchant_spritesheet.xpm"
# define TEXTURES_ASSET_PATH "./textures/market_assets.xpm"

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;


//map_utils
int get_map_width();
int get_map_height();
int check_map_number_of_char(char c);

// check_maps
int check_maps(void);
int map_check_exists();
int map_check_charactor();
int map_check_shape();

// check_maps_second
int check_line(char *line,int my_height,int map_height,int map_width);
int map_check_wall_at(int map_height,int map_width);
int map_check_wall();
int map_check_number_of_elements();



// check_textures
int check_textures(void);

//so_long_utils
int ft_in_charptr(char *ch,const char *charset);
int	ft_strchr_int(const char *s, int c);
void initialize_int_ptr_array(int **ptr,int size);

//get_next_line main function
char	*get_next_line(int fd);
//get_next_line util functions
size_t	ft_strlen(const char *s);
char	*strjoin_and_free(char *freed_str, char const *added_str);
char	*ft_strdup(const char *s);

#endif