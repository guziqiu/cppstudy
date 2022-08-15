#include "thread_pool.h"


#define INS 4
#define SIZE 1000
 
void task_queue_init(struct task_queue *taskQueue, int size)
{
	taskQueue->size = size;
	taskQueue->total = taskQueue->head = taskQueue->tail = 0;
	taskQueue->data = calloc(size, sizeof(void *));
	pthread_mutex_init(&taskQueue->mutex, NULL);
	pthread_cond_init(&taskQueue->cond, NULL);

	return ;
}

void task_queue_push(struct task_queue *taskQueue, void *data)
{
	pthread_mutex_lock(&taskQueue->mutex);
	if (taskQueue->total == taskQueue->size)
	{
		DBG(YELLOW"<push>: taskQueue id full\n" NONE);
		pthread_mutex_unlock(&taskQueue->mutex);
		return ;
	}

	DBG(GREEN"<PUSH>: "RED" data" NONE " is pushed!\n");
	taskQueue->data[taskQueue->tail] = data;
	taskQueue->tail++;
	taskQueue->total++;

	if (taskQueue->tail == taskQueue->size)
	{
		DBG(YELLOW"<PUSH> taskQUeue reach tail!\n" NONE);
		taskQueue->tail = 0;
	}

	pthread_cond_signal(&taskQueue->cond);
	pthread_mutex_unlock(&taskQueue->mutex);
	return ;
}

void *task_queue_pop(struct task_queue *taskQueue)
{
	pthread_mutex_lock(&taskQueue->mutex);
	while (0 == taskQueue->total) // 唤醒后拿到锁
	{
		pthread_cond_wait(&taskQueue->cond, &taskQueue->mutex);
		// pthread_cond_wait 会自动解锁 if -> while
		// 被唤醒时，会自动加上锁

		// 条件变量为什么要跟互斥锁一起使用 ?
	}

	void *data = taskQueue->data[taskQueue->head];
	DBG(GREEN"<POP> : " BLUE "data"NONE" is pop\n");
	taskQueue->total--;
	taskQueue->head++;

	if (taskQueue->head == taskQueue->size)
	{
		DBG(YELLOW"<POP>: taskQUeue reach tail!\n" NONE);
		taskQueue->head = 0;
	}
	pthread_mutex_unlock(&taskQueue->mutex);

	return data;
}

void *thread_run(void *arg)
{
	pthread_detach(pthread_self());

	struct task_queue *taskQueue = (struct task_queue *)arg;

	while (1)
	{
		void *data = task_queue_pop(taskQueue);
		printf("%d: %s\n", taskQueue->tail, (char*)data);
	}
}


extern int sockfd;
extern char *data[2000];
extern pthread_mutex_t mutex[2000];
void  do_work(int fd)
{
	char buff[4096] = {0};
	DBG(BLUE"<R> : data is ready on %d.\n"NONE, fd);
	int rsize = 0;
	int ind = strlen(data[fd]);

	if ( (rsize = recv(fd, buff, sizeof(buff), 0)) < 0) // recv是线程安全的
	{
		 if (errno != EAGAIN)
		 {
			epoll_ctl(sockfd, EPOLL_CTL_DEL, fd, NULL);
			DBG(RED"<C> : %d is closed!.\nn"NONE, fd);
			close(fd);
		 }

		return ;
	}

	pthread_mutex_lock(&mutex[fd]);
	for (int i = 0; i < rsize; ++i)
	{
		if (buff[i] >= 'A' && buff[i] <= 'Z')
		{
			data[fd][ind++] = buff[i] + 32;
		}
		else if (buff[i] >= 'a' && buff[i] <= 'z')
		{
			data[fd][ind++] = buff[i] - 32;
		}
		else
		{
			data[fd][ind++] = buff[i];
			if (buff[i] == '\n')
			{
				DBG(GREEN"<END> : \\n recved!.\n"NONE);
				send(fd, data[fd], ind, 0);
			}
		}
	}

	pthread_mutex_unlock(&mutex[fd]);

}


void *worker(void *arg)
{
	pthread_detach(pthread_self());

	struct task_queue *taskQueue = (struct task_queue *)arg;

	while (1)
	{
		int *fd = (int *)task_queue_pop(taskQueue);
		do_work(*fd);
	}
}
