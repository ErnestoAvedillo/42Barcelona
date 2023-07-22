/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_work_proc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 17:12:26 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/23 17:12:30 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	process_eating(t_list_philo *philos)
{
	pthread_mutex_lock(&philos->header->mutex_forks[philos->fork_left]);
	print_status(philos, "taken left fork ", BCK_GREEN);
	pthread_mutex_lock(&philos->header->mutex_forks[philos->fork_rght]);
	print_status(philos, "taken right fork", BCK_GREEN);
	philos->die_t1 = get_time();
	if (ft_usleep(1, philos))
		return (0);
	pthread_mutex_unlock(&philos->header->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->header->mutex_forks[philos->fork_rght]);
	philos->nr_eats++ ;
	return (1);
}

int	process_sleeping(t_list_philo *philos)
{
	if (ft_usleep(0, philos))
		return (0);
	return (1);
}

int	process_thinking(t_list_philo *philos)
{
	print_status(philos, "is thinking", BCK_CYAN);
	return (1);
}

int	one_philo(t_list_philo *philos)
{
	if (philos->header->nr_ph == 1)
	{
		pthread_mutex_lock(&philos->header->mutex_forks[philos->fork_left]);
		print_status(philos, "taken left fork ", BCK_GREEN);
		usleep(philos->header->die * 1000);
		philos->header->isdead = 1;
		pthread_mutex_unlock (&philos->header->mutex_forks[philos->fork_left]);
		return (1);
	}
	return (0);
}

void	*work_proc(void *var)
{
	t_list_philo	*philos;

	philos = (t_list_philo *)var;
	while (!philos->header->start)
		usleep(1);
	philos->die_t1 = get_time();
	usleep(((philos->philo_nr + 1) % 2) * philos->header->eat * 1000);
	one_philo(philos);
	while (!philos->header->isdead && process_eating(philos) && \
		process_sleeping(philos))
		process_thinking(philos);
	pthread_mutex_unlock (&philos->header->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->header->mutex_forks[philos->fork_rght]);
	pthread_mutex_unlock(philos->header->mutex_prt);
	pthread_mutex_unlock(philos->header->dead);
	return (philos);
}
