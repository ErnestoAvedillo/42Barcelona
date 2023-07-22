/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time_tool.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 07:15:19 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/07 07:15:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

/*
* i = 1 eating
* i = 0 sleeping
*/
int	ft_usleep(int i, t_list_philo *philos)
{
	long long int	init;
	int				nbr;

	pthread_mutex_lock(philos->header->dead);
	pthread_mutex_unlock(philos->header->dead);
	if (philos->header->isdead)
		return (1);
	if (i)
	{
		nbr = philos->header->eat;
		print_status(philos, "is eating", BCK_YELLOW);
	}
	else
	{
		nbr = philos->header->sleep;
		print_status(philos, "is sleeping", BCK_CYAN);
	}
	init = get_time();
	while (nbr > get_time() - init)
	{
		if (philos->header->isdead)
			return (1);
		usleep(1000);
	}
	return (0);
}
