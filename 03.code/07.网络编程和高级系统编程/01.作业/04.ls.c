#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include <limits.h>
#include <pwd.h>
#include <grp.h>
#define err_exit(func) {perror(func); exit(EXIT_FAILURE);} //打印出错函数，并结束程序
#define max(a, b) ((a) > (b) ? (a) : (b))
 
typedef struct stat_str{ //字符串形式的stat信息
    char fname[NAME_MAX]; //大概长度，不严谨
    char user[20];
    char group[20];
    char size[16];
    char time[13];
    char mode[11];
    char nlink[5];
    struct stat_str *next; //链表结构，因为需要预先获得目录里的所有项（为了控制格式化），但数目不确定，所以用链表保存
} st_str;
 
int nlink_maxlen = 0, user_maxlen = 0, group_maxlen = 0, size_maxlen = 0; //字符串形式的最大长度，为了格式化构造字符串
int ARG_L = 0, ARG_A = 0, ARG_H = 0, ARG_D = 0; //参数是否定义
 
//解析选项
void analyse_opt(int argc, char* argv[]);
//将文件大小（字节数）转换成易读(human readable)的形式
void human_readable(off_t bytes, char *szbuf);
//构造文件的详细信息
void build_line(const st_str *stat_strbuf, char* fmtstrbuf);
//打印目录信息
void print_dir_info(const char *dir);
//获得文件信息的str形式
void get_stat_str(const struct stat* stbuf, const char* fname, st_str *strbuf);
 
 
int main(int argc, char* argv[]) {
    struct stat stbuf;
    st_str st_strbuf;
    int no_operand = 1; //是否没有操作数
    analyse_opt(argc, argv); //解析选项
 
    //分别获得目录和其他文件，为了格式化输出
    char *files[argc-1], *dirs[argc-1];
     int nf = 0, nd = 0;
    for(int i = 1; i < argc; i++){
        if(argv[i][0] == '-') //跳过选项
            continue;
        else
            no_operand = 0;
        if(-1 == lstat(argv[i], &stbuf))
            err_exit("lstat");
        if(S_ISDIR(stbuf.st_mode))
            dirs[nd++] = argv[i];
        else
            files[nf++] = argv[i]; 
    }
     
    if(no_operand){
        //命令行没有输入路径
        print_dir_info(".");
    } else {
        //先列出文件的信息
        for(int i = 0; i < nf; i++){
            char fmtstrbuf[256];
            if(-1 == lstat(files[i], &stbuf))
                err_exit("lstat");
            get_stat_str(&stbuf, files[i], &st_strbuf);
            if(ARG_L){
                build_line(&st_strbuf, fmtstrbuf);
                puts(fmtstrbuf);
            } else {
                puts(files[i]);
            }           
        }
        //再列出目录的信息
        for(int i = 0; i < nd; i++){
            if(nf > 0)
                printf(" %s: ", dirs[i]);
            print_dir_info(dirs[i]);
        }
    }
    return 0;
}
 
 
void analyse_opt(int argc, char* argv[]){
    int opt;
    while((opt = getopt(argc, argv, "lahd")) != -1){
        switch (opt) {
        case 'l':
            ARG_L = 1;
            break;
        case 'a':
            ARG_A = 1;
            break;
        case 'h':
            ARG_H = 1;
            break;
        case 'd':
            ARG_D = 1;
            break;
        }
    }
}
 
void human_readable(off_t nbytes, char *szbuf){
    if(nbytes < 1024)
        sprintf(szbuf, "%ld\0", nbytes);
    else if(nbytes < 1024 * 1024)
        sprintf(szbuf, "%.1lfK\0", (double)nbytes / 1024);
    else if(nbytes < 1024 * 1024 * 1024)
        sprintf(szbuf, "%.1lfM\0", (double)nbytes / 1024 / 1024);
    else
        sprintf(szbuf, "%.1lfG\0", (double)nbytes / 1024 / 1024 / 1024);
}
 
