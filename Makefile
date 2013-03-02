
#SRC = $(wildcard src/*.c)
SRC = $(wildcard deps/*.c)
OBJ = $(SRC:.c=.o)
PREFIX=/usr/local
CARGS = -std=c99
INCLUDE = -I deps -I src
BIN=datafun


all: lt mean

lt:
	$(CC) $(SRC) src/reduce/lt.c $(CARGS) $(INCLUDE) -o ./bin/$@

mean:
	$(CC) $(SRC) src/aggregate/mean.c $(CARGS) $(INCLUDE) -o ./bin/$@

#install: all
#	install ./bin/* $(PREFIX)/bin/*

#uninstall:
#	rm $(PREFIX)/bin/$(BIN)

clean:
	rm -f ./bin/*

test:
	./test/test.sh

.PHONY: clean install uninstall test