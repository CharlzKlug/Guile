PROGRAM = simple-snrf

all: $(PROGRAM)

snrf.x: main.c
	guile-snarf -o snrf.x main.c `pkg-config --cflags guile-3.0`

$(PROGRAM): main.c snrf.x
	gcc -o $(PROGRAM) main.c `pkg-config --cflags --libs guile-3.0`

clean:
	rm -f *.x
