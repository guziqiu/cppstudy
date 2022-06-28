.PHONY: clean
CC=g++ -I./ -c
all : 41.main.o 45.41main.header3.o  46.41.main.header2.o 47.41.main.header1.o
	g++ 41.main.o 45.41main.header3.o  46.41.main.header2.o 47.41.main.header1.o
41.main.o: 41.main.cpp
	${CC} 41.main.cpp
45.41main.header3.o: 45.41main.header3.cc 44.41.main.header3.h
	${CC} 45.41main.header3.cc 
46.41.main.header2.o: 46.41.main.header2.cc 43.41.main.header2.h
	${CC} 46.41.main.header2.cc 
47.41.main.header1.o: 47.41.main.header1.cc 42.41.main.header1.h
	${CC} 47.41.main.header1.cc
clean:
	rm *.o a.out
	
