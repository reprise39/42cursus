/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/04/16 04:01:41 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/Xlib.h> // iro?
# include <X11/keysym.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 42

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 900
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define WHITE_PIXEL 0xFFFF

// for_error
# define ERROR_MAP_EXISTS 1
# define ERROR_MAP_CHARACTOR 2
# define ERROR_MAP_SHAPE 3
# define ERROR_MAP_INWALL 4
# define ERROR_MAP_ELEMENTS 5
# define ERROR_MAP_CANT_PLAY 6

# define ERROR_TEXTURES_EXISTS 10
# define ERROR_TEXTURES_UNREADABLE 11

# define MLX_ERROR 50

# define MAP_PATH "./maps/map1.txt"

# define TEXTURES_PLAYER_PATH "./textures/food_merchant_spritesheet.xpm"
# define TEXTURES_ASSET_PATH "./textures/market_assets.xpm"
# define TEXTURES_GOAL_PATH "./textures/nature_assets.xpm"
# define TEXTURES_WALL_PATH "./textures/market_assets.xpm"
# define TEXTURES_FLOOR_PATH "./textures/cobblestone_tiles_brown.xpm"

# define TILE_SIZE 32

# ifndef MAP_H
#  include "map.h"
#  define MAP_H
# endif

typedef struct s_img
{
	void			*mlx_img;
	char			*img_addr;
	int				img_width;
	int				img_height;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef enum e_game_state
{
	PLAYING,
	GAME_CLEARED
}					t_game_state;

typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			player_img;
	t_img			asset_img;
	t_img			goal_img;
	t_img			goal_on_player_img;
	t_img			wall_img;
	t_img			floor_img;
	t_map			*map;
	t_game_state	state;
}					t_data;

// map_utils
int					get_map_width(void);
int					get_map_height(void);
int					check_map_number_of_char(char c);

// check_maps
int					check_maps(void);
int					map_check_exists(void);
int					map_check_charactor(void);
int					map_check_shape(void);

// check_maps_second
int					check_line(char *line, int my_height, int map_height,
						int map_width);
int					map_check_wall_at(int map_height, int map_width);
int					map_check_wall(void);
int					map_check_number_of_elements(void);

// check_maps_third
t_map				*mk_map_ptr(int x, int y);
t_map				*install_map(t_map *map_ptr, int x, int y);
int					map_check_isplayable(void);

// make_map.c
t_map				*make_map(void);

// free_map.c
void				free_map(t_map *map);

// check_textures
int					check_textures(void);

// so_long_utils
int					ft_in_charptr(char *ch, const char *charset);
int					ft_strchr_int(const char *s, int c);
void				initialize_int_ptr_array(int **ptr, int size);

// get_next_line main function
char				*get_next_line(int fd);
// get_next_line util functions
size_t				ft_strlen(const char *s);
char				*strjoin_and_free(char *freed_str, char const *added_str);
char				*ft_strdup(const char *s);

// mlx_put_image.c
void				mlx_put_image_start(t_data *data);

// mlx_exec.c
int					exec_mlx(void);

// make_data.c
t_data				*make_data(void);
void				cp_pixel(t_img full_data, t_img *cut_data, const int *cut);

// set_mlx_hook.c
void				set_mlx_hook(t_data *data);

// move_player.c
void				move_player(t_data *data, int y, int x);

// move_player_util.c
void				get_collectible(t_map *map, int y, int x);
void				goal(t_data *data);

// combine_picture.c
void				combine_image_group(t_data *data);
void				combine_images(void *mlx, t_img *under_img,
						t_img *upper_img);

#endif