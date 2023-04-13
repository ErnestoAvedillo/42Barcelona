/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:02:00 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/10 22:02:01 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_philo	*get_params(int av, char **ac)
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->nr_ph = ft_atoi(ac[1]);
	philo->die = ft_atoi(ac[2]);
	philo->eat = ft_atoi(ac[3]);
	philo->sleep = ft_atoi(ac[4]);
	if (av == 6)
		philo->nr_eats = ft_atoi(ac[5]);
	return (philo);
}

void *work_proc(void *var)
{
	t_list_philo *philos;
	
	philos = (t_list_philo *)var;
	printf("adress Philo  %p\n", philos);
	printf("parameters cur philos  %lu\n", philos->thrd);
	printf("parameters die %u\n", philos->die);
	printf("parameters eat %u\n", philos->eat);
	printf("parameters eat %u\n", philos->sleep);
	printf("parameters nr_eats %u\n", philos->nr_eats);
	printf("parameters max_phil %i\n", philos->max_philos);
	printf("parameters left fork %i,\n", philos->fork_left);
	printf("parameters right fork %i,\n\n", philos->fork_rght);
	return (philos);
}

t_list_philo *start_proc(t_philo *philo)
{
	int				i;
	t_list_philo	*philos = NULL;
	t_list_philo	*frst_philo = NULL;
	t_list_philo	*aux = NULL;

	i = 0;
	if (philo->nr_ph == 0)
		return (NULL);
	while (++i <= philo->nr_ph)
	{
		philos = (t_list_philo *)malloc(sizeof(t_list_philo));
		if (i == 1)
		{
			frst_philo = philos;
			philos->arr_forks = (int *)malloc(philo->nr_ph * sizeof(int));
		}
		else
		{
			aux->next = philos;
			philos->arr_forks = aux->arr_forks;
		}
		philos->die = philo->die;
		philos->eat = philo->eat;
		philos->sleep = philo->sleep;
		philos->nr_eats = philo->nr_eats;
		philos->max_philos = philo->nr_ph;
		if (i == philo->nr_ph)
			philos->fork_left = 0;
		else
			philos->fork_left = i;
		philos->fork_rght = i - 1;
		philos->next = NULL;
		pthread_create(&philos->thrd, NULL, &work_proc, philos);
		aux = philos;
	}
	return (frst_philo);
}

void	join_thread(t_list_philo *philos)
{
	t_list_philo *aux;
	free(philos->arr_forks);
	while (philos)
	{
		printf("paso1 %p\n", philos);
		pthread_join(philos->thrd, NULL);
		aux = philos->next;
		free(philos);
		philos = aux;
	}
	printf("paso\n");
}