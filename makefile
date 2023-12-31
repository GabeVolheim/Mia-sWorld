COMPILER = gcc
OPTIONS = -Wall -Werror
PROGRAM = heymia
FILES = heymia.c 2048.c hangman.c


all: $(PROGRAM)

run: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(FILES)
	$(COMPILER) $(OPTIONS) $(FILES) -o $(PROGRAM)

clean:
	rm -f $(PROGRAM)