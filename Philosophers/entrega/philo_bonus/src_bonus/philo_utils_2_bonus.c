/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 13:04:51 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/18 13:04:55 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

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
	aux = first_philo;
	while (!aux->header->isdead)
	{
		if (get_time() - aux->die_t1 >= aux->header->die)
		{
			sem_wait(aux->header->dead);
			print_status(aux, "is dead", BCK_RED);
			aux->header->isdead = 1;
		}
		print_meals_eated(aux);
		if (!aux->next)
			aux = first_philo;
		else
			aux = aux->next;
	}
	return (first_philo);
}
