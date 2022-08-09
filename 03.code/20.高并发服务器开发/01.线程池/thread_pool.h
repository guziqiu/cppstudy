
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

struct task_queue
{
	// 循环队列
	int head, tail, size, total;
	void **data;
	pthread_mutex_t mutex; 
	pthread_cond_t cond;
};

void task_queue_init()


#endif