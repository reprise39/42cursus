/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/11 09:03:54 by mkuida           ###   ########.fr       */
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

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFF


//for_error
# define ERROR_MAP_EXISTS 1
# define ERROR_MAP_CHARACTOR 2
# define ERROR_MAP_SHAPE 3
# define ERROR_MAP_INWALL 4
# define ERROR_MAP_ELEMENTS 5
# define ERROR_MAP_CANT_PLAY 6

# define ERROR_TEXTURES_EXISTS 10

# define MLX_ERROR 50

# define MAP_PATH "./maps/map1.txt"

# define TEXTURES_PLAYER_PATH "./textures/food_merchant_spritesheet.xpm"
# define TEXTURES_ASSET_PATH "./textures/market_assets.xpm"
# define TEXTURES_GOAL_PATH "./textures/nature_assets.xpm"
# define TEXTURES_WALL_PATH "./textures/market_assets.xpm"
# define TEXTURES_FLOOR_PATH "./textures/cobblestone_tiles_brown.xpm"

# define TILE_SIZE 32

// x_ofset,y_ofset,cut_width,cut_height
# define CUT_FOR_PLAYER {0,0,TILE_SIZE,TILE_SIZE}
# define CUT_FOR_ASSET {295,210,TILE_SIZE,TILE_SIZE}
# define CUT_FOR_GOAL {984,120,TILE_SIZE,TILE_SIZE}
# define CUT_FOR_WALL {0,205,TILE_SIZE,TILE_SIZE}
# define CUT_FOR_FLOOR {25,25,TILE_SIZE,TILE_SIZE}

typedef struct s_img
{
    void	*mlx_img;
    char	*img_addr;
	int 	img_width;
	int 	img_height;
    int		bpp;
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_data
{
    void	*mlx_ptr;
    void	*win_ptr;
	t_img	player_img;
	t_img	asset_img;
	t_img	goal_img;
	t_img 	wall_img;
	t_img	floor_img;	
}	t_data;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

# ifndef MAP_H
#  include "map.h"
#  define MAP_H
# endif

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

// check_maps_third
t_map* mk_map_ptr(int x,int y);
t_map* install_map(t_map* map_ptr,int x,int y);
int map_check_isplayable();

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

// mlx_exec.c
int exec_mlx(void);

// make_data.c
t_data *make_data(void);

// set_mlx_hook.c
void set_mlx_hook(t_data *data);

#endif