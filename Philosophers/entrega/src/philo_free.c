/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:29:38 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/23 16:29:43 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	free_mutex_forks(pthread_mutex_t *mutex, int nr)
{
	int	i;

	i = 0;
	while(++i <= nr)
		pthread_mutex_destroy(&mutex[i]);
	return;
}

void	free_vars(t_list_philo *philos)
{
	t_list_philo	*aux;

	aux = NULL;
	while (philos)
	{
		if (!philos)
			return ;
		if (philos->die)
			free(philos->die);
		if (philos->eat)
			free(philos->eat);
		if (philos->sleep)
			free(philos->sleep);
		if (philos->mutex_forks)
			pthread_mutex_destroy(philos->mutex_prt);
		if (philos->mutex_prt)
			pthread_mutex_destroy(philos->mutex_prt);
		if (philos->dead)
			pthread_mutex_destroy(philos->dead);
		if (philos->next)
		{
			aux = philos->next;
			free(philos->next);
		}
		free(philos);
		philos = aux;
	}
}
