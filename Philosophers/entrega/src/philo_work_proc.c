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
	//int k;
	//int col;

	//col = philos->philo_nr / COL_LEN * NEXT_COL;
	//k = philos->philo_nr + 1 - (philos->philo_nr / COL_LEN) * COL_LEN;
	philos->die->t1 = get_time();
	//	print_status(philos, "dying control");
	//rintf("\033[%i;%iH%s%6s%s", k, col, BCK_YELLOW, "paso", BCK_STD);

	if (philos->die->t1 - philos->die->t0 >= philos->die->time)
	{
		philos->die->status = 1;
		return (1);
	}
	return (0);
	
}

int process_eating(t_list_philo *philos)
{
	philos->die->t0 = get_time();
	//			print_status(philos, "in eat");
	//	philos->die->status = philos->die->time;
	//	print_status(philos,"inicio bucle eat");
	// while (philos->arr_forks[philos->fork_left] || philos->arr_forks[philos->fork_rght] || philos->think->status )
	while (!philos->eat->status)
	{
	//getchar();
	//			print_status(philos, "in buc");

		while ((philos->arr_forks[philos->fork_left] || philos->arr_forks[philos->fork_rght]) && !philos->eat->status)
			if (dying_cntrol(philos))
				return (0);
		print_status(philos, "in boc");
		if (!pthread_mutex_lock(&philos->mutex_forks[philos->fork_left]))
		{
			philos->arr_forks[philos->fork_left] = 1;
			if (pthread_mutex_lock(&philos->mutex_forks[philos->fork_rght]))
			{
				pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
				philos->arr_forks[philos->fork_left] = 0;
			}
			else
			{
				philos->arr_forks[philos->fork_rght] = 1;
				philos->think = 0;
				philos->eat->status = 1;
			}
		}
		print_status(philos, "wait");
	}
//	print_status(philos,"fin bucle eat");
	print_status(philos, "eat");
	usleep(philos->eat->time*1000);
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_left]);
	philos->arr_forks[philos->fork_left] = 0;
	pthread_mutex_unlock(&philos->mutex_forks[philos->fork_rght]);
	philos->arr_forks[philos->fork_rght] = 0;
	philos->eat->status = 0;
	philos->sleep->status = 1;
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
	print_status(philos, "sleep");
	usleep(philos->sleep->time*1000);
	philos->sleep->status = 0;
	if (dying_cntrol(philos))
		return (0);
	philos->think = 1;
	print_status(philos, "think");
	return (1);
}

void *work_proc(void *var)
{
	t_list_philo *philos;

	philos = (t_list_philo *)var;

	while (!philos->die->status)
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