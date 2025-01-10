.DEFAULT_GOAL := all

OBJECTS=build/avl.o build/jogo.o build/main.o build/trie.o

build/avl.o: src/avl.c include/avl.h
	gcc -Iinclude src/avl.c -c -o build/avl.o

build/jogo.o: src/jogo.c include/jogo.h
	gcc -Iinclude src/jogo.c -c -o build/jogo.o

build/main.o: src/main.c
	gcc src/main.c -c -o build/main.o

build/trie.o: src/trie.c    
	gcc -Include src/trie.c -c -o build/trie.o

objects: $(OBJECTS)

programa: objects 
	gcc -Iinclude $(OBJECTS) -o bin/programa

clean:
	del .\build\*.o .\bin\*.exe

all: programa

run:
	bin/programa

