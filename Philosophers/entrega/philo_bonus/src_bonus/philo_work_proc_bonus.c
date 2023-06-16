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

#include"philo_bonus.h"

int	process_eating(t_list_philo *philos)
{
	sem_wait(philos->header->sem_forks);
	print_status(philos, "taken 1st fork ", BCK_GREEN);
	sem_wait(philos->header->sem_forks);
	print_status(philos, "taken 2nd fork", BCK_GREEN);
	philos->die_t1 = get_time();
	if (ft_usleep(1, philos))
		return (0);
	sem_post(philos->header->sem_forks);
	sem_post(philos->header->sem_forks);
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
		sem_wait(philos->header->sem_forks);
		print_status(philos, "taken 1st fork ", BCK_GREEN);
		ft_usleep(1, philos);
		philos->header->isdead = 1;
		sem_post(philos->header->sem_forks);
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
	one_philo(philos);
	usleep(((philos->philo_nr + 1) % 3) * philos->header->eat*100);
	while (!philos->header->isdead && process_eating(philos) && \
		process_sleeping(philos))
		process_thinking(philos);
	sem_post(philos->header->sem_forks);
	sem_post(philos->header->sem_forks);
	sem_post(philos->header->sem_prt);
	return (philos);
}
