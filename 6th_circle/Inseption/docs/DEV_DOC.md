# Developer Documentation - Inception

This document explains the technical setup and maintenance of the Inception infrastructure.

## 1. Prerequisites (Environment Setup)
- **OS**: Debian (stable version recommended). Login name: `mkuida`.
- **Tools**: Docker, Docker Compose, GNU Make.
- **Permissions**: The executing user must belong to the Docker group and have sudo privileges.
- **Domain mapping**: Add `127.0.0.1 mkuida.42.fr` to `/etc/hosts` on the host machine.

## 2. Build and Run
1. **Clone the repository**:
   `git clone <repository_url>`
2. **Configuration**:
   Create four `.txt` files in the `secrets` directory and set the passwords indicated by their file names.

> **Note:** You can prepare them by removing `.example` from the existing `.txt.example` files and filling in the contents.<br>
> Do not expose the passwords written in these files. We recommend generating strong passwords with the following method (or equivalent strength):<br>
> `pwgen 16 1`

3. **Start**:
   `make`
   This command automatically creates the required volume directories, builds images from Dockerfiles, and starts the containers.

   `make bonus`
   In addition to the above, this command also enables access to static HTML files.

> **Note:** When running `make bonus`, please uncomment the following section.  
> Conversely, when running `make` (mandatory part) afterward, ensure this section is commented out again.  
> **Target Section:** The `#bonus` part within `srcs/contexts/nginx/config/nginx.conf`.  
> [link](srcs/contexts/nginx/config/nginx.conf)

## 3. Management Commands
- `make re`: Full rebuild (`fclean + all`).
- `make clean`: Stop containers and remove containers/networks.
- `make fclean`: Remove containers, images, and **all persistent data (volumes)**.
- `docker logs <container_name>`: Check service logs for debugging.

## 4. About Data Persistence
To keep data even after containers are removed, host directories are bind-mounted.
- **WordPress files**: `/home/mkuida/data/wordpress`
- **Database files**: `/home/mkuida/data/mariadb`

Volume settings are defined in the `volumes` section of `srcs/docker-compose.yml`.

> **Warning:** Commands that include `make clean` (such as `make fclean`) also remove these directories. Use with caution.
