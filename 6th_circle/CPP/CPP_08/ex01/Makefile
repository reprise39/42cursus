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

NAME := ex01

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic
CPPFLAGS := -Iincludes 
LDFLAGS :=
LDLIBS :=

SRC_DIR := ./srcs
OBJ_DIR := ./objs

SRC_FILES :=	main.cpp\
				sio.cpp\
				Span.cpp

SRCS := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

# Default target
all: $(NAME)

# Link
$(NAME): $(OBJS)
	$(CXX) $(LDFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

# Compile
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all