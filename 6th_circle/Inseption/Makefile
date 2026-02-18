NAME				= inception
COMPOSE_FILE 		= ./srcs/docker-compose.yml
BONUS_COMPOSE_FILE	= ./srcs/bonus-docker-compose.yml
DATA_PATH			= /home/repri/data

.PHONY: all prepare up down clean fclean re bonus

all: prepare up

prepare:
	sudo mkdir -p $(DATA_PATH)/mariadb
	sudo mkdir -p $(DATA_PATH)/wordpress

up:
	docker-compose -f $(COMPOSE_FILE) up --build -d

bonus: prepare
	docker-compose -f $(COMPOSE_FILE) -f $(BONUS_COMPOSE_FILE) up --build -d

clean:
	docker-compose -f $(COMPOSE_FILE)  -f $(BONUS_COMPOSE_FILE) down --rmi all -v

down:
	docker-compose -f $(COMPOSE_FILE)  -f $(BONUS_COMPOSE_FILE) down

fclean: clean
	sudo rm -rf $(DATA_PATH)/mariadb
	sudo rm -rf $(DATA_PATH)/wordpress
	# docker network prune -f

re: fclean all