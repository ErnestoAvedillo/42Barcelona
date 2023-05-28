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
#include "colors.h"

#ifdef VISIO
int print_status(t_list_philo *philos, char *origen, char *COLOR)
{
	int j;
	int k;
	int col;
	col = philos->philo_nr / COL_LEN * NEXT_COL + philos->philo_nr / COL_LEN * NEW_BLOCK;
	k = philos->philo_nr + 1 - (philos->philo_nr / COL_LEN) * COL_LEN;
	pthread_mutex_lock(philos->mutex_prt);
	printf("\033[%i;%iH%i", k, col + 1 , philos->philo_nr);
	j = 1;
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, get_time() - philos->die->t0);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, get_time() - philos->die->t1);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->eat->status);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->sleep->status);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->die->status);
	printf("\033[%i;%iH%u", k, col + j++ * SPACING, philos->nr_eats);
	printf("%s\e[30m\033[%i;%iH%20s%s", COLOR, k, col + j++ * SPACING, origen, BCK_STD);
	printf("\n");
	pthread_mutex_unlock(philos->mutex_prt);
	return (0);
}

void print_header(void)
{
	int j;

	printf("\033[1;1HPhilo");
	j = 1;
	printf("\033[1;%iHorigen", j++ * SPACING);
	printf("\033[1;%iHtime2die", j++ * SPACING);
	printf("\033[1;%iHeat", j++ * SPACING);
	printf("\033[1;%iHsleep", j++ * SPACING);
	printf("\033[1;%iHdie", j++ * SPACING);
	printf("\033[1;%iHnr_eats", j++ * SPACING);
	printf("\033[1;%iHleft_fork", j++ * SPACING);
	printf("\033[1;%iHrigt_fork", j++ * SPACING);
	printf("\n");
	return;
}

#elif MANDAT
int	ft_putnbr (long long int nbr)
{
	char c;
	int i;

	i = 0;
	if (nbr > 10)
		i += ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	i += write(1, &c, 1);
	return (i);
}

int	print_status(t_list_philo *philos, char *origen, char *color)
{
//	int i;
//	int j;

	pthread_mutex_lock(philos->mutex_prt);
	printf ("Philosopher %i at %lld %s %s %s forks %p -- %p\n", philos->philo_nr, get_time() - philos->die->t0, color, origen, BCK_STD, &philos->mutex_forks[philos->fork_left], &philos->mutex_forks[philos->fork_rght]);
/*	i = write (1, color, 7);
	i = write(1, , 13);
	ft_putnbr(philos->philo_nr);
	i += write(1, "  ", 2);
	ft_putnbr(get_time() - philos->die->t0);
	i += write(1, "  ", 2);
	j = 0;
	while(origen[j])
		i += write(1, &origen[j++], 1);
	i += write(1, BCK_STD, 4);
	i += write(1, "\n", 1);
*/	pthread_mutex_unlock(philos->mutex_prt);
	return (0);
}
#endif