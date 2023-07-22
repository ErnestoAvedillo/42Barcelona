/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 16:31:27 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/23 16:31:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

int	check_is_number(int av, char **ac)
{
	int	i;
	int	j;

	i = 1;
	while (i < av)
	{
		j = -1;
		while (ac[i][++j])
			if (ac[i][j] < 48 || ac[i][j] > 57)
				return (0);
		i++;
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
		philo->sleep == 0 || !init_sem(philo))
	{
		free(philo);
		return (NULL);
	}
	return (philo);
}

int	init_sem(t_philo *phi_head)
{
	sem_unlink("sem_print");
	sem_unlink("sem_dead");
	sem_unlink("sem_forks");
	phi_head->sem_prt = sem_open("sem_print", O_CREAT | O_EXCL, 0644, 1);
	phi_head->dead = sem_open("sem_dead", O_CREAT | O_EXCL, 0644, 1);
	phi_head->sem_forks = sem_open("sem_forks", O_CREAT | O_EXCL, 0644, \
		phi_head->nr_ph);
	if (phi_head->sem_prt == SEM_FAILED || phi_head->dead == SEM_FAILED || \
		phi_head->sem_forks == SEM_FAILED)
	{
		printf("Error on creating semaphoresn\n");
		sem_close(phi_head->sem_prt);
		sem_close(phi_head->dead);
		sem_close(phi_head->sem_forks);
		return (0);
	}
	return (1);
}
