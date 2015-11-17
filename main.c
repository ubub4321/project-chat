#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
void main (int argc, char *argv[])
{
 int c_socket, s_socket;
 struct sockaddr_in s_addr, c_addr;
 int len;
 int nfds = 0;
 int i,j,n;
 fd_set read_fds;
 char chatData[CHATDATA];
 int res;
 }
