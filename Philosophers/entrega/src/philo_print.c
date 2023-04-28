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

void print_status(t_list_philo *philos)
{
	int j;
	printf("\033[%i;%iH%i", philos->philo_nr + 1, 1, philos->philo_nr);
	j = 1;
	//	printf("\033[%i;%iH%p", philos->philo_nr + 1, j * SPACING, philos);
	//	j++;
	//	printf("\033[%i;%iH%ld", philos->philo_nr + 1, j * SPACING, philos->thrd);
	//	j++;
	printf("\033[%i;%iH%lld", philos->philo_nr + 1, j * SPACING, philos->die->status);
	j++;
	printf("\033[%i;%iH%lld", philos->philo_nr + 1, j * SPACING, philos->eat->status);
	j++;
	printf("\033[%i;%iH%lld", philos->philo_nr + 1, j * SPACING, philos->sleep->status);
	j++;
	printf("\033[%i;%iH%u", philos->philo_nr + 1, j * SPACING, philos->nr_eats);
	j++;
	printf("\033[%i;%iH%i", philos->philo_nr + 1, j * SPACING, philos->max_philos);
	j++;
	printf("\033[%i;%iH%i,%i", philos->philo_nr + 1, j * SPACING, philos->fork_left, philos->arr_forks[philos->fork_left]);
	j++;
	printf("\033[%i;%iH%i,%i\n", philos->philo_nr + 1, j * SPACING, philos->fork_rght, philos->arr_forks[philos->fork_rght]);
}

void print_header(void)
{
	int j;

	printf("\033[1;1HPhilosofer");
	//	printf("\033[1;20HAddress");
	//	printf("\033[1;40Hthread");
	j = 1;
	printf("\033[1;%iHdie", j++ * SPACING);
	printf("\033[1;%iHeat", j++ * SPACING);
	printf("\033[1;%iHsleep", j++ * SPACING);
	printf("\033[1;%iHnr_eats", j++ * SPACING);
	printf("\033[1;%iHmax_phil", j++ * SPACING);
	printf("\033[1;%iHleft_fork", j++ * SPACING);
	printf("\033[1;%iHrigt_fork\n", j++ * SPACING);
	return;
}