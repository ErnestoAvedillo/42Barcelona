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

void	free_vars(t_philo *header)
{
	t_list_philo	*aux;
	t_list_philo	*philos;

	//printf("Liberando memoria\n");

	aux = NULL;
	if (!header)
		return ;
	if (header->mutex_forks)
		pthread_mutex_destroy(header->mutex_forks);
	if (header->mutex_prt)
		pthread_mutex_destroy(header->mutex_prt);
	if (header->dead)
		pthread_mutex_destroy(header->dead);
	if (header->first_philo)
		philos = header->first_philo;
	else 
		philos = NULL;
	free(header);
	while (philos)
	{
		if (!philos)
		{
			if (philos->die)
				free(philos->die);
			if (philos->eat)
				free(philos->eat);
			if (philos->sleep)
				free(philos->sleep);
			if (philos->next)
			{
				aux = philos->next;
				free(philos->next);
			}
			free(philos);
			philos = aux;
		}
		else
			return ;
	}
	//printf("Memoria liberada\n");
}
