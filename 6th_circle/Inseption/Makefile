# env
NAME                = inception
LOGIN               = mkuida
DATA_PATH           = /home/$(LOGIN)/data

# files
SRCS_DIR            = ./srcs
COMPOSE_FILE        = $(SRCS_DIR)/docker-compose.yml
BONUS_FILE          = $(SRCS_DIR)/bonus-docker-compose.yml

# cmd
SRCS                = -f $(COMPOSE_FILE)
COMPOSE             = docker compose -p $(NAME)

.PHONY: all prepare build up down clean fclean re bonus stop start logs

# 1. 全てを準備して起動
all: prepare build up

# 2. bonus 用の設定切り替え
bonus: SRCS += -f $(BONUS_FILE)
bonus: all

# ディレクトリ作成
prepare:
	sudo mkdir -p $(DATA_PATH)/mariadb
	sudo mkdir -p $(DATA_PATH)/wordpress

# イメージのビルドのみ（コンテナは作らず更新だけ）
build:
	$(COMPOSE) $(SRCS) build

# コンテナの起動（バックグラウンド）
up:
	$(COMPOSE) $(SRCS) up -d

stop:
	$(COMPOSE) $(SRCS) stop

start:
	$(COMPOSE) $(SRCS) start

down:
	$(COMPOSE) $(SRCS) down

clean: SRCS += -f $(BONUS_FILE)
clean:
	$(COMPOSE) $(SRCS) down --rmi local -v

fclean: SRCS += -f $(BONUS_FILE)
fclean:
	$(COMPOSE) $(SRCS) down --rmi all -v
	sudo rm -rf $(DATA_PATH)

re: fclean all

logs:
	$(COMPOSE) $(SRCS) logs -f