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
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

MAN_SRC_DIR = .
BNS_SRC_DIR = .

MAN_SRC_FILES = push_swap.c / push_swap_check_input.c / push_swap_lstaddback_and_checkoverlap.c /
				push_swap_utils.c

MAN_SRCS = $(addprefix $(MAN_SRC_DIR)/, $(MAN_SRC_FILES))

MAN_OBJ_DIR = .

MAN_OBJS = $(MAN_SRCS:$(MAN_SRC_DIR)/%.c=$(MAN_OBJ_DIR)/%.o)

OBJS = $(MAN_OBJS) $(BNS_OBJS)

LIBFT_DIR = ./libft_added_ftprintf
LIBFT = $(LIBFT_DIR)/libft.a

# BONUS_FLAG = .bonus_done

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(MAN_OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
#	ar rcs $(NAME) $(MAN_OBJS)
	$(CC) -o $(NAME) $(MAN_OBJS) -L$(LIBFT_DIR) -lft

# make object files
$(MAN_OBJ_DIR)/%.o: $(MAN_SRC_DIR)/%.c | $(MAN_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all