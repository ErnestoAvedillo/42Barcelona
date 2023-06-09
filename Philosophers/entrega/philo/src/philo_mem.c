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
	if (!ph->header->mutex_forks || !ph->header->die || !ph->header->eat || \
			!ph->header->sleep)
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
		if (!philos)
			return (NULL);
		if (i != 1)
			aux->next = philos;
		philos->philo_nr = i;
		philos->next = NULL;
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
	return (frst_phil);
}
