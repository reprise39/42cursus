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

NAME = Main
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
LDFLAGS =
INCLUDES = -I includes

SRC_DIR = ./srcs

SRC_FILES =	main.cpp\
			HumanA.cpp\
			HumanB.cpp\
			Weapon.cpp

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = ./objs

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(OBJS)
	$(CC) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)

# make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all