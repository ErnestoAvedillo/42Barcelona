/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:02:00 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/10 22:02:01 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	fill_data_proc(t_list_philo *first_philo, t_philo *head)
{
	int				i;
	t_list_philo	*philos;

	philos = first_philo;
	i = 1;
	while (philos)
	{
		philos->philo_nr = i;
//		philos->die->status = 0;
//		philos->die->time = head->die;
//		philos->eat->time = head->eat;
//		philos->sleep->time = head->sleep;
//		philos->lim_eats = head->nr_eats;
		philos->nr_eats = 0;
//		philos->max_philos = head->nr_ph;
		philos->fork_rght = i;
		if (i == head->nr_ph)
			philos->fork_rght = 0;
		philos->fork_left = i - 1;
		philos->header = head;
//		philos->mutex_forks = head->mutex_forks;
//		philos->mutex_prt = head->mutex_prt;
//		philos->dead = head->dead;
//		philos->start = &head->start;
		philos->istart = 0;
//		philos->t0 = &head->t0;
//		philos->isdead = &head->isdead;
		pthread_create(&philos->thrd, NULL, &work_proc, philos);
		philos = philos->next;
		i++;
	}
}

/// @brief initialize the variables and start the threads
/// @param philo 
/// @return position memory of the head philosophers
t_list_philo *start_proc(t_philo *head)
{
	t_list_philo *first_philo;

	printf("\033[2J");
	if (head->nr_ph == 0)
		return (NULL);
	first_philo = alloc_var(head->nr_ph);
	if (!first_philo)
	{
		free_vars(first_philo);
		return (NULL);
	}
	fill_data_proc(first_philo, head);
	head->start = 1;
	return (first_philo);
}

void	join_thread(t_list_philo *first_philo)
{
	t_list_philo *philos;

	philos = first_philo;
	while (philos)
	{
		pthread_join(philos->thrd, NULL);
		philos = philos->next;
	}
	return ;
}

void	finish_control(t_list_philo *first_philo)
{
	t_list_philo	*aux;
	int				finish;

	aux = first_philo;
	while (!aux->header->isdead)
	{
		finish &= (aux->header->lim_eats > 0 && aux->header->lim_eats == aux->nr_eats);
		if (!aux->next)
		{
			if (finish)
				break ;
			finish = 1;
			aux = first_philo;
		}
		else
			aux = aux->next;
	}
	print_meals_eaten(first_philo);
	return ;
}
