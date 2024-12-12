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
NAME = push_swap
CC = cc
CFLAGS =
# CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

SRC_DIR = .

SRC_FILES = push_swap.c \
			push_swap_check_input.c \
			push_swap_lstaddback_and_checkoverlap.c \
			push_swap_utils.c \
			push_swap_comannd.c \
			ft_qsort.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = .

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
	$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft

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