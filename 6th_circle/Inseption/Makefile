NAME			= inception
COMPOSE_FILE 	= ./srcs/docker-compose.yml
DATA_PATH		= /home/repri/data

.PHONY: all prepare up down clean fclean re

all: prepare up

prepare:
	sudo mkdir -p $(DATA_PATH)/mariadb
	sudo mkdir -p $(DATA_PATH)/wordpress

up:
	docker-compose -f $(COMPOSE_FILE) up --build -d

clean:
	docker-compose -f $(COMPOSE_FILE) down --rmi all -v

down:
	docker-compose -f $(COMPOSE_FILE) down

fclean: clean
	printf "All data remove\n"
	sudo rm -rf $(DATA_PATH)/mariadb
	sudo rm -rf $(DATA_PATH)/wordpress
	# docker network prune -f

re: fclean all