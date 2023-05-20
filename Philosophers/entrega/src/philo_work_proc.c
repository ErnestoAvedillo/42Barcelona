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
	#ifdef CONTROL
	printf("philo1 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
	while (!philos->eat->status)
	{
	#ifdef CONTROL
	printf("philo2 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
		while ((philos->arr_forks[philos->fork_left] || philos->arr_forks[philos->fork_rght]))
		{
		if (dying_cntrol(philos))
				return (0);
		}
		if(!pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]))
		{
	#ifdef CONTROL
	printf("philo3 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
			philos->arr_forks[philos->fork_left] = 1;
			#ifdef MANDAT
			print_msg(philos, "has taken left fork");
			#endif
			if(!pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]))
			{
	#ifdef CONTROL
	printf("philo4 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
				philos->arr_forks[philos->fork_rght] = 1;
				#ifdef MANDAT
				print_msg(philos, "has taken right fork");
				#endif
				philos->think = 0;
				philos->eat->status = 1;
			}
			else
			{
	#ifdef CONTROL
	printf("philo5 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
				pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
				#ifdef MANDAT
				print_msg(philos, "has released left fork");
				#endif

			}
		}
		#ifdef VISIO
		print_status(philos, "wait");
		#endif
	#ifdef CONTROL
	printf("philo6 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
	}
	#ifdef CONTROL
	printf("philo7 %i -- %p -- %i \n", philos->philo_nr, philos->start, *philos->start);
	#endif
	#ifdef VISIO
	print_status(philos, "eat");
	#endif
	philos->die->t0 = get_time();
	if (dying_cntrol(philos))
		return (0);
	#ifdef MANDAT
	print_msg(philos, "is eating");
	#endif
	ft_usleep(philos->eat->time, philos);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
	philos->arr_forks[philos->fork_left] = 0;
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
	philos->arr_forks[philos->fork_rght] = 0;
	philos->eat->status = 0;
	philos->sleep->status = 1;
	philos->nr_eats++ ;
	#ifdef MANDAT
	print_msg(philos, "is control eating");
	#endif
	return (1);
}

int process_sleeping(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
	#ifdef VISIO
	print_status(philos, "sleep");
	#endif
	#ifdef MANDAT
	print_msg(philos, "is sleeping");
	#endif
	ft_usleep(philos->sleep->time, philos);
	#ifdef MANDAT
	print_msg(philos, "is control sleeping");
	#endif
	philos->sleep->status = 0;
	philos->think = 1;
	#ifdef VISIO
	print_status(philos, "think");
	#endif
	if (dying_cntrol(philos))
		return (0);
	#ifdef MANDAT
	print_msg(philos, "is thinking");
	#endif
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
	while (!philos->die->status)
	{
		#ifdef VISIO
		print_status(philos, "start");
		#endif

		if (!process_eating(philos))
			return (philos);
		if (!process_sleeping(philos))
			return (philos);
		if(philos->lim_eats && philos->lim_eats == philos->nr_eats )
		{
			break;
		}
	}
	return (philos);
}