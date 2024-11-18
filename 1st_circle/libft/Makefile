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
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

MAN_SRC_DIR = .
BNS_SRC_DIR = .

MAN_SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
				ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
				ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
				ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BNS_SRC_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
				ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

MAN_SRCS = $(addprefix $(MAN_SRC_DIR)/, $(MAN_SRC_FILES))
BNS_SRCS = $(addprefix $(BNS_SRC_DIR)/, $(BNS_SRC_FILES))

MAN_OBJ_DIR = .
BNS_OBJ_DIR = .

MAN_OBJS = $(MAN_SRCS:$(MAN_SRC_DIR)/%.c=$(MAN_OBJ_DIR)/%.o)
BNS_OBJS = $(BNS_SRCS:$(BNS_SRC_DIR)/%.c=$(BNS_OBJ_DIR)/%.o)

OBJS = $(MAN_OBJS) $(BNS_OBJS)

BONUS_FLAG = .bonus_done

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(MAN_OBJS)
	ar rcs $(NAME) $(MAN_OBJS)

bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	touch $(BONUS_FLAG)

# make object files
$(MAN_OBJ_DIR)/%.o: $(MAN_SRC_DIR)/%.c | $(MAN_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(BNS_OBJ_DIR)/%.o: $(BNS_SRC_DIR)/%.c | $(BNS_OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# make object directorie
$(MAN_OBJ_DIR):
	mkdir -p $(MAN_OBJ_DIR)

$(BNS_OBJ_DIR):
	mkdir -p $(BNS_OBJ_DIR)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(MAN_SRC_FILES) $(BNS_SRC_FILES)
	gcc -nostartfiles -shared -o libft.so $(OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(BONUS_FLAGS)

fclean: clean
	rm -f $(NAME)

re: fclean all