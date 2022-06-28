#include "00.head.h"

int sockfd;
void logout(int signum) {
    close(sockfd);
    printf("ByeBye\n");
    exit(0);
}

int main(int argc, char **argv) {
    int port;
    char buff[512] = {0}, ip[20] = {0},  name[20] = "guziqiu";
    
    if (argc != 3) {
        fprintf(stderr, "Usage:%s is port!\n", argv[0]);
    }
    strcpy(ip, argv[1]);
    port = atoi(argv[2]);
    signal(SIGINT, logout);
    if ((sockfd = socket_connect(ip, port)) < 0) {
        perror("socket_connect");
        exit(1);
    }
    // 连接成功
    

    send(sockfd, name, strlen(name), 0);

    if (recv(sockfd, buff, sizeof(buff), 0) <= 0) {
        perror("recv-client");
        exit(1);
    }

    printf("<Server> : %s \n", buff);





    printf("before loop!\n");
    while (1) {
        sleep(10);
        /*
        printf("<please> : ");
        scanf("%[^\n]s", buff);
        getchar();
        if (!strlen(buff)) continue;
        send(sockfd, buff, strlen(buff), 0);
        printf("sending %s ...\n", buff);
        bzero(buff, sizeof(buff));
        //sleep(1);
        recv(sockfd, buff, sizeof(buff), 0);
        printf("<server> : %s\n", buff);
        bzero(buff, sizeof(buff));
        */
    }

    
    return 0;
}

