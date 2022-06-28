.PHONY: clean
all: ./src/test.o main.o
	gcc ./src/test.o main.o -o ./bin/haizei
./src/test.o: ./src/test.c ./include/test.h
	gcc -I ./include -c ./src/test.c -o ./src/test.o
main.o: main.c ./include/test.h 
	gcc -I ./include -c main.c 
clean: 
	rm ./bin/haizei ./src/*.o main.o
run: 
	./bin/haizei
