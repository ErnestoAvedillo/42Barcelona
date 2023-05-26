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

void print_status(t_list_philo *philos, char *origen, char *COLOR)
{
	int j;
	int k;
	int col;
	col = philos->philo_nr / COL_LEN * NEXT_COL;
	k = philos->philo_nr + 1 - (philos->philo_nr / COL_LEN) * COL_LEN;
	pthread_mutex_lock(philos->mutex_prt);
	printf("\033[%i;%iH%i", k, col + 1 , philos->philo_nr);
	j = 1;
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->die->time - get_time()  + philos->die->t0);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->eat->status);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->sleep->status);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->die->status);
	printf("\033[%i;%iH%u", k, col + j++ * SPACING, philos->nr_eats);
	printf("%s\e[30m\033[%i;%iH%10s%s", COLOR, k, col + j++ * SPACING, origen, BCK_STD);
	printf("\n");
	pthread_mutex_unlock(philos->mutex_prt);
}

void print_header(void)
{
	int j;

	printf("\033[1;1HPhilo");
	//	printf("\033[1;20HAddress");
	//	printf("\033[1;40Hthread");
	j = 1;
	printf("\033[1;%iHorigen", j++ * SPACING);
	printf("\033[1;%iHtime2die", j++ * SPACING);
	//printf("\033[1;%iHdie passed", j++ * SPACING);
//	printf("\033[1;%iHdie t0", j++ * SPACING);
//	printf("\033[1;%iHget-time", j++ * SPACING);
	printf("\033[1;%iHeat", j++ * SPACING);
	printf("\033[1;%iHsleep", j++ * SPACING);
	printf("\033[1;%iHdie", j++ * SPACING);
	printf("\033[1;%iHnr_eats", j++ * SPACING);
	//printf("\033[1;%iHmax_phil", j++ * SPACING);
	printf("\033[1;%iHleft_fork", j++ * SPACING);
	printf("\033[1;%iHrigt_fork", j++ * SPACING);
	printf("\n");
	return;
}


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

int	print_msg(t_list_philo *philos, char *str)
{
	int i;
	int j;

	//write(1, "wait prio mutex lock ", 21);
	//ft_putnbr(philos->philo_nr);
	//write(1, "\n", 1);
	pthread_mutex_lock(philos->mutex_prt);
//	while (pthread_mutex_lock(philos->mutex_prt))
//		sleep(10);
	//write(1, "wait after lock ", 16);
	//ft_putnbr(philos->philo_nr);
	//write(1, "\n", 1);
	i = write(1, "Philosopher  ", 13);
	ft_putnbr(philos->philo_nr);
	i += write(1, "  ", 2);
	ft_putnbr(get_time() - philos->die->t0);
	i += write(1, "  ", 2);
	ft_putnbr(get_time());
	i += write(1, "  ", 2);
	j = 0;
	while(str[j])
		i += write(1, &str[j++], 1);
	i += write(1, "\n", 1);
	pthread_mutex_unlock(philos->mutex_prt);
	return (i);
}
