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
	philo->isdead = 0;
	philo->t0 = get_time();
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
//	data->t0 = 0;
	data->t1 = 0;
}

/// @brief initialize the variables and start the threads
/// @param philo 
/// @return position memory of the head philosophers
t_philo *start_proc(t_philo *head)
{
	int				i;
	t_list_philo	*philos = NULL;

	#ifdef VISIO
		printf("\033[2J");
	#endif
	if (head->nr_ph == 0)
		return (NULL);
	head->first_philo = alloc_var(head->nr_ph);
	if (!head->first_philo)
	{
		free_vars(head);
		return (NULL);
	}
	philos = head->first_philo;
	i = 1;
	while (philos)
	{
		philos->philo_nr = i;
		fill_data_proc(philos->die, head->die);
		fill_data_proc(philos->eat, head->eat);
		fill_data_proc(philos->sleep, head->sleep);
		philos->lim_eats = head->nr_eats;
		philos->nr_eats = 0;
		philos->max_philos = head->nr_ph;
		if (i == head->nr_ph)
			philos->fork_rght = 0;
		else
			philos->fork_rght = i;
		philos->fork_left = i - 1;
		philos->mutex_forks = head->mutex_forks;
		philos->mutex_prt = head->mutex_prt;
		philos->dead = head->dead;
		philos->start = &head->start;
		philos->istart = 0;
		philos->t0 = &head->t0;
		philos->isdead = &head->isdead;
		pthread_create(&philos->thrd, NULL, &work_proc, philos);
		philos = philos->next;
		i++;
	}

	head->start = 1;
	return (head);
}

void	join_thread(t_philo *philo)
{
	t_list_philo	*philos;
	
	philos = philo->first_philo;
	while (philos)
	{
		pthread_join(philos->thrd, NULL);
		philos = philos->next;
	}
	return;
}

void print_meals_eaten(t_philo *header)
{
	t_list_philo	*aux;

	if (header->nr_eats)
	{
		aux = header->first_philo;
		while(aux)
		{
			#ifdef MANDAT
			pthread_mutex_lock(aux->mutex_prt);
			printf("Philosopher %i  has eaten %i meals.\n",aux->philo_nr, aux->nr_eats);
			pthread_mutex_unlock(aux->mutex_prt);
			#endif
			aux = aux->next;
		}
	}
}

void finish_control(t_philo *header)
{
	t_list_philo	*aux;
	int				finish;

	aux = header->first_philo;
	while (!header->isdead)
	{
		finish &= (aux->lim_eats > 0  && aux->lim_eats == aux->nr_eats);
		if (!aux->next)
		{
			if (finish)
				break;
			finish = 1;
			aux = header->first_philo;
		}
		else 
			aux = aux->next;
	}
	print_meals_eaten(header);
	return;
}


void ft_usleep(int nbr )
{
	long long int init;

	init = get_time();
	while (nbr > get_time() - init)
	{
		usleep(nbr / 2);
	}
}