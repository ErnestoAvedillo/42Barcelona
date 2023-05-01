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
	philos->die->status = get_time() - philos->die->t0;
//	print_status(philos, "dying control");

	if (philos->die->status >= philos->die->time)
	{
		philos->die->finished = 1;
//		print_status(philos, "dying control");
		return (1);
	}
	return (0);
	
}

int process_eating(t_list_philo *philos)
{
	philos->die->t0 = get_time();
	philos->die->status = philos->die->time;
//	print_status(philos,"inicio bucle eat");
	while (philos->arr_forks[philos->fork_left] || philos->arr_forks[philos->fork_rght] || philos->eat->status || philos->sleep->status)
	{
//	printf("\033[%i;1Hwaiting control1 %p -- %i -->fork l %i -fork r %i --eat %llu --sleep %llu", philos->philo_nr + 12, philos, philos->philo_nr, philos->arr_forks[philos->fork_left], philos->arr_forks[philos->fork_rght], philos->eat->status, philos->sleep->status);
		if (dying_cntrol(philos))
		{
//			printf("Salgo sin entrar");
			return (0);
		}
	}
//	print_status(philos,"fin bucle eat");
	philos->eat->status = 1;
	pthread_mutex_lock(philos->mutex_forks);
	philos->arr_forks[philos->fork_left] = 1;
	pthread_mutex_unlock(philos->mutex_forks);
	pthread_mutex_lock(philos->mutex_forks);
	philos->arr_forks[philos->fork_rght] = 1;
	pthread_mutex_unlock(philos->mutex_forks);
	print_status(philos, "start eating");
	usleep(philos->eat->time);
	pthread_mutex_lock(philos->mutex_forks);
	philos->arr_forks[philos->fork_left] = 0;
	philos->arr_forks[philos->fork_rght] = 0;
	pthread_mutex_unlock(philos->mutex_forks);
	philos->sleep->status = 1;
	philos->eat->status = 0;
	philos->nr_eats++ ;
//	print_status(philos,"finish eating");
	if (dying_cntrol(philos))
	{
//			printf("Salgo sin en el primer if");
		return (0);
	}
	return (1);
}

int process_sleeping(t_list_philo *philos)
{
//	print_status(philos, "start sleeping");
	usleep(philos->sleep->time);
	philos->sleep->status = 0;
	if (dying_cntrol(philos))
	{
//			printf("Salgo en sleeping");
		return (0);
	}
//	print_status(philos, "finish sleeping");
	return (1);
}

void *work_proc(void *var)
{
	t_list_philo *philos;

	philos = (t_list_philo *)var;
	while (!philos->die->finished)
	{
		if (!process_eating(philos))
			return (philos);
		if (!process_sleeping(philos))
			return (philos);
//		print_status(philos, "dead function");
//		printf("\033[%i;1Hdireccion1 %p -- %i", philos->philo_nr + 12, philos, philos->philo_nr);
//		printf("impreso status %lld --gettime %lld --t0 %lld--resta %lld \n", philos->die->status, get_time(), philos->die->t0, get_time() - philos->die->t0);
	//	getchar();
	}
	return (philos);
}