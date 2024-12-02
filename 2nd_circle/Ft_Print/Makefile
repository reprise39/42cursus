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
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

MAN_SRC_DIR = .
BNS_SRC_DIR = .

MAN_SRC_FILES = ft_printf.c ft_printf_x.c ft_printf_diu.c ft_printf_cspp.c
# BNS_SRC_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c \

MAN_SRCS = $(addprefix $(MAN_SRC_DIR)/, $(MAN_SRC_FILES))
# BNS_SRCS = $(addprefix $(BNS_SRC_DIR)/, $(BNS_SRC_FILES))

MAN_OBJ_DIR = .
# BNS_OBJ_DIR = .

MAN_OBJS = $(MAN_SRCS:$(MAN_SRC_DIR)/%.c=$(MAN_OBJ_DIR)/%.o)
# BNS_OBJS = $(BNS_SRCS:$(BNS_SRC_DIR)/%.c=$(BNS_OBJ_DIR)/%.o)

OBJS = $(MAN_OBJS) $(BNS_OBJS)

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# BONUS_FLAG = .bonus_done

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(MAN_OBJS)
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(MAN_OBJS)

# bonus: $(BONUS_FLAG)

# $(BONUS_FLAG): $(OBJS)
# 	ar rcs $(NAME) $(OBJS)
# 	touch $(BONUS_FLAG)

# make object files
$(MAN_OBJ_DIR)/%.o: $(MAN_SRC_DIR)/%.c | $(MAN_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# $(BNS_OBJ_DIR)/%.o: $(BNS_SRC_DIR)/%.c | $(BNS_OBJ_DIR)
# 	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# make object directorie
# $(MAN_OBJ_DIR):
# 	mkdir -p $(MAN_OBJ_DIR)

# $(BNS_OBJ_DIR):
# 	mkdir -p $(BNS_OBJ_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
