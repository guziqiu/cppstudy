#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>
//socket
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "28.epoll.client.h"
#include "27.epoll.server.h"

// epoll
#include <sys/epoll.h>


#include "24.thread_pool.h"
#include "05.common.h"
