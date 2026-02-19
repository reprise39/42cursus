FROM debian:11

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y \
	php7.4-fpm \
	php7.4-mysql \
	mariadb-client \
	wget \
	&& rm -rf /var/lib/apt/lists/*

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

RUN sed -i 's|listen = /run/php/php7.4-fpm.sock|listen = 9000|' /etc/php/7.4/fpm/pool.d/www.conf

WORKDIR /var/www/html

EXPOSE 9000

COPY ./scripts/setup.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/setup.sh

ENTRYPOINT [ "/usr/local/bin/setup.sh" ]