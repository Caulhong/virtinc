client server:client.o server.o
	cc -o client client.o
	cc -o server server.o

client.o:client.c tiny_web.h
	cc -c client.c
server.o:server.c tiny_web.h
	cc -c server.c
clean :
	rm client server client.o server.o