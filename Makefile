miniql: build/main.o
	gcc build/main.o -o bin/miniql

build/main.o: src/main.c
	gcc -c src/main.c -o build/main.o