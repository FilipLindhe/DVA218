/* File: client.c
 * Trying out socket communication between processes using the Internet protocol family.
 * Usage: client [host name], that is, if a server is running on 'lab1-6.idt.mdh.se'
 * then type 'client lab1-6.idt.mdh.se' and follow the on-screen instructions.
 */

#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
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
#define INIT 0
#define SYN 4

struct linkedLists{
    int flag;
    int id;
    int seq;
    int windowSize;
    int crc;
    char *data;
    struct linkedList *next;

} linkedList;

pthread_t thread1;
pthread_mutex_t lock;
void *readconnections(int sock);

void checkSum(struct linkedList* checkSumList){


}

/* initSocketAddress
 * Initialises a sockaddr_in struct given a host name and a port.
 */
void initSocketAddress(struct sockaddr_in *name, char *hostName, unsigned short int port) {
  struct hostent *hostInfo; /* Contains info about the host */
  /* Socket address format set to AF_INET for Internet use. */
  name->sin_family = AF_INET;     
  /* Set port number. The function htons converts from host byte order to network byte order.*/
  name->sin_port = htons(port);   
  /* Get info about host. */
  hostInfo = gethostbyname(hostName); 
  if(hostInfo == NULL) {
    fprintf(stderr, "initSocketAddress - Unknown host %s\n",hostName);
    exit(EXIT_FAILURE);
  }
  /* Fill in the host name into the sockaddr_in struct. */
  name->sin_addr = *(struct in_addr *)hostInfo->h_addr;
}
/* writeMessage
 * Writes the string message to the file (socket) 
 * denoted by fileDescriptor.
 */


void connection(fileDescriptor, socklen_t size){


    struct linkedLists CL;
    CL.flag = SYN;
    strcpy(CL->data, "hejsan\n");
    CL.seq = -1;
    CL.id = 0;
    CL.crc = checkSum(&CL);
    


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


