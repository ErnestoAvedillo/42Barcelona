#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_SIZE 1000000
#define MAX_CLIENTS 1024

typedef struct s_client
{
	int fd;
	char text[MAX_SIZE];
} t_client;

t_client client[MAX_CLIENTS];

int cur_fd = 0;
int max_fd = 0;


fd_set read_set;
fd_set write_set;
fd_set cur_set;

char sent_buff[MAX_SIZE];
char recive_buff[MAX_SIZE];

int putstr(int fd, char *str)
{
	int i=0;
	int out=0;
	while (str[i] != '\0')
	{
		out += write(fd, &str[i],1);
		i++;
	}
	return out;
}
int prterr(char *str)
{
	if(!str)
		putstr(2, "Fatal error\n");
	else
		putstr(2, str);
	exit (1);
}
void send_transm(int cur_fd)
{
	for (int fd=0; fd <= max_fd; fd ++)
	{
		if (FD_ISSET(fd, &write_set) && cur_fd != fd)
		{
			if (send(fd,sent_buff,strlen(sent_buff),0) == -1)
				prterr(NULL);
		}
	}
}

int main (int av, char **ac)
{
	if (av != 2)
		prterr("Wrong number of arguments\n");

	int port = atoi(ac[1]);
	int sockfd, connfd;

	struct sockaddr_in servaddr;

	// socket create and verification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) 
	{ 
		prterr(NULL);
	} 

	bzero(&servaddr, sizeof(servaddr)); 
	
	FD_ZERO(&cur_set);
	FD_SET(sockfd,&cur_set);
	max_fd = sockfd;
	
	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(port); 
  
	// Binding newly created socket to given IP and verification 
	if ((bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) 
		prterr(NULL); 
	if (listen(sockfd, 10) != 0) 
		prterr(NULL); 
	while (1)
	{
		read_set = write_set = cur_set;
		if (select(max_fd+ 1, &read_set, &write_set, NULL, NULL) == -1)
			prterr(NULL);
		for (int fd = 0; fd <= max_fd; fd++)
		{
			if(FD_ISSET(fd, &read_set))
			{
				struct sockaddr_in cli;
				socklen_t len = sizeof(cli);
				connfd = accept(sockfd, (struct sockaddr *)&cli, &len);
				if (connfd < 0)
					prterr(NULL);
				else if (connfd > max_fd)
					max_fd = connfd;
				client[connfd].fd = cur_fd;
				cur_fd ++;
				FD_SET(connfd, &cur_set); 
				sprintf(sent_buff,"server: client %d just arrived\n",client[connfd].fd);
				send_transm(connfd);
			}
			else
			{
				int rec;
				rec = recv(fd, recive_buff,MAX_SIZE, 0);
				if (rec <= 0)
				{
					sprintf(sent_buff,"server: client %d just left\n",client[fd].fd);
					send_transm(fd);
					FD_CLR(fd,&cur_set);
					close(fd);
				}
				else
				{
					for (int i = 0,  j = strlen(client[fd].text); i < rec; i++, j ++)
					{
						client[fd].text[j] = recive_buff[i];
						if (client[fd].text[j] == '\n')
						{
							client[fd].text[j] = '\0';
							sprintf(sent_buff, "client %d: %s\n",client[fd].fd,client[fd].text);
							send_transm(fd);
							bzero(client[fd].text, strlen(client[fd].text));
							j = -1;
						}
					}
				}
			}
		}

	}
	
	return (0);

}
