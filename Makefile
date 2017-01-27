CC=g++
OBJECTS=src/main.o src/Grille.o src/Ile.o src/IleOuPont.o src/Pont.o
CFLAGS=-Wall -std=c11
PROG=Hashi

$(PROG): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $(PROG)

clean:
	rm -f src\/*.o $(PROG) *.huf
