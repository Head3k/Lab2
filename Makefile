all:main

main: src/main.c src/IntVector.c
	gcc -Wall -o main -I src src/main.c src/IntVector.c
