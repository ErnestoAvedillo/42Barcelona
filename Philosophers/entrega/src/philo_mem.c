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

void free_vars(t_list_philo *philos)
{
	t_list_philo *aux;

	while (philos)
	{
		if(philos->die)
			free(philos->die);
		if (philos->eat)
			free(philos->eat);
		if (philos->sleep)
			free(philos->sleep);
		if (philos->arr_forks)
			free(philos->arr_forks);
		if (philos->next)
		{
			aux = philos->next;
			free(philos->next);
		}
		else
			aux = NULL;
		free(philos);
		philos = aux;
	}
}

static int	*fork_arr(int nr)
{
	int *i;
	int j;
	i = (int *)malloc(nr * sizeof(int));
	if (!i)
		return (NULL);
	j = 0;
	while (j < nr)
		i[j++] = 0;
	return (i);
}

int check_mem(t_list_philo *ph)
{
	if (!ph->arr_forks || !ph->die | !ph->eat \
		|| !ph->sleep || !ph->next)
		return (0);
	return (1);
}

int set_mem (t_list_philo * philos)
{
	philos->die = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->eat = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->sleep = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->arr_forks = (int *)malloc(sizeof(int));
	philos->next = (void *)malloc(sizeof(void));
	if(!check_mem(philos))
		return (0);
	return (1);
}

t_list_philo	*alloc_var(int nr_phil)
{
	t_list_philo	*philos;
	t_list_philo	*aux;
	t_list_philo	*frst_phil;
	int				i;
	int				*arr_forks;

	aux = NULL;
	frst_phil = NULL;
	arr_forks = fork_arr(nr_phil);
	if (!arr_forks)
		retrun(NULL);
	i = 0;
	while (++i <= nr_phil)
	{
		philos = (t_list_philo *)malloc(sizeof(t_list_philo));
		if (i == 1)
		{
			if (!philos)
				return (NULL);
			frst_phil = philos;
		}
		if (!philos || !set_mem(philos))
		{
			free_vars(frst_phil);
			return(NULL);
		}
		philos->arr_forks = arr_forks;
		if (i != 1)
			aux->next = philos;
		aux = philos;
	}
	return (frst_phil);
}
