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
	print_status(philos, "is eating", BCK_YELLOW);
	philos->die_t1 = get_time();
	if(ft_usleep(philos->header->eat, &philos->header->isdead))
		return (0);
	pthread_mutex_unlock(&philos->header->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->header->mutex_forks[philos->fork_rght]);
	philos->nr_eats++ ;
	return (1);
}

int	process_sleeping(t_list_philo *philos)
{
	print_status(philos, "is sleeping", BCK_CYAN);
	if (ft_usleep(philos->header->sleep, &philos->header->isdead))
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
	if (philos->max_philos == 1)
	{
		pthread_mutex_lock(&philos->header->mutex_forks[philos->fork_left]);
		print_status(philos, "taken left fork ", BCK_GREEN);
		if (ft_usleep(philos->header->eat, &philos->header->isdead))
			return (1);
		philos->header->isdead = 1;
		print_status(philos, "is dead", BCK_RED);
		pthread_mutex_unlock (&philos->header->mutex_forks[philos->fork_left]);
		return (1);
	}
	return (0);
}

void	*work_proc(void *var)
{
	t_list_philo	*philos;
	int				finished;

	philos = (t_list_philo *)var;
	while (!philos->start)
		usleep(1);
	philos->die_t1 = get_time();
	ft_usleep(((philos->philo_nr + 1) % 2) * philos->header->eat / 4, \
		&philos->header->isdead);
	if (one_philo(philos))
		return (philos);
	finished = 1;
	while (finished)
		finished = process_eating(philos) && process_sleeping(philos) && \
			process_thinking(philos);
	pthread_mutex_unlock (&philos->header->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->header->mutex_forks[philos->fork_rght]);
	pthread_mutex_unlock(philos->header->mutex_prt);
	pthread_mutex_unlock(philos->header->dead);
	return (philos);
}
