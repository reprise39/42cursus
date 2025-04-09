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
BONUS_SRC_DIR=./BONUS_SRCS

SRC_FILES = pipex_main.c\
			pipe_mode.c\
			heredoc_mode.c\
			check_pipemode_input_file.c\
			check_pipemode_input_cmd.c\
			check_heredocmode_input_cmd.c\
			set_struct.c\
			set_struct_cmd_phrase.c\
			set_struct_cmd_fullpaths.c\
			free_struct.c\
			exec_pipe.c\
			exec_cmds.c\
			utils.c\
			get_next_line.c

BONUS_SRC_FILES = pipex_main_bonus.c\
				pipe_mode_bonus.c\
				heredoc_mode_bonus.c\
				check_pipemode_input_file_bonus.c\
				check_pipemode_input_cmd_bonus.c\
				check_heredocmode_input_cmd_bonus.c\
				set_struct_bonus.c\
				set_struct_cmd_phrase_bonus.c\
				set_struct_cmd_fullpaths_bonus.c\
				free_struct_bonus.c\
				exec_pipe_bonus.c\
				exec_cmds_bonus.c\
				utils_bonus.c\
				get_next_line_bonus.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRCS = $(addprefix $(BONUS_SRC_DIR)/, $(BONUS_SRC_FILES))

OBJ_DIR = ./OBJS
BONUS_OBJ_DIR = ./BONUS_OBJS

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(BONUS_SRC_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

LIBFT_DIR = ./libft_added_ftprintf
LIBFT = $(LIBFT_DIR)/libft.a

ifeq ($(MAKECMDGOALS) , bonus)
	SRCS = $(BONUS_SRCS)
	OBJ_DIR = $(BONUS_OBJ_DIR)
	OBJS = $(BONUS_OBJS)
endif


.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	$(CC) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)

# make object files
bonus: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# $(BONUS_OBJ_DIR):
# 	mkdir -p $(BONUS_OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c | $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all