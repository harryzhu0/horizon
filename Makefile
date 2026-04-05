CC = gcc

CFLAGS = -Wall -Wextra -g -DWLR_USE_UNSTABLE \
         -Isrc \
         -I/usr/include/wlr-protocols \
         `pkg-config --cflags wlroots-0.18 wayland-server`

LDFLAGS = `pkg-config --libs wlroots-0.18 wayland-server` -ldl

SRC = src/main.c src/compositor.c
OBJ = $(SRC:.c=.o)

all: horizon

horizon: $(OBJ)
	$(CC) $(OBJ) -o horizon $(LDFLAGS)

clean:
	rm -f $(OBJ) horizon
