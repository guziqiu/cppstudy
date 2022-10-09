all:server client

OBJS:= ./common -I ./  ./common/common.c ./wechat.c 

client:
	gcc ./client.c -std=c99 -I $(OBJS) -lpthread -o client

server:
	gcc ./server.c -std=c99 -I $(OBJS) -I ./common ./common/wechat_ui.c -D UI -lpthread -lncurses -o server

debug:
	gcc ./client.c -std=c99 -I $(OBJS) -D _D -lpthread -o client
	gcc ./server.c -std=c99 -I $(OBJS) -I ./common ./common/wechat_ui.c -D _D -D UI -lpthread -lncursesw -o server

clean:
	rm ./server ./client