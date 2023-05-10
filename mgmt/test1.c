#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
struct _msgbuf
{
	long type;
	char msg[10];
};
int main()
{
	while(1)
	{
		key_t key = ftok(".", 1);
		int msgqid = msgget(key, IPC_CREAT|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) ;
		struct _msgbuf msgbuf;
		strcpy(msgbuf.msg, "hello");
		msgbuf.type = 1;
		int res = msgsnd(msgqid, &msgbuf, 10, 0);
		if (res < 0) {
			perror("msgrcv error");
			return -1;
		}else{
			printf("send finish\n");
		}
	}
	return 0;	
}
