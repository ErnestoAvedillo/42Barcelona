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

void print_status(t_list_philo *philos, char *origen)
{
	int j;
//	static int k;
	int k;
	int col;
//	if (!k)
//		k = 2;
//	else 
//		k++;
	col = philos->philo_nr / COL_LEN * NEXT_COL;
	k = philos->philo_nr + 1 - (philos->philo_nr / COL_LEN) * COL_LEN;
	while (pthread_mutex_lock(philos->mutex_prt))
		usleep(10);
//	printf("\033[%i;%iHOrigen print %s\n",k, 1, origen);
//	k++;
	printf("\033[%i;%iH%i", k, col + 1 , philos->philo_nr);
	j = 1;
	//	printf("\033[%i;%iH%p", philos->philo_nr + 1, j * SPACING, philos);
	//	j++;
	//	printf("\033[%i;%iH%ld", philos->philo_nr + 1, j * SPACING, philos->thrd);
	//	j++;

	printf("\033[%i;%iH%6s", k, col + j++ * SPACING, origen);
//	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->die->status);
//	printf("\033[%i;%iH%lld", k, j++ * SPACING, philos->die->t0);
	//printf("\033[%i;%iH%lld", k, j++ * SPACING, get_time());
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->die->time - get_time()  + philos->die->t0);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->eat->status);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->sleep->status);
	printf("\033[%i;%iH%lld", k, col + j++ * SPACING, philos->die->status);
	printf("\033[%i;%iH%u", k, col + j++ * SPACING, philos->nr_eats);
	//printf("\033[%i;%iH%i", k, j++ * SPACING, philos->max_philos);
	if (philos->eat->status)
	{
		printf("%s\e[30m\033[%i;%iH% 3i,%3i%s", BCK_RED, k, col + j++ * SPACING, philos->fork_left, philos->arr_forks[philos->fork_left], BCK_STD);
		printf("%s\e[30m\033[%i;%iH% 3i,%3i%s", BCK_RED, k, col + j * SPACING, philos->fork_rght, philos->arr_forks[philos->fork_rght], BCK_STD);
	}
	else if (philos->sleep->status)
	{
		printf("%s\e[30m\033[%i;%iH% 3i,*%i*%s", BCK_GREEN, k, col + j++ * SPACING, philos->fork_left, philos->arr_forks[philos->fork_left], BCK_STD);
		printf("%s\e[30m\033[%i;%iH% 3i,*%i*%s", BCK_GREEN, k, col + j * SPACING, philos->fork_rght, philos->arr_forks[philos->fork_rght], BCK_STD);
	}
	else
	{
		printf("%s\e[30m\033[%i;%iH% 3i,*%i*%s", BCK_WHITE, k, col + j++ * SPACING, philos->fork_left, philos->arr_forks[philos->fork_left], BCK_STD);
		printf("%s\e[30m\033[%i;%iH% 3i,*%i*%s", BCK_WHITE, k, col + j * SPACING, philos->fork_rght, philos->arr_forks[philos->fork_rght], BCK_STD);
	}	
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

/*
void	ft_putnbr (long long int nbr)
{
	char c;

	if (nbr > 10)
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write(1, &c, 1);
}

void	print_msg(t_list_philo *philos, char *str)
{
	int i;

	while (pthread_mutex_lock(philos->mutex_prt))
		write(1, "wait to lock", 12);
	write(1, "Philosopher  ", 13);
	ft_putnbr(philos->philo_nr);
	write(1, "  ", 2);
	ft_putnbr(get_time() - philos->die->t0);
	write(1, "  ", 2);
	ft_putnbr(get_time());
	write(1, "  ", 2);
	i = 0;
	while(str[i])
		write(1, &str[i++], 1);
	write(1, "\n", 1);
	pthread_mutex_unlock(philos->mutex_prt);
}
*/