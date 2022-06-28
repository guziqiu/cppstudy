.PHONY: clean
all :  
	gcc 30.epoll.main.server.c  04.common.c 26.epoll.server.c -o server
	gcc 32.epoll.main.client.c 04.common.c 29.epoll.client.c -o client

clean:
	rm server client
