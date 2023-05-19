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
	if (!philo)
		return (NULL);
	philo->nr_ph = ft_atoi(ac[1]);
	philo->die = ft_atoi(ac[2]);
	philo->eat = ft_atoi(ac[3]);
	philo->sleep = ft_atoi(ac[4]);
	if (av == 6)
		philo->nr_eats = ft_atoi(ac[5]);
	else
		philo->nr_eats = 0;
	philo->proc_finished = 0;
	philo->start = 0;
	if (!init_mutex(philo))
		return(NULL);
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
	data->time = val;
	data->t0 = 0;
	data->t1 = 0;
}

/// @brief initialize the variables and start the threads
/// @param philo 
/// @return position memory of the head philosophers
t_philo *start_proc(t_philo *philo)
{
	int				i;
	t_list_philo	*philos = NULL;

	printf("\033[2J");
	if (philo->nr_ph == 0)
		return (NULL);
	//print_header();
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
		philos->lim_eats = philo->nr_eats;
		philos->nr_eats = 0;
		philos->max_philos = philo->nr_ph;
		if (i == philo->nr_ph)
			philos->fork_left = 0;
		else
			philos->fork_left = i;
		philos->fork_rght = i - 1;
		philos->arr_forks = philo->arr_forks;
		philos->mutex_forks = philo->mutex_forks;
		philos->mutex_prt = philo->mutex_prt;
		philos->dead = philo->dead;
		philos->start = &philo->start;
		pthread_create(&philos->thrd, NULL, &work_proc, philos);
		philos = philos->next;
		i++;
	}
	philo->start = 1;
	return (philo);
}

void	join_thread(t_philo *philo)
{
	t_list_philo	*philos;

	philos = philo->first_philo;
	while (philos)
	{
		pthread_cancel(philos->thrd);
		pthread_join(philos->thrd, NULL);
	//	print_status(philos,"join");
		philos = philos->next;
	}
}

void finish_control(t_philo *philos)
{
	t_list_philo	*aux;
	int				finish;

	aux = philos->first_philo;
	while (!aux->die->status)
	{
		finish &= (aux->lim_eats > 0  && aux->lim_eats == aux->nr_eats);
		if (!aux->next)
		{
			if (finish)
			{
				break;
			}
			finish = 1;
			aux = philos->first_philo;
		}
		else 
			aux = aux->next;
	}
	if (finish)
	{
		aux = philos->first_philo;
		while(aux)
		{
			pthread_mutex_lock(aux->mutex_prt);
	//		while(pthread_mutex_lock(aux->mutex_prt))
	//			usleep(10);
				printf("Philosopher %i  has eaten %i meals.\n",aux->philo_nr, aux->nr_eats);
			pthread_mutex_unlock(aux->mutex_prt);
			aux = aux->next;
		}
	}
	aux = philos->first_philo;
	while (aux)
	{
		if (!finish)
			aux->die->status = 1;
			pthread_mutex_lock(aux->mutex_prt);
	//		while(pthread_mutex_lock(aux->mutex_prt))
	//			usleep(10);
			printf("Philosopher %i  dead %llu.\n",aux->philo_nr, get_time()- aux->die->t0);
			pthread_mutex_unlock(aux->mutex_prt);
//		print_status(aux, "exit");
		aux = aux->next;
	}
//	printf("FINALIZADO\n");
	return;
}

void ft_usleep(int nbr,t_list_philo *philos )
{
	long long int init;

	init = get_time();
	while (nbr > get_time() - init - 5 )
	{
		usleep(nbr / 4);
	}
	pthread_mutex_lock(philos->mutex_prt);
//	while(pthread_mutex_lock(philos->mutex_prt))
//		sleep(10);
	write (1, "Philosopher ", 12);
	ft_putnbr(philos->philo_nr);
	write (1, " sleep been ", 12);
	ft_putnbr(nbr);
	write (1, " > ", 3);
	ft_putnbr(get_time() - init);
	write (1, " \n", 2);


//	printf("Philosopher %i  ft_usleep %i > %llu?.--eat %lli-- sleep %lli \n",philos->philo_nr, nbr, get_time() - init, philos->eat->status, philos->sleep->status);
	pthread_mutex_unlock(philos->mutex_prt);
	
}