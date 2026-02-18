FROM Debian:11

RUN apt-get update -y && \
	apt-get upgrade -y && \
	apt-get install -y && \
	rm -rf /var/lib/apt/lists/*

COPY config/nginx.conf /etc/nginx/nginx.conf
COPY static_html/index.html /var/www/html/index.html

CMD ["nginx", "-g", "daemon off;"]