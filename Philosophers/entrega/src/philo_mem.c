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

void	free_vars(t_list_philo *philos)
{
	t_list_philo	*aux;

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
		if (philos->arr_forks)
			free(philos->arr_forks);
		if (philos->mutex)
			free(philos->mutex);
		if (philos->next)
		{
			aux = philos->next;
			free(philos->next);
		}
		free(philos);
		philos = aux;
	}
}

static int	*fork_arr(int nr)
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

int	check_mem(t_list_philo *ph)
{
	if (!ph->arr_forks || !ph->die | !ph->eat \
		|| !ph->sleep || !ph->next)
		return (0);
	return (1);
}

int	set_mem(t_list_philo *philos)
{
	philos->die = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->eat = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->sleep = (t_control_proc *)malloc(sizeof(t_control_proc));
	philos->arr_forks = (int *)malloc(sizeof(int));
	philos->next = (void *)malloc(sizeof(void));
	if (!check_mem(philos))
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
	while (++i <= nr_phil)
	{
		philos = (t_list_philo *)malloc(sizeof(t_list_philo));
		if (i == 1)
			frst_phil = philos;
		if (!philos || !set_mem(philos))
		{
			free_vars(frst_phil);
			return (NULL);
		}
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
	t_list_philo	*aux;
	t_list_philo	*frst_phil;
	int				*arr_forks;
	pthread_mutex_t	*mutex;

	aux = NULL;
	arr_forks = fork_arr(nr_phil);
	mutex = (pthread_mutex_t *) malloc(sizeof(pthread_mutex_t));
	if (!arr_forks)
		return (NULL);
	frst_phil = create_lst_philos(nr_phil);
	aux = frst_phil;
	while (aux)
	{
		aux->mutex = mutex;
		aux->arr_forks = arr_forks;
		aux = aux->next;
	}
	return (frst_phil);
}
