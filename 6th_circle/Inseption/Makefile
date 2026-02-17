NAME			= inception
COMPOSE_FILE 	= ./docker-compose.yml
DATA_PATH		= /home/repri/data

.PHONY: all prepare up down clean fclean re

all: prepare up

prepare:
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress

up:
	docker-compose -f $(COMPOSE_FILE) up --build -d

clean: down
	docker system prune -a --force

down:
	docker-compose -f $(COMPOSE_FILE) down

fclean: clean
	printf "All data remove\n"
	sudo rm -rf $(DATA_PATH)

re: fclean all