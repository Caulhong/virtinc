#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include <string.h>
struct _msgbuf
{
    long type;
	char msg[10];
    int a;
};
int main()
{
	key_t key = ftok(".", 1);
    int msgqid = msgget(key, IPC_CREAT|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH);
    struct _msgbuf msgbuf;
    msgbuf.type = 1;
    msgrcv(msgqid, &msgbuf, 10, 1, 0);
    printf("%s\n", msgbuf.msg);
    printf("fukkkkk  %d\n", msgbuf.a);
    msgbuf.type = 2;
    int res = msgsnd(msgqid, &msgbuf, 10, 0);
    if (res < 0) {
        perror("msgrcv error");
        return -1;
    }else{
        printf("send finish\n");
    }
	return 0;	
}

