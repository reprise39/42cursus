FROM debian:11

RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server

COPY config/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY scripts/setup.sh /usr/local/bin/setup.sh
RUN chmod +x /usr/local/bin/setup.sh

RUN mkdir -p /var/run/mysqld && \
    chown -R mysql:mysql /var/run/mysqld

EXPOSE 3306

ENTRYPOINT [ "/usr/local/bin/setup.sh" ]