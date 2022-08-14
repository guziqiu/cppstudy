#include "00.head.h"

// 5s中之内输入值，输出内容
// 5s中之后，输出0

int main()
{
	int flag = 0;

	// make_nonblock(0);
	// sleep(5);

	fd_set rfds;
	FD_ZERO(&rfds);
	FD_SET(0, &rfds);

	// 设置超时时间
	struct timeval tv;
	tv.tv_sec = 5;
	tv.tv_usec = 0;

	int nfds = select(0 + 1, &rfds, NULL, NULL, &tv);

	if (nfds > 0)
	{
		printf("input found !\n");
		scanf("%d", &flag);
	}
	else
	{
		printf(RED"time out!\n"NONE);
	}

	printf("flag = %d\n", flag);;
}