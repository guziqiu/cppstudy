

#ifndef _WECHAT_H
#define _WECHAT_H


struct wechat_user
{
	char name[50];
	char passwd[20];
	int sex;
	int fd;
	int isOnline;
};

// 比特掩码
#define WECHAT_SIGNUP 0x01
#define WECHAT_SININ 0x02
#define WECHAT_SIGNOUT 0x04
#define WECHAT_ACK 0x08
#define WECHAT_NAK 0x10
#define WECHAT_SYS 0x20
#define WECHAT_WALL 0x40
#define WECHAT_MSG 0x80
#define WECHAT_FIN 0x100
#define WECHAT_HEART 0x200

struct wechat_msg
{
	int type;
	int sex;
	char from[50];
	char to[50];
	char msg[1024];
};

void *client_recv(void *arg);


void setfd(int epollfd, int subefd1, int subefd2);

void *sub_reactor(void *arg);
void heart_beat(int signum);
// void heart_beat(int signum, int epollfd, int subefd1, int subefd2);

int add_to_reactor(int epollfd, int fd);

#define MAXEVENTS 5
#define MAXUSERS 1024



#endif