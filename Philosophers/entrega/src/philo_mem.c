/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_mem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:38:06 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/18 08:38:10 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"



int	check_mem(t_list_philo *ph)
{
	if (!ph->mutex_forks || !ph->die || !ph->eat \
		|| !ph->sleep )
		return (0);
	return (1);
}

int	set_mem(t_list_philo *philos)
{
	philos->die = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->eat = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->sleep = (t_control_proc *)malloc(sizeof(t_control_proc));
/*	philos->mutex_forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->mutex_prt = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	philos->next = (void *)malloc(sizeof(void));
*/	if (!check_mem(philos))
		return (0);
	return (1);
}

t_list_philo	*create_lst_philos(int nr_phil)
{
	t_list_philo	*philos;
	t_list_philo	*aux;
	t_list_philo	*frst_phil;
	int				i;

	i = 0;
	philos = (t_list_philo *)malloc(sizeof(t_list_philo));
	frst_phil = philos;
	aux = NULL;
	while (++i <= nr_phil)
	{
		if (i != 1)
			philos = (t_list_philo *)malloc(sizeof(t_list_philo));
		if (!philos || !set_mem(philos))
			return (NULL);
		if (i != 1)
			aux->next = philos;
		philos->philo_nr = i;
		philos->next = NULL;
//		philos->think = 1;
		aux = philos;
	}
	return (frst_phil);
}



t_list_philo	*alloc_var(int nr_phil)
{
	t_list_philo	*frst_phil;

	frst_phil = create_lst_philos(nr_phil);
	if (!frst_phil)
		return (NULL);
/*	if (!init_mutex(frst_phil,nr_phil))
	{
		return (NULL);
	}
*/
	return (frst_phil);
}
