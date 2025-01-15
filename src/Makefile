CC = gcc
FLAGS = -Wall
LIBS = -lm
EXEC = versiondynamique clean

WEB_DIR = /var/www/html/
APACHE_LOG = /var/log/apache2/access.log
APACHE_CONF = /etc/apache2/sites-available/000-default.conf

%.o: %.c
	$(CC) $(FLAGS) -c $<

all: $(EXEC)

versiondynamique: ../lib/libgraphique.c log.o versiondynamique.o
	$(CC) $(LIBS) $(FLAGS) -o $@ $^ `sdl-config --libs --cflags` -lSDL -lSDL_ttf

install: versiondynamique
	@sudo mkdir -p $(WEB_DIR)
	@sudo cp versiondynamique $(WEB_DIR)/index.cgi
	@sudo chmod 755 $(WEB_DIR)/index.cgi
	@sudo cp ../www/access.log $(APACHE_LOG)
	@sudo chmod 644 $(APACHE_LOG)
	@sudo chown -R www-data:www-data $(WEB_DIR)
	@sudo chmod -R 755 $(WEB_DIR)
	@sudo cp ../www/000-default.conf $(APACHE_CONF)
	@sudo systemctl restart apache2

clean:
	rm -f *.o versiondynamique

