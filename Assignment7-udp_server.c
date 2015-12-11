#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
 
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 1567 
#define BUFSIZE 200

int main(int argc, char *argv)
{
struct sockaddr_in serv_addr; /* server address */ 
struct sockaddr_in client_addr; /* client address */ 
socklen_t addrlen = sizeof(client_addr); /* length of address */ 
int recvlen; /* number of bytes received */ 
int fd; /*socket descriptor*/ 
unsigned char buf[BUFSIZE]; /* receive buffer */ 

/* create a UDP socket */ 
if ((fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) { 
	perror("cannot create socket\n"); return 0; } /* bind the socket to any valid IP address and a specific port */ 

memset((char *)&serv_addr, 0, sizeof(serv_addr)); 
serv_addr.sin_family = AF_INET; 
serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); /*to listen on all interfaces*/
serv_addr.sin_port = htons(PORT); 

if (bind(fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { 
	perror("bind failed"); return 0; } 

for (;;){ //runs forever
	printf("waiting on port %d\n", PORT); 
	recvlen = recvfrom(fd, buf, BUFSIZE, 0, (struct sockaddr *)&client_addr, &addrlen); 
	printf("received %d bytes\n", recvlen); 
		if (recvlen > 0) { 
		buf[recvlen] = 0; 
		printf("received message: \"%s\"\n", buf);
		sendto(fd, buf, strlen(buf), 0, (struct sockaddr *)&client_addr, sizeof(client_addr));} 
        }
close(fd);
}


