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
	philos->die->t1 = get_time();

	if (philos->die->t1 - philos->die->t0 >= philos->die->time)
	{
		philos->die->status = 1;
		print_msg(philos, "is dead");
		return (1);
	}
	return (0);
	
}

int process_eating(t_list_philo *philos)
{
	philos->die->t0 = get_time();
	while (!philos->eat->status)
	{
		while ((philos->arr_forks[philos->fork_left] || philos->arr_forks[philos->fork_rght]) && !philos->eat->status)
			if (dying_cntrol(philos))
				return (0);
		if (!pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]))
		{
			philos->arr_forks[philos->fork_left] = 1;
			print_msg(philos, "has taken left fork");
			if (pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]))
			{
				pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
				print_msg(philos, "has leaved left fork");
				philos->arr_forks[philos->fork_left] = 0;
			}
			else
			{
				philos->arr_forks[philos->fork_rght] = 1;
				print_msg(philos, "has taken right fork");
				philos->think = 0;
				philos->eat->status = 1;
			}
		}
		//print_status(philos, "wait");
	}
	//print_status(philos, "eat");
	print_msg(philos, "is eating");
	ft_usleep(philos->eat->time, philos);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
	philos->arr_forks[philos->fork_left] = 0;
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
	philos->arr_forks[philos->fork_rght] = 0;
	philos->eat->status = 0;
	philos->sleep->status = 1;
	philos->nr_eats++ ;
	print_msg(philos, "is control eating");
	if (dying_cntrol(philos))
		return (0);
	return (1);
}

int process_sleeping(t_list_philo *philos)
{
	if (dying_cntrol(philos))
		return (0);
	//print_status(philos, "sleep");
	print_msg(philos, "is sleeping");
	ft_usleep(philos->sleep->time, philos);
	print_msg(philos, "is control sleeping");
	philos->sleep->status = 0;
	philos->think = 1;
	//print_status(philos, "think");
	print_msg(philos, "is thinking");
	return (1);
}

void *work_proc(void *var)
{
	t_list_philo *philos;

	philos = (t_list_philo *)var;
	while(!*philos->start)
		usleep (200);
	while (!philos->die->status)
	{
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