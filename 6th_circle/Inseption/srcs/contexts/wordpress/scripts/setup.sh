#!/bin/bash

#wait db
until mariadb-admin ping -h"mariadb" --silent; do
    sleep 1
done


if ! wp core is-installed --allow-root; then

    wp core download --allow-root

    wp config create --allow-root \
        --dbname=${SQL_DATABASE} \
        --dbuser=${SQL_USER} \
        --dbpass=${SQL_PASSWORD} \
        --dbhost=mariadb:3306

    # 4. サイトのインストール（管理者ユーザーの作成）
    wp core install --allow-root \
        --url=${DOMAIN_NAME} \
        --title=${SITE_TITLE} \
        --admin_user=${ADMIN_USER} \
        --admin_password=${ADMIN_PASSWORD} \
        --admin_email=${ADMIN_EMAIL}

    # 5. 一般ユーザーの作成（課題要件）
    wp user create ${USER_NAME} ${USER_EMAIL} --user_pass=${USER_PASSWORD} --role=author --allow-root

fi

# 6. PHP-FPMをフォアグラウンドで起動
# -F はデーモン化（バックグラウンド化）させないためのフラグ
mkdir -p /run/php
exec php-fpm7.4 -F