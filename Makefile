CC = gcc
CFLAGS = -Wall -O3

all: hello_world inject.so

hello_world:
	$(CC) $(CFLAGS) -s src/hello_world.c -o hello_world

inject.so:
	$(CC) $(CFLAGS) -FPIC -shared src/inject.c -o inject.so

inject.so_nocolor:
	$(CC) $(CFLAGS) -DNOCOLOR -FPIC -shared src/inject.c -o inject.so

clean:
	rm -f hello_world inject.so

help:
	@echo "Default Target:"
	@echo "\t all => Build the default hello world & inject shared object."
	@echo "\nHello World Targets:"
	@echo "\t hello_world => Build the default hello world ELF binary."
	@echo "\nInject Targets:"
	@echo "\t inject.so => Build standard LD_PRELOAD inject.so shared object."
	@echo "\t inject.so_nocolor => Build non-colorized LD_PRELOAD inject.so shared object."
	@echo "\nMaintance Targets:"
	@echo "\t clean => delete the binaries."
