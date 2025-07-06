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
NAME = philosophers
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS =
INCLUDES = -I includes

SRC_DIR = ./SRCS

SRC_FILES =	main.c\
			check_input.c\
			start_simulation.c\
			end_simulation.c\
			print_info.c\
			wait_all_thread.c\
			ft_is_int.c\
			utils.c\
			for_debag.c\
			philosophers.c\
			philo_behave_takeforks.c\
			philo_behave_1.c\
			philo_behave_2.c\
			monitoring.c\
			cal_time.c\

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ_DIR = ./OBJS

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

.PHONY: all clean fclean re

# defolt
all: $(NAME)

# make lib
$(NAME): $(OBJS)
#	cp $(LIBFT) $(NAME)
#	ar rcs $(NAME) $(MAN_OBJS)
	$(CC) $(INCLUDES) -o $(NAME) $(OBJS) $(LDFLAGS)

# make object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all