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

	j = 2;
	printf("\033[%i;1HPhilos \033[%i;%iH%i", j, j, philos->philo_nr * 20, philos->philo_nr);
	j++;
	printf("\033[%i;1HAddress  \033[%i;%iH%p", j, j, philos->philo_nr * 20, philos);
	j++;
	printf("\033[%i;1Hthread  \033[%i;%iH%lu", j, j, philos->philo_nr * 20, philos->thrd);
	j++;
	printf("\033[%i;1Hdie \033[%i;%iH%u", j, j, philos->philo_nr * 20, philos->die->time);
	j++;
	printf("\033[%i;1Heat \033[%i;%iH%llu", j, j, philos->philo_nr * 20, philos->eat->t1 - philos->eat->t0);
	j++;
	printf("\033[%i;1Hsleep \033[%i;%iH%u", j, j, philos->philo_nr * 20, philos->sleep->time);
	j++;
	printf("\033[%i;1Hnr_eats \033[%i;%iH%u", j, j, philos->philo_nr * 20, philos->nr_eats);
	j++;
	printf("\033[%i;1Hmax_phil \033[%i;%iH%i", j, j, philos->philo_nr * 20, philos->max_philos);
	j++;
	printf("\033[%i;1Hleft fork \033[%i;%iH%i,%i", j, j, philos->philo_nr * 20, philos->fork_left, philos->arr_forks[philos->fork_left]);
	j++;
	printf("\033[%i;1Hright fork \033[%i;%iH%i,%i\n", j, j, philos->philo_nr * 20, philos->fork_rght, philos->arr_forks[philos->fork_rght]);
}

void print_header(int nr)
{
	int	i;

	i = 0;
	printf("Philosopher");
	while (++i <= nr)
	{
		printf("\033[1;%iH %i", i * 20, i);
	}
	printf("\n");
	return;
}