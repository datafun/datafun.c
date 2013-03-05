
#SRC = $(wildcard src/*.c)
SRC = $(wildcard deps/*.c)
OBJ = $(SRC:.c=.o)
PREFIX=/usr/local
CARGS = -std=c99
INCLUDE = -I deps -I src
BIN=datafun


all: lt max mean

lt:
	$(CC) $(SRC) src/reduce/lt.c $(CARGS) $(INCLUDE) -o ./bin/$@

max:
	$(CC) $(SRC) src/search/max.c $(CARGS) $(INCLUDE) -o ./bin/$@

mean:
	$(CC) $(SRC) src/aggregate/mean.c $(CARGS) $(INCLUDE) -o ./bin/$@

mode:
	$(CC) $(SRC) src/aggregate/mode.c $(CARGS) $(INCLUDE) -o ./bin/$@

install:
	install ./bin/lt $(PREFIX)/bin/lt
	install ./bin/max $(PREFIX)/bin/max
	install ./bin/mean $(PREFIX)/bin/mean

uninstall:
	rm $(PREFIX)/bin/lt
	rm $(PREFIX)/bin/max
	rm $(PREFIX)/bin/mean

clean:
	rm -f ./bin/*

test:
	./test/test.sh

.PHONY: clean install uninstall test