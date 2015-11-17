#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <netinet/in.h>

//메시지 최대 길이
#define MSGLEN 64
//접속자 최대 명수
#define MAXCONNECT 5

static int userlist_fd[MAXCONNECT];
static char userlist_nick[MAXCONNECT][MSGLEN];
//메인과 오른쪽 윈도우 선언
static *mwin, *rwin;

void initwin()
{
  //메인 윈도우, 채팅 로그 출력 부분 선언
  mwin = newwin(20, 52, 2, 1);
  //오른쪽 윈도우, 유저 리스트 출력 부분 선언
  rwin = newwin(MAXCONNECT + 2, 15, 2, 54);
  //글씨 굵게 시작
  attron(A_BOLD);
  //맨 위 메시지 출력
  mvprintw(1,0,"%s","\t\t\tChating Log\t\t\t User List");
  //맨 아래 메시지 출력
  mvprintw(24,1,"Quit - Ctrl + C, MAXCONNECT - %d", MAXCONNECT);
  //글시 굵게 종료
  attroff(A_BOLD);
  //화면 재출력
  refresh();
  //메인 윈도우의 스크롤 기능 키기
  scrollok(mwin, true);
  //커서 숨기기
  noecho();

  //메인 윈도우 테두리 선언
  box(mwin,'|','-'); 
  //오른쪽 윈도우 테두리 선언
  box(rwin,'|','-'); 
  //메인 윈도우 재출력
  wrefresh(mwin);
  //오른쪽 윈도우 재출력
  wrefresh(rwin);
}

void main()
{
	 initscr();

  	 initwin();
	printf("dsadsada");
}
