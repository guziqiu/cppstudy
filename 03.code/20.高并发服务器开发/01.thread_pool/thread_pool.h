
#ifndef _THREAD_POOL_H
#define _THREAD_POOL_H

#include "00.head.h"
#include "01.color.h"

struct task_queue
{
	// 循环队列
	int head;
	int tail;
	int size;
	int total;
	void **data;

	// 锁 信号量
	pthread_mutex_t mutex; 
	pthread_cond_t cond;
};

void task_queue_init(struct task_queue *taskQueue, int size);
void task_queue_push(struct task_queue *taskQueue, void *data);
void *task_queue_pop(struct task_queue *taskQueue);

void *thread_run(void *arg); // 线程处理函数

#endif