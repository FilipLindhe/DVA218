#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/times.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

#define PORT 49153
#define hostNameLength 50
#define messageLength  256
#define MAXMSG 512
#define message 10
#define WAIT_SYN 1
#define WAIT_ACK 2
#define WAIT_SYNACK 3
#define GOT_SYN 4
#define GOT_ACK 5
#define GOT_SYNACK 6
#define INIT 0

typedef struct rtp struct {
    int flags ;
    int id;
    int seq ;
    int windowsize;
    int crc ;
    char *data;
} rtp;


struct sockaddr_in cName;
int activeWindowSize = 2;
int state;
int sequenceNum;
fd_set activeFdSet, readFdSet;


void initSocketAddress(struct sockaddr_in *name, char *hostName, unsigned short int port) {
  struct hostent *hostInfo; /* Contains info about the host */
  /* Socket address format set to AF_INET for Internet use. */
  name->sin_family = AF_INET;     
  /* Set port number. The function htons converts from host byte order to network byte order.*/
  name->sin_port = htons(port);   
  /* Get info about host. */
  hostInfo = gethostbyname(hostName); 
  if(hostInfo == NULL) {
    fprintf(stderr, "initSocketAddress(): Unknown host %s\n",hostName);
    exit(EXIT_FAILURE);
  }
  /* Fill in the host name into the sockaddr_in struct. */
  name->sin_addr = *(struct in_addr *)hostInfo->h_addr;
}




void sendMSG(int targetSock, rtp MSG, socklen_t size)
{
    int success;
    success = sendto(targetSock, &MSG, sizeof(MSG), 0, (struct sockaddr *)&cName, size);

    if(success < 0)
    {
        perror("sendMSG(): Could not send data to client\n");
        exit(EXIT_FAILURE);
    }

}


int receiveFlag(int targetSock, socklen_t size)
{
    rtp MSG;
    recvfrom(sock, (void*)&MSG, sizeof(struct rtp), 0, (struct sockaddr*)&cName, size);
    return MSG.flags;
}



int receiveMSG(int targetSock, socklen_t size)
{
    struct timeval timeout;
    //...
}






int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_in serverName;
  char hostName[hostNameLength];
  char messageString[messageLength];
  char buffer[MAXMSG];
  char in[message];


  /* Check arguments */
  if(argv[1] == NULL) {
    perror("Usage: client [host name]\n");
    exit(EXIT_FAILURE);
  }
  else {
    strncpy(hostName, argv[1], hostNameLength);
    hostName[hostNameLength - 1] = '\0';
  }
  /* Create the socket */
  sock = socket(PF_INET, SOCK_DGRAM, 0);
  if(sock < 0) {
    perror("Could not create a socket\n");
    exit(EXIT_FAILURE);
  }
  /* Initialize the socket address */
  initSocketAddress(&serverName, hostName, PORT);


  printf("Do you want to connect to the server?\n")

  fflush(stdin);
  fgets(in, 10, stdin);

  if(strcmp(, "y")==0) {
      connection(sock, sizeof(serverName));

  }
  else{
      close(sock);
      return 0;
  }




}


