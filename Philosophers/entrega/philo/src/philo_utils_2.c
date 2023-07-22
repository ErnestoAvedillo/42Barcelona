/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 12:21:46 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/18 12:21:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	print_meals_eated(t_list_philo *aux)
{
	if (aux->header->lim_eats && aux->header->lim_eats == aux->nr_eats && \
		!aux->prt_meals_eated)
	{
		print_status(aux, "meals eaten", BCK_MGENTA);
		aux->prt_meals_eated = 1;
	}
}

void	*dying_cntrol(void *var)
{
	t_list_philo	*first_philo;
	t_list_philo	*aux;

	first_philo = (t_list_philo *)var;
	while (!first_philo->header->start)
		usleep(1);
	aux = first_philo;
	while (!aux->header->isdead)
	{
		print_meals_eated(aux);
		if (get_time() - aux->die_t1 >= aux->header->die)
		{
			pthread_mutex_lock(aux->header->dead);
			print_status(aux, "is dead", BCK_RED);
			aux->header->isdead = 1;
		}
		if (!aux->next)
			aux = first_philo;
		else
			aux = aux->next;
	}
	return (first_philo);
}
