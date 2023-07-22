#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 1
#endif

char *get_next_line(int fd)
{
	int i = 0;
	int rd;
	static char current;
	char *out;

	if(BUFFER_SIZE <= 0)
		return (NULL);
	out = (char *)malloc (1000000 * sizeof(char));
	while((rd = read(fd, &current, BUFFER_SIZE-BUFFER_SIZE+1))>0)
	{
		out[i++] = current;
		if (current == '\n')
			break ;
	}
	out[i]='\0';
	if(rd == -1 || rd == 0 || (out[i-1] == 0 && rd == 0))
		return (free(out), NULL);
	return (out);
}

int main()
{
	int fd;
	char *out;

	fd= open("subject.en.txt",O_RDONLY);
	out=get_next_line(fd);
	printf("entro %s",out);
	while((out=get_next_line(fd)))
		printf("%s",out);
	return (0);

}
