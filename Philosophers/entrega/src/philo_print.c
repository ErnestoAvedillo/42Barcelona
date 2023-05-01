/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 08:43:12 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/18 08:43:14 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_status(t_list_philo *philos, char *origen)
{
	int j;
	static int k;

	if (!k)
		k = 2;
	else 
		k++;
	pthread_mutex_lock(philos->mutex_prt);
	printf("\033[%i;%iHOrigen print %s\n",k, 1, origen);
	k++;
	printf("\033[%i;%iH%i", k, 1, philos->philo_nr);
	j = 1;
	//	printf("\033[%i;%iH%p", philos->philo_nr + 1, j * SPACING, philos);
	//	j++;
	//	printf("\033[%i;%iH%ld", philos->philo_nr + 1, j * SPACING, philos->thrd);
	//	j++;
	printf("\033[%i;%iH%lld", k, j++ * SPACING, philos->die->status);
	printf("\033[%i;%iH%lld", k, j++ * SPACING, philos->die->t0);
	printf("\033[%i;%iH%lld", k, j++ * SPACING, get_time());
	printf("\033[%i;%iH%lld", k, j++ * SPACING, get_time()  - philos->die->t0);
	printf("\033[%i;%iH%lld", k, j++ * SPACING, philos->eat->status);
	printf("\033[%i;%iH%lld", k, j++ * SPACING, philos->sleep->status);
	printf("\033[%i;%iH%u", k, j++ * SPACING, philos->nr_eats);
	printf("\033[%i;%iH%i", k, j++ * SPACING, philos->max_philos);
	if (philos->eat->status)
	{
		printf("\033[%i;%iH%i,%i", k, j++ * SPACING, philos->fork_left, philos->arr_forks[philos->fork_left]);
		printf("\033[%i;%iH%i,%i", k, j * SPACING, philos->fork_rght, philos->arr_forks[philos->fork_rght]);
	}
	else
	{
		printf("\033[%i;%iH%i,*%i*", k, j++ * SPACING, philos->fork_left, philos->arr_forks[philos->fork_left]);
		printf("\033[%i;%iH%i,*%i*", k, j * SPACING, philos->fork_rght, philos->arr_forks[philos->fork_rght]);
	}	
	printf("\n");
	pthread_mutex_unlock(philos->mutex_prt);
}

void print_header(void)
{
	int j;

	printf("\033[1;1HPhilosofer");
	//	printf("\033[1;20HAddress");
	//	printf("\033[1;40Hthread");
	j = 1;
	printf("\033[1;%iHdie rest", j++ * SPACING);
	printf("\033[1;%iHdie passed", j++ * SPACING);
	printf("\033[1;%iHdie t0", j++ * SPACING);
	printf("\033[1;%iHget-time", j++ * SPACING);
	printf("\033[1;%iHeat", j++ * SPACING);
	printf("\033[1;%iHsleep", j++ * SPACING);
	printf("\033[1;%iHnr_eats", j++ * SPACING);
	printf("\033[1;%iHmax_phil", j++ * SPACING);
	printf("\033[1;%iHleft_fork", j++ * SPACING);
	printf("\033[1;%iHrigt_fork", j++ * SPACING);
	printf("\n");
	return;
}