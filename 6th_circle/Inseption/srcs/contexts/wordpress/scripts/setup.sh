#!/bin/bash

#setup-password
if [ -f /run/secrets/wp_admin_password ]; then
    WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)
fi

if [ -f /run/secrets/wp_password ]; then
    SQL_ROOT_PASSWORD=$(cat /run/secrets/wp_password)
fi

#wait db
until mariadb-admin ping -h"mariadb" --silent; do
    sleep 1
done


#if ! wp core is-installed --allow-root; then
if [ ! -f wp-config.php ]; then
    wp core download --allow-root

    wp config create --allow-root \
        --dbname=${SQL_DATABASE} \
        --dbuser=${SQL_USER} \
        --dbpass=${SQL_PASSWORD} \
        --dbhost=mariadb:3306

    # 4. サイトのインストール（管理者ユーザーの作成）
    wp core install --allow-root \
        --url=${WP_DOMAIN_NAME} \
        --title=${WP_SITE_TITLE} \
        --admin_user=${WP_ADMIN_USER} \
        --admin_password=${WP_ADMIN_PASSWORD} \
        --admin_email=${WP_ADMIN_EMAIL}

    # 5. 一般ユーザーの作成（課題要件）
    wp user create ${WP_USER_NAME} ${WP_USER_EMAIL} --user_pass=${USER_PASSWORD} --role=author --allow-root

fi

mkdir -p /run/php
exec php-fpm7.4 -F