#include "thread_pool.h"


#define INS 4
#define SIZE 1000
 
int main()
{

	FILE *fp;
	pthread_t tid[INS];
	char buff[SIZE][1024];// 存放读取出来的数据


	struct task_queue *taskQueue = (struct task_queue *)malloc(sizeof(struct task_queue));
	task_queue_init(taskQueue, SIZE); // 初始化线程

	for (int i = 0; i < INS; ++i)
	{
		printf("-->thead %d \n", i);
		pthread_create(&tid[i], NULL, thread_run, (void *)taskQueue); // 创建线程用来做thread_run 传的参数是taskQueue
	}

	while (1)
	{
		if ((fp = fopen("./tmp.txt", "r")) == NULL)
		{
			perror("fopen");
			exit(1);
		}

		int ind;
		// usleep(100000);
		while (fgets(buff[ind], 1024, fp) != NULL)
		{
			task_queue_push(taskQueue, buff[ind]);

			if (++ind == SIZE)
			{
				ind = 0;
			}
			usleep(10000);
		}
		fclose(fp);
	}


	return 0;
}


