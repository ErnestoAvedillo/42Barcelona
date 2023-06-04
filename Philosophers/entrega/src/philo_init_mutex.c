/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:31:27 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/23 16:31:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

pthread_mutex_t	*fork_mutex_arr(int nr)
{
	pthread_mutex_t	*i;
	int	j;

	i = (pthread_mutex_t *)malloc(nr * sizeof(pthread_mutex_t));
	if (!i)
		return (NULL);
	j = 0;
	while (j < nr)
		pthread_mutex_init(&i[j++], NULL);
	return (i);
}

int *get_arr_forks(int nr)
{
	int	*i;
	int	j;

	i = (int *)malloc(nr * sizeof(int));
	if (!i)
		return (NULL);
	j = 0;
	while (j < nr)
		i[j++] = 0;
	return (i);
}

int init_mutex(t_philo *phi_head)
{
	phi_head->mutex_forks = fork_mutex_arr(phi_head->nr_ph);
	phi_head->mutex_prt = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phi_head->mutex_prt, NULL);
	phi_head->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phi_head->dead, NULL);
	if (!phi_head->mutex_forks || !phi_head->mutex_prt || !phi_head->dead)
		return (0);
	return (1);
}