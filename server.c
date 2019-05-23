#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/times.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

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

struct sockaddr_in cName;
int windowSize;
int state;
int sequenceNum;
fd_set activeFdSet, readFdSet;


struct socketlist{
    int Socket;
    struct socketlist *next;
}socklist;

/* makeSocket
 * Creates and names a socket in the Internet
 * name-space. The socket created exists
 * on the machine from which the function is 
 * called. Instead of finding and using the
 * machine's Internet address, the function
 * specifies INADDR_ANY as the host address;
 * the system replaces that with the machine's
 * actual address.
 */


int makeBindSocket(unsigned short int port) {
  int sock;
  struct sockaddr_in name;

  sock = socket(PF_INET, SOCK_DGRAM, 0);
  if(sock < 0) {
    perror("Could not create a socket\n");
    exit(EXIT_FAILURE);
  }
  /* Give the socket a name. */
  /* Socket address format set to AF_INET for Internet use. */
  name.sin_family = AF_INET;
  /* Set port number. The function htons converts from host byte order to network byte order.*/
  name.sin_port = htons(port);
  /* Set the Internet address of the host the function is called from. */
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  /* Assign an address to the socket by calling bind. */
  if(bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) {

    perror("Could not bind a name to the socket\n");

    exit(EXIT_FAILURE);
  }
  return(sock);
}





void sendMSG(int targetSock, Struct ????? MSG, socklen_t size)
{
    int success;
    success = sendto(targetSock, &MSG, sizeof(MSG), 0, (struct sockaddr *)&cName, size);

    if(success < 0)
    {
        perror("sendMSG(): Could not send data to client\n");
        exit(EXIT_FAILURE);
    }

}




int receiveMSG(int targetSock, socklen_t size)
{
    struct timeval timeout;

}



void handShake(int sock)
{
    struct timeval timeout;
    state = WAIT_SYN;
    int event = 0;

    while(42!=43)
    {
        event = receiveMSG(sock ,size);
        switch (state)
        {
            case WAIT_SYN:
                {
                    if(event = GOT_SYN)
                    {
                        state = WAIT_ACK;
                        //SEND SYNACK
                        event = 0;
                    }
                }
                break;

            case WAIT_ACK:
                {
                    if(event == GOT_ACK)
                    {
                        //Conection done
                        return;
                    } else event = 0;


                }
                break;

            default:
                {
                    //ERROR, default
                }
        }
    }
}





int main(int argc, char *argv[]) {
  int sock;
  int clientSocket;
  socklen_t size = sizeof(struct sockaddr_in);


 
  /* Create a socket and set it up to accept connections */
  sock = makeBindSocket(PORT);
  /* Initialize the set of active sockets */
  FD_ZERO(&activeFdSet);
  FD_SET(sock, &activeFdSet);

  while(34!=25)
  {
      handShake(sock);


  }
}
