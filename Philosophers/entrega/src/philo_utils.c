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
	philo->die = ft_atoi(ac[2]) * 1000;
	philo->eat = ft_atoi(ac[3]) * 1000;
	philo->sleep = ft_atoi(ac[4]) * 1000;
	if (av == 6)
		philo->nr_eats = ft_atoi(ac[5]);
	else
		philo->nr_eats = 0;
	return (philo);
}

long long get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void fill_data_proc (t_control_proc *data, int val)
{
	data->status = 0;
	data->finished = 0;
	data->time = val;
	data->t0 = 0;
	data->t1 = 0;
}

t_philo *start_proc(t_philo *philo)
{
	int				i;
	t_list_philo	*philos = NULL;

	printf("\033[2J");
	if (philo->nr_ph == 0)
		return (NULL);
	print_header();
	philo->first_philo = alloc_var(philo->nr_ph);
	if (!philo->first_philo)
	{
		free_vars(philo);
		return (NULL);
	}
	philos = philo->first_philo;
	i = 1;
	while (philos)
	{
		philos->philo_nr = i;
		fill_data_proc(philos->die, philo->die);
		fill_data_proc(philos->eat, philo->eat);
		fill_data_proc(philos->sleep, philo->sleep);
		philos->nr_eats = philo->nr_eats;
		philos->max_philos = philo->nr_ph;
		if (i == philo->nr_ph)
			philos->fork_left = 0;
		else
			philos->fork_left = i;
		philos->fork_rght = i - 1;
		pthread_create(&philos->thrd, NULL, &work_proc, philos);
		philos = philos->next;
		i++;
	}
	return (philo);
}

void	join_thread(t_philo *philo)
{
	t_list_philo	*philos;

	philos = philo->first_philo;
//	t_list_philo *aux;
//	free(philos->arr_forks);
//	pthread_mutex_lock(philos->mutex_prt);
//	printf("\nEntro en joinv%p\n", philos);
//	pthread_mutex_unlock(philos->mutex_prt);
	print_header();
	while (philos)
	{
		pthread_cancel(philos->thrd);
		pthread_join(philos->thrd, NULL);
//		aux = ;
//		free(philos);
//		pthread_mutex_lock(philos->mutex_prt);
//		printf("\033[%i;1Hdireccion1 %p -- %i", philos->philo_nr + 20, philos, philos->philo_nr);
//		printf("bucle status %lld --gettime %lld --t0 %lld--resta %lld \n", philos->die->status, get_time(), philos->die->t0, get_time() - philos->die->t0);
//		pthread_mutex_unlock(philos->mutex_prt);
		print_status(philos,"join");
		philos = philos->next;
	}
	printf("salgo de join\n");
}

void finish_control(t_philo *philos)
{
	t_list_philo *aux;

	aux = philos->first_philo;
	while (!aux->die->finished)
	{
		if (!aux->next)
			aux = philos->first_philo;
		else
			aux = aux->next;
	}
	printf("FINALIZADO\n");
	return;
}