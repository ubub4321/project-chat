#include <stdio.h>
#include <stdlib.h>
#include <string.h> //bzero
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/select.h>
#define MAX_CLIENT 10 //최대 입장자(클라이언트)수
#define CHATDATA 1024
#define INVALID_SOCK -1
int list_c[MAX_CLIENT]; //채팅 참가중인 클라이언트에 대한 연결소켓 저장
char escape[ ] = "Q";
char greeting[ ] = "Welcome to my chatting room\n";
char CODE200[ ] = "Sorry room is full\n";
char *excapechar = "exit\n"; //exit character insert
void main (int argc, char *argv[])
{
 int server_fd, clinet_fd; //소켓번호 저장용
 int c_socket, s_socket;
 struct sockaddr_in s_addr, c_addr; //SOCKET STRUCTURE
 struct sockaddr_in fd_ser, fd_cli;
 int senline[CHATDATA], rbuf[CHATDATA]; //INPUT VECTOR
 int len;
 int nfds = 0;
 int i,j,n;
 fd_set read_fds;
 char chatData[CHATDATA];
 int res;

	if(argc < 2) //매개변수가 모자르면
	{
		//에러메시지 출력
		printf("ussage : %s TCP_PORT\n", argv[0]);
		return -1;
	}
	//소켓생성
	if((server_fd = socket(PF_INET, SOCK_STREAM, 0)) <0)
	{
		printf("server : can't open stream socket\n");
		return -1;
	}

	printf("SOCKET = %d\n",server_fd); //소켓번호출력
	
	bzero((char *)&server_addr, sizeof(server_addr)); //serveraddr 0으로 초기화
	bzero((char *)&fd_ser, sizeof(server_addr)); //initialization
	bzero((char *)&fd_cli, sizeof(server_addr));
 }
