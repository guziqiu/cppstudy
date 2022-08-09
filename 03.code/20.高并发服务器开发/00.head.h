#ifndef _HEAD_H
#define _HEAD_H


#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/sem.h>
#include <sys/ioctl.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <ctype.h>
#include <dirent.h>

#include "01.color.h"
#ifdef _D
#define DBG(fmt, arg...) print(fmt, ##arg)
#else
#define DBG(fmt, arg...)
#endif

#endif