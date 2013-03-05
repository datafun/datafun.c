
#SRC = $(wildcard src/*.c)
SRC = $(wildcard deps/*.c)
OBJ = $(SRC:.c=.o)
PREFIX=/usr/local
CARGS = -std=c99
INCLUDE = -I deps -I src
BIN=datafun


all: aggregate reduce search

### reduce

reduce: gt gte lt lte

gt: 
	$(CC) $(SRC) src/reduce/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

gte: 
	$(CC) $(SRC) src/reduce/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

lt:
	$(CC) $(SRC) src/reduce/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

lte:
	$(CC) $(SRC) src/reduce/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@


### aggregate

aggregate: mean

mean:
	$(CC) $(SRC) src/aggregate/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

#mode:
#	$(CC) $(SRC) src/aggregate/mode.c $(CARGS) $(INCLUDE) -o ./bin/$@

### search

search: max min

max:
	$(CC) $(SRC) src/search/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

min:
	$(CC) $(SRC) src/search/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@


### UTILS

install:
	ls -tr bin/* | xargs -t -I {} install {} $(PREFIX)/bin/.

uninstall:
	ls bin | xargs -t -I {} rm $(PREFIX)/bin/{}

clean:
	rm -f ./bin/*

test:
	./test/test.sh

.PHONY: clean install uninstall test

