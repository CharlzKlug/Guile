# The configure script fills in these values.
CC=gcc
CFLAGS=-I/nix/store/7gx6d1713pszdvk8v5zakanl5ghrkwk3-libunistring-1.4.1-dev/include -I/nix/store/9b2v4rddpw85lkhj7nk9bw2mfg04hh6x-guile-3.0.10-dev/include/guile/3.0 -I/nix/store/87cw8k791y3d96m6gjrshlf18sg0w4kn-boehm-gc-8.2.8-dev/include
LIBS=-L/nix/store/fslv3c0sb12kbn9yyj6f9ylisz969xjv-guile-3.0.10/lib -L/nix/store/mf2kqmp9s7cm2ygacfvmnickjisd35pd-boehm-gc-8.2.8/lib -lguile-3.0 -lgc -lpthread -ldl

simple-guile: simple-guile.o
	${CC} simple-guile.o ${LIBS} -o simple-guile
simple-guile.o: simple-guile.c
	${CC} -c ${CFLAGS} simple-guile.c
