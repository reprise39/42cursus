# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkuida <reprise39@yahoo.co.jp>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/18 19:33:28 by mkuida            #+#    #+#              #
#    Updated: 2024/11/18 19:33:28 by mkuida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./SRCS
OBJ_DIR = ./OBJS

LIBFT_DIR = ./libft_added_ftprintf
LIBFT = $(LIBFT_DIR)/libft.a

MINILIBX_DIR = ./minilibx
MINILIBX = $(MINILIBX_DIR)/libmlx.a

INCLUDES = -I includes -I$(MINILIBX_DIR) -I$(LIBFT_DIR)/includes
LDFLAGS = -L$(LIBFT_DIR) -lft -L$(MINILIBX_DIR) -lmlx -L/usr/local/lib -lXext -lX11 -lm

SRC_FILES = main.c \
			so_long_utils.c \
			make_map.c \
			free_map.c \
			map_utils.c \
			check_maps.c \
			check_maps_second.c \
			check_maps_third.c \
			bfs_utils.c \
			queue_utils.c \
			check_textures.c \
			get_next_line.c \
			get_next_line_utils.c \
			mlx_put_image.c \
			mlx_exec.c \
			make_data.c \
			set_mlx_hook.c \
			move_player.c \
			move_player_util.c \
			combine_picture.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

# defo
all: $(NAME)

# bild
$(NAME): $(MINILIBX) $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)

# make obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# make obj file
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# build libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# MINILIBX
$(MINILIBX):
	@if [ ! -d $(MINILIBX_DIR) ]; then \
		echo "MINILIBX not found. Cloning..."; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MINILIBX_DIR); \
	fi
	@make -C $(MINILIBX_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)
	rm -rf $(MINILIBX_DIR)

re: fclean all
