/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:55:25 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/10 21:55:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_philo
{
	int nr_ph;
	unsigned int die;
	unsigned int eat;
	unsigned int sleep;
	unsigned int nr_eats;
} t_philo;

typedef struct s_list_philo
{
	pthread_t 		thrd;
	unsigned int 	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	nr_eats;
	int				max_philos;
	int				fork_left;
	int				fork_rght;
	int				*arr_forks;
	void			*next;
} t_list_philo;

//philo_utils
t_philo			*get_params(int av, char **ac);
t_list_philo	*start_proc(t_philo *philo);
void			join_thread(t_list_philo *philos);

// ft_isdigit
int ft_isdigit(int c);
//ft_atoi
int ft_atoi(const char *str);
#endif