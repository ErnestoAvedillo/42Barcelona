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

	i = -1;
	while (++i <= nr - 1)
		pthread_mutex_destroy(&mutex[i]);
	return ;
}

void	free_philos(t_list_philo *philos)
{
	t_list_philo	*aux;

	while (philos)
	{
		if (philos->next)
		{
			aux = philos->next;
			free(philos);
			philos = aux;
		}
		else
			return ;
	}
}

void	free_vars(t_list_philo *first_philo)
{
	if (!first_philo)
		return ;
	if (first_philo->header->mutex_forks)
		free_mutex_forks(first_philo->header->mutex_forks, \
				first_philo->header->nr_ph);
	if (first_philo->header->mutex_prt)
		pthread_mutex_destroy(first_philo->header->mutex_prt);
	if (first_philo->header->dead)
		pthread_mutex_destroy(first_philo->header->dead);
	if (first_philo->header)
		free(first_philo->header);
	free_philos(first_philo);
}
