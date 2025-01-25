#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_TXT 1000000
#define MAX_CLI 1024

typedef struct s_client{
	int id;
	char txt[MAX_TXT];
} t_client;

t_client client[MAX_CLI];

fd_set write_fd;
fd_set read_fd;
fd_set curr_fd;

int curr_id = 0;
int max_fd = 0;

char send_buff[MAX_TXT + 20];
char rec_buff[MAX_TXT];

void putstr ( int fd, char *str)
{
	int i = 0;
	while (str[i] !=0)
	{
		write(fd, &str[i],1);
		i++;
	}
}

void prterr ( char *str)
{
	if (str == NULL)
		putstr(2, "Fatal error\n");
	else
		putstr(2, str);
	exit(1);
}

void send_transm (int acc)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if(FD_ISSET(fd,&write_fd) && fd != acc)
		{
			if (send(fd, send_buff, strlen(send_buff),0) == -1)
				prterr(NULL);
		}	
	}
	
}

int main (int av, char **ac)
{
	int port = 0;
	if(av != 2)
		prterr("Wrong number of arguments\n");
	port = atoi(ac[1]);
	int sockfd, connfd;
        socklen_t len;
	struct sockaddr_in servaddr, cli; 

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		prterr(NULL);
	} 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
	bzero(&curr_fd, sizeof(curr_fd));
	FD_SET(sockfd,&curr_fd);
	max_fd = sockfd;	

	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { 
		prterr(NULL);
	} 
	if (listen(sockfd, 10) != 0) {
		prterr(NULL);
	}
	
	while(1)
	{
		read_fd = write_fd = curr_fd;
		if(select(max_fd + 1,&read_fd, &write_fd, NULL, NULL) == -1)
			prterr(NULL);
		for (int fd = 0; fd <= max_fd; fd++ )
		{
			if (FD_ISSET(fd, &read_fd))
			{
				if (fd== sockfd)
				{
				
					len = sizeof(cli);
					bzero(&cli,sizeof(cli));
					connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
					if (connfd < 0)
						prterr(NULL);
					if (connfd > max_fd)
						max_fd = connfd;
					client[connfd].id = curr_id;
					curr_id++ ;
					FD_SET(connfd,&curr_fd);
					sprintf(send_buff,"server: client %d just arrived\n", client[connfd].id);
					send_transm(connfd);
    					 
				}
				else
				{
					int rec = recv(fd, rec_buff, MAX_TXT,0);
					if (rec <=0 )
					{
						sprintf(send_buff, "server: client %d just left\n", client[fd].id);
						send_transm(fd);
						FD_CLR(fd, &curr_fd);
						bzero(client[fd].txt, sizeof(client[fd].txt));
						close(fd);
					}
					else
					{
						for(int i = 0, j = strlen(client[fd].txt); i < rec; i++, j++)
						{
							client[fd].txt[j] = rec_buff[i];
							if (client[fd].txt[j] == '\n')
							{
								client[fd].txt[j] = '\0';
								sprintf(send_buff, "client %d: %s\n", client[fd].id, client[fd].txt);
								send_transm(fd);
								bzero(client[fd].txt, sizeof(client[fd].txt));
								j = -1;
							}
						}
					}
				}
			}
		}
	}


}


