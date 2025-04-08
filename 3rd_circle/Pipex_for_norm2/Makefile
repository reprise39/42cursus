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
NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L$(LIBFT_DIR) -lft
INCLUDES = -I includes

SRC_DIR = ./SRCS

SRC_FILES = pipex_main.c\
			pipe_mode.c\
			heredoc_mode.c\
			check_pipemode_input_file.c\
			check_pipemode_input_cmd.c\
			check_heredocmode_input_cmd.c\
			set_struct.c\
			set_struct_cmd_phrase.c\
			set_struct_cmd_fullpaths.c\
			print_struct.c\
			free_struct.c\
			exec_pipe.c\
			exec_cmds.c\
			utils.c\
			get_next_line.c

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
	$(CC) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)

# make object files

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all