void get_stat_str(const struct stat* stbuf, const char* fname, st_str *strbuf){
    //mode
    sprintf(strbuf->mode, "%c%c%c%c%c%c%c%c%c%c",
        S_ISREG(stbuf->st_mode) ? '-' : (
            S_ISDIR(stbuf->st_mode) ? 'd' : (
                S_ISBLK(stbuf->st_mode) ? 'b' : (
                    S_ISCHR(stbuf->st_mode) ? 'c' : 'l'
                )
            )
        ),
        (S_IRUSR & stbuf->st_mode ) ? 'r' : '-',
        (S_IWUSR & stbuf->st_mode ) ? 'w' : '-',
        (S_IXUSR & stbuf->st_mode ) ? 'x' : '-',
        (S_IRGRP & stbuf->st_mode ) ? 'r' : '-',
        (S_IWGRP & stbuf->st_mode ) ? 'w' : '-',
        (S_IXGRP & stbuf->st_mode ) ? 'x' : '-',
        (S_IROTH & stbuf->st_mode ) ? 'r' : '-',
        (S_IWOTH & stbuf->st_mode ) ? 'w' : '-',
        (S_IXOTH & stbuf->st_mode ) ? 'x' : '-'
         
    );
    //nlink
    sprintf(strbuf->nlink, "%ld\0", stbuf->st_nlink);
    nlink_maxlen = max(nlink_maxlen, strlen(strbuf->nlink));
    //user, group
    sprintf(strbuf->user, "%s\0", getpwuid(stbuf->st_uid)->pw_name);
    sprintf(strbuf->group, "%s\0", getgrgid(stbuf->st_gid)->gr_name);
    user_maxlen = max(user_maxlen, strlen(strbuf->user));
    group_maxlen = max(group_maxlen, strlen(strbuf->group));
    //size
    if(ARG_H){
        char szbuf[16];
        human_readable(stbuf->st_size, szbuf);
        sprintf(strbuf->size, "%s\0", szbuf);
    } else {
        sprintf(strbuf->size, "%ld\0", stbuf->st_size);
    }
    size_maxlen = max(size_maxlen, strlen(strbuf->size));
    //time
    strftime(strbuf->time, 13, "%b %d %H:%M\0", localtime(&(stbuf->st_mtime)));
    //fname
    sprintf(strbuf->fname, "%s\0", fname);
 
}
 
void build_line(const st_str *stat_strbuf, char* fmtstrbuf){
    char fmt[32];
    sprintf(fmt, "%%s %%%ds %%-%ds %%-%ds %%%ds %%s %%s\0", nlink_maxlen, user_maxlen, group_maxlen, size_maxlen);
    // puts(fmt);
    const char *temp = "/";

    if((stat_strbuf->mode)[0] == 'd')
        strcat(stat_strbuf->fname, "/");
    sprintf(fmtstrbuf, fmt, stat_strbuf->mode, stat_strbuf->nlink, stat_strbuf->user,
        stat_strbuf->group, stat_strbuf->size, stat_strbuf->time, stat_strbuf->fname);
}
 
void print_dir_info(const char *dir){
    if(ARG_D){
        //显式目录本身的信息
        st_str stat_strbuf;
        struct stat stbuf;
        char fmtstrbuf[256];
        if(-1 == lstat(dir, &stbuf))
            err_exit("lstat");
        get_stat_str(&stbuf, dir, &stat_strbuf);
        if(ARG_L){
            build_line(&stat_strbuf, fmtstrbuf);
            puts(fmtstrbuf);
        } else {
            puts(stat_strbuf.fname);
        }
    } else {
        group_maxlen = nlink_maxlen = user_maxlen = size_maxlen = 0;
        //列出目录所有项
        struct DIR *pdir = opendir(dir);
        if(pdir == NULL)
            err_exit("opendir");
        struct dirent *pdirent;
        struct stat stbuf;
        st_str * head_st_str = (st_str*)(malloc(sizeof(st_str))), *p = head_st_str; //链表头（字符串形式的stat）
        //循环都目录
        errno = 0;
        while((pdirent = readdir(pdir)) != NULL){
            if((pdirent->d_name)[0] != '.' || ARG_A) {
                //是否显示隐藏文件
                if(ARG_L) {
                    char path[256];
                    strcpy(path, dir);             //!!!!! 找了一个多小时才找出来这个错误
                    strcat(path, "/");             //!!!!! d_name仅是个文件名而已
                    strcat(path, pdirent->d_name); //!!!!! 需要加上完整路径
                    if(-1 == lstat(path, &stbuf)){
                        err_exit("lstat");
                    }
                    p->next = (st_str*)(malloc(sizeof(st_str)));
                    p = p->next;
                    p->next = NULL;
                    get_stat_str(&stbuf, pdirent->d_name, p);
                } else {
                    puts(pdirent->d_name);
                }
            }
        }
        if(errno != 0)
            err_exit("readdir");
 
        //输出信息链表的格式化内容
        p = head_st_str->next;
        while(ARG_L && p){
            char fmtstrbuf[256];
            build_line(p, fmtstrbuf);
            puts(fmtstrbuf);
            p = p->next;
        }
        if(-1 == closedir(pdir))
            err_exit("closedir");
        st_str *q = head_st_str->next; //释放链表
        while(q){
            free(head_st_str);
            head_st_str = q;
            q = q->next;
        }
        free(head_st_str);
    }
}
