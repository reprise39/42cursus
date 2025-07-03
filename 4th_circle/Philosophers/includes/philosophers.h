/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 15:50:31 by mkuida            #+#    #+#             */
/*   Updated: 2025/07/03 18:43:50 by mkuida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 42

# include <sys/time.h> // gettimeofday
# include <fcntl.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h> // memset
# include <unistd.h>
# include <stdbool.h>

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

# define MAP_PATH "./maps/map.ber"

# define TEXTURES_PLAYER_PATH "./textures/food_merchant_spritesheet.xpm"
# define TEXTURES_ASSET_PATH "./textures/market_assets.xpm"
# define TEXTURES_GOAL_PATH "./textures/nature_assets.xpm"
# define TEXTURES_WALL_PATH "./textures/market_assets.xpm"
# define TEXTURES_FLOOR_PATH "./textures/cobblestone_tiles_brown.xpm"

# define TILE_SIZE 32

typedef struct s_condition
{
	int				num_of_philos;
	suseconds_t		time_to_die;
	suseconds_t		time_to_eat;
	suseconds_t		time_to_sleep;
	int				num_of_eat_times;
	bool			optional_eat_times_flag;
}					t_condition;

typedef enum e_game_state
{
	PLAYING,
	GAME_CLEARED
}					t_game_state;



// check_input.c
int					check_argc_num(int argc);
int					check_input_is_num(int argc, char **argv);
int					check_input_is_posi_int(int argc, char **argv);

// ft_is_int.c
int					ft_isdigit_str(const char *str);
int					ft_isposiint_str(const char *str);

// utils.c
int					ft_is_spase(char c);
int					ft_is_digit(const char str);
int					ft_strlen(const char *str);
void				ft_hyper_usleep(useconds_t timer);
int 				ft_atoi(const char *str);

// for_debag.c
void				print_condition(t_condition *condition);

#endif