CC ?= gcc

CFLAGS = -c -Wall -Wextra -std=c11 -O3


SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)


CLI = cli.c


INSTALL_PATH = /usr/bin
LIBRARY_PATh = lib


all: build


static: $(SOURCES)
  mv src/*.o $(LIBRARY_PATH)


*.c:
  $(CC) $(CFLAGS) $@


build: $(SOURCES) $(CLI) link clean


link:
  $(CC) $(OBJECTS) -o nvm


clean:
  rm src/*.o