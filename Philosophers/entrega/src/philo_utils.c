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

int	dying_cntrol(t_list_philo *philos)
{
	if (get_time() - philos->die_t1 >= philos->header->die)
	{
		pthread_mutex_lock(philos->header->dead);
		if (!philos->header->isdead)
			philos->header->isdead = 1;
		else
			return (1);
		print_status(philos, "is dead", BCK_RED);
		return (1);
	}
	else if (philos->header->isdead)
		return (1);
	if (philos->header->lim_eats && philos->header->lim_eats == philos->nr_eats)
		print_status(philos, "meals eaten", BCK_RED);
	return (0);
}

void	fill_data_proc(t_list_philo *first_philo, t_philo *head)
{
	int				i;
	t_list_philo	*philos;

	philos = first_philo;
	i = 1;
	while (philos)
	{
		philos->philo_nr = i;
		philos->nr_eats = 0;
		philos->fork_rght = i;
		if (i == head->nr_ph)
			philos->fork_rght = 0;
		philos->fork_left = i - 1;
		philos->header = head;
		philos->istart = 0;
		pthread_create(&philos->thrd, NULL, &work_proc, philos);
		philos = philos->next;
		i++;
	}
}

/// @brief initialize the variables and start the threads
/// @param philo 
/// @return position memory of the head philosophers
t_list_philo	*start_proc(t_philo *head)
{
	t_list_philo	*first_philo;

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
	t_list_philo	*philos;

	philos = first_philo;
	while (philos)
	{
		while (pthread_join(philos->thrd, NULL) != 0)
			usleep(1);
		philos = philos->next;
	}
	return ;
}

void	finish_control(t_list_philo *first_philo)
{
	t_list_philo	*aux;
	int				finish;

	finish = 1;
	aux = first_philo;
	while (!aux->header->isdead)
	{
		finish &= (aux->header->lim_eats > 0 && \
			aux->header->lim_eats == aux->nr_eats);
		if (!aux->next)
		{
			if (finish)
			{
				aux->header->isdead = 1;
				break ;
			}
			finish = 1;
			aux = first_philo;
		}
		else
			aux = aux->next;
	}
	return ;
}
