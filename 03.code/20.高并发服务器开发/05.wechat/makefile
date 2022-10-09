all: user rela mess photo svr

ARGS:= -std=c++11

user:
	g++ $(ARGS) -c -o user.o UserManager.cpp

rela:
	g++ $(ARGS) -c -o relationInfo.o RelationInfo.cpp
	g++ $(ARGS) -c -o relationManager.o RelationManager.cpp

mess:
	g++ $(ARGS) -c -o mess.o MessageManager.cpp

photo:
	g++ $(ARGS) -c -I ./common -o photo.o PhotoManager.cpp

OBJS:=server_ssp user.o relationInfo.o relationManager.o mess.o photo.o

svr:
	g++ $(ARGS) -I ./common -o $(OBJS) Config.cpp Socket.cpp main.cpp

clean:
	rm -f $(OBJS) server_ssp