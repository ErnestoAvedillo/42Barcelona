/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_mutex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:31:27 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/23 16:31:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	check_is_number(int av, char **ac)
{
	int	i;
	int	j;

	i = 0;
	while (++i < av)
	{
		j = -1;
		while (ac[i][++j])
			if (ac[i][j] < 48 || ac[i][j] > 57)
				return (0);
	}
	return (1);
}

t_philo	*get_params(int av, char **ac)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->nr_ph = ft_atoi(ac[1]);
	philo->die = ft_atoi(ac[2]);
	philo->eat = ft_atoi(ac[3]);
	philo->sleep = ft_atoi(ac[4]);
	if (av == 6)
		philo->lim_eats = ft_atoi(ac[5]);
	else
		philo->lim_eats = 0;
	philo->proc_finished = 0;
	philo->start = 0;
	philo->isdead = 0;
	philo->t0 = get_time();
	if (philo->nr_ph == 0 || philo->die == 0 || philo->eat == 0 || \
		philo->sleep == 0 || !init_mutex(philo))
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}

pthread_mutex_t	*fork_mutex_arr(int nr)
{
	pthread_mutex_t		*i;
	int					j;

	i = (pthread_mutex_t *)malloc(nr * sizeof(pthread_mutex_t));
	if (!i)
		return (NULL);
	j = 0;
	while (j < nr)
		pthread_mutex_init(&i[j++], NULL);
	return (i);
}

int	init_mutex(t_philo *phi_head)
{
	phi_head->mutex_forks = fork_mutex_arr(phi_head->nr_ph);
	phi_head->mutex_prt = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phi_head->mutex_prt, NULL);
	phi_head->dead = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(phi_head->dead, NULL);
	if (!phi_head->mutex_forks || !phi_head->mutex_prt || !phi_head->dead)
		return (0);
	return (1);
}
