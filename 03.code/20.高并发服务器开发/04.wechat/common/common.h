#ifndef _COMMON_H
#define _COMMON_H

int socket_create(int port);
int socket_connect(const char *ip, int port);
int make_nonblock(int fd);

int make_block(int fd);

int get_conf_val_int(const char *file, const char *key);
char *get_conf_val(const char *file, const char *key);

// char ans[512];

#endif