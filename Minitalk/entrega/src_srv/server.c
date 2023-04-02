#include"server.h"

static void	sigact(int sig)//, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

//	(void)context;
//	if (!client_pid)
//		client_pid = info->si_pid;
	c = (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(c, 1);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}

static void	exit_handler(int i)
{
	printf("int recibido = %i",i);
//	(void)i;
	exit (0);
}

int main (void)
{
	int pid;
	
	pid = getpid();
	ft_printf("Server PID: %i \n",pid);
	signal(SIGUSR1, sigact);
	signal(SIGUSR2, sigact);
	signal(SIGINT, exit_handler);
	signal(SIGTERM, exit_handler);
	while (1)
		pause();
	return (0);
}