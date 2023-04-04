/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 12:24:01 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/04 12:24:03 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"client.h"

static void	sigact(int sig)
{
	static int	received = 0;

	if (sig == SIGUSR1)
		++received;
	else
	{
		ft_printf("Charachters recived %i\n", received);
		exit(0);
	}
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

int	main(int av, char **ac)
{
	int	pid;

	if (av != 3 || ft_strlen (ac[2]) == 0)
		return (1);
	pid = getpid();
	ft_printf("PID proceso cliente: %i \n", pid);
	signal(SIGUSR1, sigact);
	signal(SIGUSR2, sigact);
	mt_kill(ft_atoi(ac[1]), ac[2]);
	while (1)
		pause();
	return (0);
}
