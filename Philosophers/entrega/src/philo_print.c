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
	printf("\033[%i;%iH%p", philos->philo_nr + 1, j * 20, philos);
	j++;
	printf("\033[%i;%iH%p", philos->philo_nr + 1, j * 20,philos->dead);
	j++;
	printf("\033[%i;%iH%u", philos->philo_nr + 1, j * 20, philos->die->time);
	j++;
	printf("\033[%i;%iH%llu", philos->philo_nr + 1, j * 20, philos->eat->t1 - philos->eat->t0);
	j++;
	printf("\033[%i;%iH%u", philos->philo_nr + 1, j * 20, philos->sleep->time);
	j++;
	printf("\033[%i;%iH%u", philos->philo_nr + 1, j * 20, philos->nr_eats);
	j++;
	printf("\033[%i;%iH%i", philos->philo_nr + 1, j * 20, philos->max_philos);
	j++;
	printf("\033[%i;%iH%i,%i", philos->philo_nr + 1, j * 20, philos->fork_left, philos->arr_forks[philos->fork_left]);
	j++;
	printf("\033[%i;%iH%i,%i\n", philos->philo_nr + 1, j * 20, philos->fork_rght, philos->arr_forks[philos->fork_rght]);

}

void print_header(void)
{
	int	i;

	i = 0;
	printf("\033[1;1HPhilosofer");
	printf("\033[1;20HAddress");
	printf("\033[1;40Hthread");
	printf("\033[1;60Hdie");
	printf("\033[1;80Heat");
	printf("\033[1;100Hsleep");
	printf("\033[1;120Hnr_eats");
	printf("\033[1;140Hmax_phil");
	printf("\033[1;160Hleft_fork");
	printf("\033[1;180Hrigt_fork\n");
	return;
}