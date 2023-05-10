#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
struct _msgbuf
{
	long type;
	char msg[128];
};
int main(int argc, char ** argv)
{
	key_t key = ftok(".", 0);
	int msgqid = msgget(key, IPC_CREAT|S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) ;
	struct _msgbuf msgbuf;
	int addr, size, operation;
	addr = atoi(argv[1]);
	size = atoi(argv[2]);
	operation = atoi(argv[3]);
	sprintf(msgbuf.msg, "%d %d %d", addr, size, operation);
	msgbuf.type = 1;
	int res = msgsnd(msgqid, &msgbuf, 128, 0);
	if (res < 0) {
		perror("msgrcv error");
		return -1;
	}else{
		printf("send finish\n");
	}
	return 0;	
}

