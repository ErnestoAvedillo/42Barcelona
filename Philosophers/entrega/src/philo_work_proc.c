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
	if (get_time() - philos->die->t0 >= philos->die->time || philos->die->status)
	{
		philos->die->status = 1;
		#ifdef MANDAT
		print_msg(philos, "is dead");
		#endif
		return (1);
	}
	return (0);
	
}

int process_eating(t_list_philo *philos)
{
	pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]);
	#ifdef MANDAT
	print_msg(philos, "has taken left fork");
	#elif VISIO
	print_status(philos, "LFT_F",BCK_GREEN);
	#endif
	pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]);
	#ifdef MANDAT
	print_msg(philos, "has taken right fork");
	#endif
	if (dying_cntrol(philos))
		return (0);
	philos->die->t0 = get_time();
	philos->think = 0;
	philos->eat->status = 1;
	#ifdef MANDAT
	print_msg(philos, "is eating");
	#elif VISIO
	print_status(philos, "eat", BCK_RED);
	#endif
	ft_usleep(philos->eat->time, philos);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
	philos->eat->status = 0;
	philos->nr_eats++ ;
	return (1);
}

int process_sleeping(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
	philos->sleep->status = 1;
	#ifdef MANDAT
	print_msg(philos, "is sleeping");
	#elif VISIO
	print_status(philos, "sleep", BCK_MGENTA);
	#endif
	ft_usleep(philos->sleep->time, philos);
	philos->sleep->status = 0;
	return (1);
}

void *work_proc(void *var)
{
	t_list_philo *philos;
	
	philos = (t_list_philo *)var;
	#ifdef CONTROL
	printf("philo0 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
	while(!*philos->start)
	{
		usleep (10);
	#ifdef CONTROL
	printf("philo00 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
	}
	while (!philos->die->status && philos->istart)
	{
		#ifdef VISIO
		print_status(philos, "start", BCK_GREEN);
		#endif

		if (!process_eating(philos))
			return (philos);
		if (!process_sleeping(philos))
			return (philos);
		philos->think = 1;
		#ifdef VISIO
		print_status(philos, "think",BCK_BLACK);
		#elif MANDAT
		print_msg(philos, "is thinking");
		#endif
		if(philos->lim_eats && philos->lim_eats == philos->nr_eats )
		{
			break;
		}
	}
	print_msg(philos, "is dead");
	return (philos);
}