.PHONY: clean


libfuncs.a: server.o client.o
	ar rv libfuncs.a server.o client.o
%.o: %.c
	gcc -c -g -Wall $< -o $@  
clean:
	rm -f libfuncs.a server.o client.o
