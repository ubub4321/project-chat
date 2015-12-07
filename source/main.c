#include <stdio.h>

void main()
{
	//server port number
	server(4000);
	//client ip, server port
	client("127.0.0.1",4000);
}
