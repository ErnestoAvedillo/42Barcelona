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

void *work_proc(void *var)
{
	t_list_philo *philos;

	philos = (t_list_philo *)var;
	while (philos->die->status >= 0)
	{
		if (!philos->eat->status)
		{
			pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]);
			pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]);
			philos->arr_forks[philos->fork_left] = 1;
			philos->arr_forks[philos->fork_rght] = 1;
			philos->eat->t0 = get_time();
			philos->eat->t0 = philos->eat->t0;
			philos->eat->status = philos->eat->time;
			philos->die->status = philos->die->time;
		}
		philos->eat->status = get_time() - philos->eat->t0;
		philos->die->status = get_time() - philos->die->t0;
		if (philos->eat->status <= 0)
		{
			pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
			pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
			philos->arr_forks[philos->fork_left] = 0;
			philos->arr_forks[philos->fork_rght] = 0;
			philos->eat->status = 0;
			philos->sleep->t0 = get_time();
			philos->sleep->status = philos->sleep->time;
			
		while(philos->eat->status >= 0)
		{
			philos->sleep->status = get_time() - philos->sleep->t0;
			philos->die->status = get_time() - philos->die->t0;
		}
		philos->sleep->status = 0;

		pthread_mutex_lock(philos->mutex_prt);
		print_status(philos);
		pthread_mutex_unlock(philos->mutex_prt);
//		printf("\033[%i;1Hdireccion1 %p -- %i", philos->philo_nr + 12, philos, philos->philo_nr);
//		printf("impreso %i\n", philos->philo_nr);
		philos->die->status = get_time() - philos->die->t0;
	}
	return (philos);
}
