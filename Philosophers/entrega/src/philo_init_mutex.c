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

int init_mutex(t_list_philo *philos, int nr_phil)
{
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_prt;
	pthread_mutex_t	*mutex_die;
    int             *arr_forks;

	
    arr_forks = get_arr_forks(nr_phil);
	mutex_forks = fork_mutex_arr(nr_phil);
	mutex_forks = (pthread_mutex_t*) malloc (sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex_forks, NULL);
	mutex_prt = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex_prt, NULL);
	mutex_die = (pthread_mutex_t*) malloc (sizeof(pthread_mutex_t));
	pthread_mutex_init(mutex_die, NULL);
	if (!mutex_forks || !mutex_die || !mutex_prt)
		return (0);
	while(philos)
	{
        philos->arr_forks = arr_forks;
		philos->mutex_prt = mutex_prt;
		philos->mutex_forks = mutex_forks;
		philos->dead = mutex_die;
		philos = philos->next;
	}
	return (1);
}