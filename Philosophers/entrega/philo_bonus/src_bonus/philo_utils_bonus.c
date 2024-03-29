/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:02:00 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/10 22:02:01 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

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
		philos->header = head;
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
	printf("\033[1;1H\n");
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
	pthread_create(&head->thrd_ctrl, NULL, &dying_cntrol, first_philo);
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
	pthread_join(first_philo->header->thrd_ctrl, NULL);
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
			aux->header->lim_eats <= aux->nr_eats);
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
