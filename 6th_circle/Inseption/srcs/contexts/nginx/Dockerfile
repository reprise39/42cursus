FROM debian:11

RUN apt-get update -y && \
	apt-get install -y \
	nginx \
	openssl \
	&& rm -rf /var/lib/apt/lists/*

RUN mkdir -p /etc/nginx/ssl && \
	openssl req -new\
	-x509 \
	-nodes \
	-days 365 \
	-newkey rsa:2048 \
	-keyout etc/nginx/ssl/inception.key \
	-out etc/nginx/ssl/inception.crt \
	-subj "/C=JP/ST=Tokyo/L=Shinjuku/O=42Tokyo/OU=student/CN=mkuida.42.fr"

COPY ./config/nginx.conf /etc/nginx/conf.d/default.conf

EXPOSE 443

CMD ["nginx","-g","daemon off;"]