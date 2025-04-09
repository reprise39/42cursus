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
BONUS_NAME = pipex

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRC_DIR = ./SRC
BONUS_SRC_DIR = ./BONUS_SRC

SRC_FILES = push_swap.c \
			push_swap_initlst.c \
			push_swap_coodinatecompress.c \
			push_swap_struct_command.c \
			push_swap_check_input.c \
			push_swap_lstaddback_and_checkoverlap.c \
			push_swap_utils.c \
			push_swap_command_a.c \
			push_swap_command_b.c \
			push_swap_command_r.c \
			push_swap_for_three.c \
			push_swap_morethan_three.c \
			push_swap_algo.c \
			ft_qsort.c \
			ft_binarysarch.c \
			push_swap_morethan_three_algo_ab_r.c \
			push_swap_morethan_three_algo_ab_rr.c \
			push_swap_morethan_three_algo_ba_r.c \
			push_swap_morethan_three_algo_ba_rr.c \
			push_swap_for_debag.c

BONUS_SRC_FILES = bonus_make_checker.c \
				  bonus_make_checker_utils.c \
				  bonus_push_swap_command_basic.c \
				  bonus_push_swap_command_complex.c \
				  get_next_line.c \
				  push_swap_initlst.c \
				  push_swap_coodinatecompress.c \
				  push_swap_struct_command.c \
				  push_swap_check_input.c \
				  push_swap_lstaddback_and_checkoverlap.c \
				  push_swap_utils.c \
				  push_swap_command_a.c \
				  push_swap_command_b.c \
				  push_swap_command_r.c \
				  ft_qsort.c \
				  ft_binarysarch.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRCS = $(addprefix $(SRC_DIR)/, $(BONUS_SRC_FILES))

OBJ_DIR = ./OBJ
BONUS_OBJ_DIR = ./BONUS_OBJ

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT_DIR = ./libft_added_ftprintf
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make mandatory
$(NAME): $(OBJS) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

# make bonus
bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft

# Make libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# make object files(man)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# make object files(bonus)
$(OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all