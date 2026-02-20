# User Manual - Inception

This document explains what Inception provides and how to use it.

## 1. What Is Inception? (Provided Services)
It provides a secure WordPress site composed of the following services:
- **NGINX**: The entry point of the infrastructure. Provides HTTPS communication over port 443.
- **WordPress**: The content management system (CMS), running with PHP-FPM.
- **MariaDB**: The database used to store WordPress data.

## 2. Starting and Stopping the Project
To start the infrastructure, run the following in the project root directory:
`make`

To stop services while keeping data:
`make stop`

## 3. How to Access the Website
### 🌐 Public Site
Open your browser and access:
[https://mkuida.42.fr](https://mkuida.42.fr)

### ⚙️ Admin Panel (Dashboard)
To manage WordPress, log in here:
[https://mkuida.42.fr/wp-admin](https://mkuida.42.fr/wp-admin)

> **Note:** Because a self-signed certificate is used, your browser may display a “connection is not private” warning.<br>
> For this project, it should be fine. Choose “Advanced” and continue to access the site.

## 4. Managing Credentials (Login Information)
Database and WordPress passwords are stored in `.txt` files under `secrets/`.
Public information such as login names is written in `srcs/.env`.

> **Note:** These values are set when running `make`. Changing them during operation will not apply updates, so avoid changing them carelessly.<br>
> (It can become confusing.)

## 5. Health Check
To verify that all services are running correctly, run:
`docker ps`

If `nginx`, `wordpress`, and `mariadb` all show status **Up**, everything is working correctly.
