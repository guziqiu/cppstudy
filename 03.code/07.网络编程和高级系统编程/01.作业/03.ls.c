#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[]) {
    DIR             *dp;
    struct dirent   *dirp;

    if(argc != 2) {
        printf("usage: ./myls directory_name\n");
        exit(-1);
    }

    char * dir;
    dir = "./";
    //printf("argv[2] = %s,\n ", argv[2]);
    if (argv[1] == NULL) argv[1] = "./";
    if( (dp = opendir(argv[1])) == NULL ) {
        printf("error: can't open %s\n", argv[1]);
        exit(-1);
    }

    while( (dirp = readdir(dp)) != NULL ) {
        printf("%s ", dirp->d_name);
    }
    printf("\n");

    closedir(dp);

    return 0;
}
