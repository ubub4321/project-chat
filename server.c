#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#define MAXLINE 511

int main(int argc,char* argv[])
{
	int serv_sock;
	int conn_sock;

	struct sockaddr_in serv_addr;
	struct sockaddr_in conn_addr;

	int addrlen, datalen;
	
	char buf[MAXLINE + 1];
	int nbytes;
	
	pid_t pid;

	if(argc != 2)
	{
		printf("Usage : %s <port>\n", argv[0]);
		exit(0);
	}

	serv_sock = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);
	if(serv_sock == -1)
	{
		perror("socket() error\n");
		exit(0);
	}
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_addr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
	{
		perror("bind() error\n");
		exit(0);
	}

	addrlen = sizeof(conn_sock);

}
