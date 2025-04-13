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

#define
NAME = so_long
CC = cc
CFLAGS = 
# CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft -L/usr/local/lib -lmlx -lXext -lX11 -lm
INCLUDES = -I includes

SRC_DIR = ./SRCS

SRC_FILES = main.c \
			so_long_utils.c \
			make_map.c \
			free_map.c \
			map_utils.c \
			check_maps.c \
			check_maps_second.c \
			check_textures.c \
			get_next_line.c \
			get_next_line_utils.c \
			mlx_exec.c \
			make_data.c \
			set_mlx_hook.c
#			check_maps_third.c \

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = ./OBJS

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./libft_added_ftprintf
LIBFT = $(LIBFT_DIR)/libft.a

# BONUS_FLAG = .bonus_done

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
#	cp $(LIBFT) $(NAME)
#	ar rcs $(NAME) $(MAN_OBJS)
	$(CC) $(incluses) -o $(NAME) $(OBJS) $(LDFLAGS)

# make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all