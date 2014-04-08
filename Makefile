BINARY=PlayRisk
OPTFLAGS?=-g3 -ggdb -DDEBUG
DEBUG_LEVEL=3

export BINARY
export OPTFLAGS

default: debug

all: 
	mkdir -p obs/
	cd src/ && make all && cd ..

genmake:
	./genmake.sh

debug: OPTFLAGS=-g3 -ggdb -Wall -Wextra -DDEBUG$(DEBUG_LEVEL)
debug: all

release: OPTFLAGS=-O2 -DRELEASE
release: all

clean:
	rm -rf obs/ $(BINARY)
