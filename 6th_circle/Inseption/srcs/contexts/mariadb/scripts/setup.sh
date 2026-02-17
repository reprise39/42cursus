#!/bin/sh

#pre-boot
mysqld --skip-networking &

#wait-preboot
until mariadb-admin ping > /dev/null 2>&1; do
  sleep 5
done

mariadb << EOF
CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;
CREATE USER IF NOT EXISTS '${SQL_USER}'@'%' IDENTIFIED BY '${SQL_PASSWORD}';
GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO '${SQL_USER}'@'%';

ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';
FLUSH PRIVILEGES;
EOF

mariadb-admin -u root -p${SQL_ROOT_PASSWORD} shutdown

#main bool
exec mysqld