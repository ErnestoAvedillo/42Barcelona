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

int dying_cntrol(t_list_philo *philos)
{
	if (get_time() - philos->die->t1 >= philos->die->time || philos->die->status)
	{
		philos->die->status = 1;
		print_status(philos, "is dead", BCK_RED);
		return (1);
	}
	return (0);
	
}

int process_eating(t_list_philo *philos)
{
	pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]);
	print_status(philos, "has taken left fork ",BCK_GREEN);
	pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]);
	print_status(philos, "has taken right fork",BCK_GREEN);
	if (dying_cntrol(philos))
		return (0);
	philos->die->t1 = get_time();
//	philos->think = 0;
//	philos->eat->status = 1;
	print_status(philos, "is eating", BCK_YELLOW);
	ft_usleep(philos->eat->time, philos);
	print_status(philos, "finish eating", BCK_STD);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
//	philos->eat->status = 0;
	philos->nr_eats++ ;
	return (1);
}

int process_sleeping(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
//	philos->sleep->status = 1;
	print_status(philos, "is sleeping", BCK_CYAN);
	ft_usleep(philos->sleep->time, philos);
	philos->sleep->status = 0;
	return (1);
}

int process_thinking(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
//	philos->think = 1;
	print_status(philos, "is thinking",BCK_CYAN);
//	philos->think = 0;
	return (1);
}

void *work_proc(void *var)
{
	t_list_philo *philos;
	
	philos = (t_list_philo *)var;
	while(!philos->start)
		usleep(1);
	usleep (((philos->philo_nr + 1) % 2) * philos->eat->time);
	philos->die->t1 = get_time();
	//while (!philos->die->status)
	while(process_eating(philos) && process_sleeping(philos) && process_thinking(philos))
	{
	/*	if (!process_eating(philos))
			break;
		if (!process_sleeping(philos))
			break;
		philos->think = 1;
		print_status(philos, "is thinking",BCK_CYAN);
	*/	if(philos->lim_eats && philos->lim_eats == philos->nr_eats )
			break;
	}
	pthread_mutex_unlock (&philos->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock (&philos->mutex_forks[philos->fork_rght]);
//	print_status(philos, "is dead        ", BCK_RED);
	return (philos);
}