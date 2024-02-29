COMPILER = gcc
OPTIONS = -Wall
UI = `pkg-config --cflags --libs gtk4` -lgtk-4 -L/lib/x86_64-linux-gnu/gtk-4.0
PROGRAM = heymia
FILES = heymia.c 2048.c hangman.c


all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(FILES)
	$(COMPILER) $(OPTIONS) $(FILES) -o $(PROGRAM) $(UI)

clean:
	rm -f $(PROGRAM)