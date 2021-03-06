#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>

#define MAXLINE 511
//여기다 귓속말, 채팅창 클리어 등의 기능 추가?? 
int server(int port){
     int serv_sock;
     int conn_sock;
	int option;

    struct sockaddr_in serv_addr;
    struct sockaddr_in conn_addr;

    int addrlen, datalen;

    char buf[MAXLINE +1];
     int nbytes;

    pid_t pid;

    serv_sock = socket(PF_INET,SOCK_STREAM, IPPROTO_TCP);// serv_sock를 소켓 파일 서술자로 만든다.
 
     if(serv_sock == -1){
         perror("socket() error\n");
         exit(0);
     }

    memset(&serv_addr, 0, sizeof(serv_addr));
     serv_addr.sin_family = AF_INET;
     serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
     serv_addr.sin_port = htons(port);
//프로그램을 강제 종료하든 그냥 종료하든 다시 실행하면 bind() 에서 에러가 발생합니다.
//프로그램에서 소켓을 close() 함수를 이용하여 소켓을 소멸 시켜도 커널은 바로 속멸 시키지 않고 몇 초 정도 생명을 유지시켜 줍니다.
//SO_REUSEADDR을 지정해 주면 같은 포트에 대해 다른 소켓이 bind()되는 것을 허락해 주기 때문에 bind()에러 없이 프로그램을 실행할 수 있습니다.
	option = 1;
        setsockopt(serv_sock,SOL_SOCKET,SO_REUSEADDR,&option,sizeof(option));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr,sizeof(serv_addr)) == -1){
         perror("bind() error\n");  //bind(). 소켓 파일 서술자에게 ip, port 주소를 가진 구조체를 넣어준다. 
         exit(0);
     }

    if(listen(serv_sock,1) == -1){ // 소켓 대기열 생성
        perror("listen() error\n");
         exit(0);
     }

    addrlen = sizeof(conn_sock);
    conn_sock = accept(serv_sock, (struct sockaddr*)&conn_addr, &addrlen); //전화오기를 기다림.

    if(conn_sock == -1){
         perror("accept() error\n");
         exit(0);
     }
    else
    {
	printf("\n %s(%d)님이 들어오셨습니다.\n",inet_ntoa(conn_addr.sin_addr),ntohs(conn_addr.sin_port));
    }

    if((pid=fork())==-1){close(conn_sock);perror("fork() error");exit(0);}
     else if (pid == 0){//자식프로세스이다.

        while(1){
            fgets(buf,sizeof(buf),stdin);
             nbytes = strlen(buf);
             write(conn_sock,buf,MAXLINE);
             if((strncmp,"exit",4) == 0){
                 puts("Good Bye.");
                 exit(0);
             } //자식프로세스는 stdin으로 사용자가 입력한 문자를 buf에 저장하여 소켓에다 write 시스템콜을 이용해
        }     //client에게 문자열을 보내고, exit를 입력시 종료하게 한다.
         exit(0);
     }

    else if(pid>0){ //부모프로세스이다.
         while(1){
             if((nbytes = read(conn_sock,buf,MAXLINE)) <0){
                 perror("read() error\n");
                 exit(0);
             }
             printf("\n상대방[%s]: %s",inet_ntoa(conn_addr.sin_addr),buf);
             if(strncmp(buf,"exit",4) == 0)
                 exit(0);
             }//부모프로세스는 client가 소켓에 보낸 문자열을 read로 읽어 저장한다.
         }     //역시 exit 가 날라왔을시에는 종료.
     return 0;
 }

