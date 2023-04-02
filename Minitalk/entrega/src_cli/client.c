 #include"client.h"
 
 static void	sigact(int sig)//, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	//(void)context;
	//if (!client_pid)
	//	client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
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

static void	mt_kill(int pid, char *str)
{
	int		i;
	char	c;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if (c >> i & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR1);
		usleep(100);
	}
}

int   main(int av, char **ac)
 {
    if (av != 3 || ft_strlen (ac[2]) == 0) 
      return (1);
    int pid;
    pid = getpid();
	ft_printf("PID proceso cliente: %i \n",pid);
	mt_kill(ft_atoi(ac[1]), ac[2]);
	signal(SIGUSR1, sigact);
	signal(SIGUSR2, sigact);
	mt_kill(ft_atoi(ac[1]), ac[2]);
	while (1)
		pause();
	return (0);

 }