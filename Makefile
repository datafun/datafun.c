
#SRC = $(wildcard src/*.c)
SRC = $(wildcard deps/*.c)
OBJ = $(SRC:.c=.o)
PREFIX=/usr/local
CARGS = -std=c99
INCLUDE = -I deps -I src
BIN=datafun


all: reduce max mean

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


### 

max:
	$(CC) $(SRC) src/search/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

mean:
	$(CC) $(SRC) src/aggregate/$@.c $(CARGS) $(INCLUDE) -o ./bin/$@

#mode:
#	$(CC) $(SRC) src/aggregate/mode.c $(CARGS) $(INCLUDE) -o ./bin/$@

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