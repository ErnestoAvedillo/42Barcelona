/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:23:42 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/04 12:23:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"server.h"

pid_t	close_com(pid_t client_pid, void *context)
{
	kill(client_pid, SIGUSR2);
	return ((pid_t) 0);
	(void)context;
}

static void	sigact(int sig, siginfo_t *info, void *context)
{
	static int				i = 0;
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;

	if (!client_pid)
		client_pid = info->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (c)
		{
			write(1, &c, 1);
			c = 0;
			kill(client_pid, SIGUSR1);
		}
		else
		{
			client_pid = close_com(client_pid, context);
			return ;
		}
	}
	else
		c <<= 1;
}

static void	exit_handler(int i)
{
	(void)i;
	exit (0);
}

int	main(void)
{
	int					pid;
	struct sigaction	s_action;

	pid = getpid();
	ft_printf("Server PID: %i \n", pid);
	s_action.sa_sigaction = sigact;
	s_action.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &s_action, 0);
	sigaction(SIGUSR2, &s_action, 0);
	signal(SIGINT, exit_handler);
	signal(SIGTERM, exit_handler);
	while (1)
	{
	}
	return (0);
}
