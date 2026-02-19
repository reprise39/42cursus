*This project has been created as part of the 42 curriculum by mkuida.*

# Inception

## 🐍 Description
The goal of this project is to build a system administration infrastructure composed of multiple Docker containers.
Three services run in dedicated containers: ① Nginx (TLS only), ② MariaDB, and ③ WordPress, with proper network isolation to provide a secure web server environment.
The target is considered complete when you can access the following URLs in a browser:
mandatory -> `https://${USER}.42.fr`
bonus     -> `https://${USER}.42.fr/static`

## 🛠 Instructions
### Build and Run
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

## 📖 Concepts Comparison

### 1. Virtual Machines vs Docker
| Comparison Item | Virtual Machines (VM) | Docker (Container) |
| :--- | :--- | :--- |
| **Virtualization target** | Entire hardware/OS | Processes/applications |
| **Kernel** | Has its own kernel | Shares the host OS kernel |
| **Resource usage** | Heavy (GBs) | Very lightweight (MBs) |
| **Startup time** | Minutes (OS boot required) | Seconds |

### 2. Secrets vs Environment Variables
* **Environment Variables (`.env`)**:
    * Easy to configure and commonly used.
    * Values may be exposed by commands like `docker inspect`, so careful handling is required.
    * In this project, only public information is written there, so it is not hidden.
* **Docker Secrets**:
    * Very secure because they are mounted temporarily in memory and not written to disk.
    * In this project, secrets are designed to work together with `.env` while maintaining confidentiality.

### 3. Docker Network vs Host Network
* **Docker Network (Bridge)**:
    * Connects containers in an isolated subnet.
    * Can block unnecessary traffic and expose only required ports, so it is **recommended for security**.
* **Host Network**:
    * Containers use the host network directly.
    * Since there is no isolation, port conflicts and security risks can occur.

### 4. Docker Volumes vs Bind Mounts
* **Docker Volumes**:
    * Dedicated storage managed by the Docker engine.
    * Independent from host filesystem structure, with better performance and manageability.
* **Bind Mounts**:
    * Directly mounts specific directories from the host.

---

## 📚 Resources
- [Docker Documentation](https://docs.docker.com/)
- [Nginx Official Site](https://nginx.org/)
- [WordPress CLI Guide](https://developer.wordpress.org/cli/commands/)

---

## 🤖 AI Use Disclosure
During development of this project, AI (Google Gemini) was used for the following tasks:
* Drafting structure, translation, and decoration for project documents (`README`, `USER_DOC`, `DEV_DOC`).
* Advice on Makefile structure definition and error handling.
* Assistance with network troubleshooting (SSH connection and port forwarding).
* Organizing conceptual comparisons of technical terms (Docker vs VM, etc.).
* Thank you very much. I hope to upgrade to the paid version someday.
