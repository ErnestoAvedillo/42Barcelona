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

int	print_status(t_list_philo *philos, char *origen, char *COLOR)
{
	int	j;
	int	k;
	int	col;

	col = philos->philo_nr / COL_LEN * NEXT_COL + philos->philo_nr / \
	COL_LEN * NEW_BLOCK;
	k = philos->philo_nr + 1 - (philos->philo_nr / COL_LEN) * COL_LEN;
	pthread_mutex_lock(philos->header->mutex_prt);
	printf("\033[%i;%iH%i", k, col + 1, philos->philo_nr);
	j = 1;
	printf("\033[%i;%iH%lld", k, col + SPACING * j++, get_time() - \
	philos->header->t0);
	printf("\033[%i;%iH%lld", k, col + SPACING * j++, get_time() - \
	philos->die_t1);
	printf("\033[%i;%iH%u", k, col + SPACING * j++, philos->nr_eats);
	printf("%s\e[30m\033[%i;%iH%16s%s", COLOR, k, col + SPACING * j++, \
	origen, BCK_STD);
	printf("\n");
	pthread_mutex_unlock(philos->header->mutex_prt);
	return (0);
}

void	print_header(void)
{
	int	j;

	printf("\033[1;1HPhilo");
	j = 1;
	printf("\033[1;%iHorigen", SPACING * j++);
	printf("\033[1;%iHtime2die", SPACING * j++);
	printf("\033[1;%iHeat", SPACING * j++);
	printf("\033[1;%iHsleep", SPACING * j++);
	printf("\033[1;%iHdie", SPACING * j++);
	printf("\033[1;%iHnr_eats", SPACING * j++);
	printf("\033[1;%iHleft_fork", SPACING * j++);
	printf("\033[1;%iHrigt_fork", SPACING * j++);
	printf("\n");
	return ;
}

void	print_meals_eaten(t_list_philo *first_philo)
{
	(void)first_philo;
}

#elif MANDAT

int	print_status(t_list_philo *philos, char *origen, char *color)
{
	pthread_mutex_lock(philos->header->mutex_prt);
	printf("Philosopher %i at t0:%lld %s %s %s \n", philos->philo_nr,
		   get_time() - philos->header->t0, color, origen, BCK_STD);
	pthread_mutex_unlock(philos->header->mutex_prt);
	return (0);
}

void	print_meals_eaten(t_list_philo *first_philo)
{
	t_list_philo	*aux;

	if (first_philo->header->lim_eats)
	{
		aux = first_philo;
		while (aux)
		{
			pthread_mutex_lock(aux->header->mutex_prt);
			printf("Philosopher %i  has eaten %i meals.\n", aux->philo_nr, \
				aux->nr_eats);
			pthread_mutex_unlock(aux->header->mutex_prt);
			aux = aux->next;
		}
	}
}
#endif
