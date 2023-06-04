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
	if(*philos->isdead)
		return (1);
	if (get_time() - philos->die->t1 >= philos->die->time || philos->die->status)
	{
		philos->die->status = 1;
		*philos->isdead = 1;
		print_status(philos, "is dead", BCK_RED);
		return (1);
	}
	if(philos->lim_eats && philos->lim_eats == philos->nr_eats )
	{
		print_status(philos, "meals eaten", BCK_RED);
		return (1);
	}
	return (0);
	
}

int process_eating(t_list_philo *philos)
{
	pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]);
	print_status(philos, "taken left fork ",BCK_GREEN);
	pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]);
	print_status(philos, "taken right fork",BCK_GREEN);
	if (dying_cntrol(philos))
		return (0);
	print_status(philos, "is eating", BCK_YELLOW);
	philos->die->t1 = get_time();
	ft_usleep(philos->eat->time);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
	philos->nr_eats++ ;
	return (1);
}

int process_sleeping(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
	print_status(philos, "is sleeping", BCK_CYAN);
	ft_usleep(philos->sleep->time);
	return (1);
}

int process_thinking(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
	print_status(philos, "is thinking",BCK_CYAN);
	return (1);
}

int one_philo(t_list_philo *philos)
{
	if(philos->max_philos  == 1)
	{
		pthread_mutex_lock (&philos->mutex_forks[philos->fork_left]);
		print_status(philos, "taken left fork ",BCK_GREEN);
		ft_usleep(philos->eat->time);
		philos->die->status = 1;
		print_status(philos, "is dead", BCK_RED);
		pthread_mutex_unlock (&philos->mutex_forks[philos->fork_left]);
		return (1);
	}
	return (0);
}

void *work_proc(void *var)
{
	t_list_philo *philos;
	
	philos = (t_list_philo *)var;
	while(!philos->start)
		usleep(1);
	ft_usleep (((philos->philo_nr + 1) % 2) * philos->eat->time);
	philos->die->t1 = get_time();
	if(one_philo(philos))
		return(philos);
	while(process_eating(philos) && process_sleeping(philos) && process_thinking(philos))
		if(dying_cntrol(philos) )
			break;
	pthread_mutex_unlock (&philos->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock (&philos->mutex_forks[philos->fork_rght]);
	pthread_mutex_unlock (philos->mutex_prt);
	return (philos);
}