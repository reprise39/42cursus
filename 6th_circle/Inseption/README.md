*This project has been created as part of the 42 curriculum by mkuida*
# Inception

Docker-based infrastructure project from the 42 curriculum.

This setup runs:
- `mariadb`
- `wordpress` (PHP-FPM)
- `nginx` (TLS on port `443`)

## Quick Start

1. Create secret files from the examples:
```bash
cp secrets/db_root_password.txt.example secrets/db_root_password.txt
cp secrets/db_user_password.txt.example secrets/db_user_password.txt
cp secrets/wp_admin_password.txt.example secrets/wp_admin_password.txt
cp secrets/wp_user_password.txt.example secrets/wp_user_password.txt
```

2. Edit those 4 files and set strong passwords.
```bash
# Example password generator
pwgen 16 1
```

3. Build and start mandatory services:
```bash
make
```

## Project Layout

- `srcs/docker-compose.yml`: mandatory stack
- `srcs/bonus-docker-compose.yml`: bonus service overlay
- `srcs/.env`: configurable parameters (DB name/user, WP user/domain, volume path)
- `secrets/`: Docker secrets consumed by containers

## Mandatory

Runs MariaDB + WordPress + Nginx with HTTPS.

- Nginx exposes `443:443`
- Volumes are bind-mounted to `/home/repri/data/{mariadb,wordpress}` (created by `make prepare`)

Useful commands:
```bash
make        # prepare + up
make down   # stop containers
make clean  # stop + remove images + volumes
make fclean # clean + remove /home/repri/data/*
make re     # full rebuild
```

## Bonus

Bonus provides an additional static site service (`bonus_nginx`).

1. Uncomment the `location /static/` block in:
   - `srcs/contexts/nginx/config/nginx.conf`
2. Start with:
```bash
make bonus
```

Notes:
- If bonus routing stays enabled in `nginx.conf`, running only the mandatory stack can break expected routing.
- Either keep the bonus block commented for mandatory-only runs, or use `make bonus`.

## Domain / Access

Current config expects:
- `WP_DOMAIN_NAME=mkuida.42.fr` (`srcs/.env`)
- `server_name mkuida.42.fr` (`srcs/contexts/nginx/config/nginx.conf`)

So you may need a local hosts entry:
```text
127.0.0.1 mkuida.42.fr
```

Then open:
- `https://mkuida.42.fr`
- `https://mkuida.42.fr/static/` (bonus enabled only)

## Requirements

- Docker + Docker Compose (`docker-compose` command available)
- `make`
- `sudo` permission (required by `make prepare` for `/home/repri/data`)
