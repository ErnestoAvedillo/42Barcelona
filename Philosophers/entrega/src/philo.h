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
#include <sys/time.h>

typedef struct s_philo
{
	int nr_ph;
	unsigned int die;
	unsigned int eat;
	unsigned int sleep;
	unsigned int nr_eats;
} t_philo;

typedef struct s_control_proc
{
	unsigned int	time;
	int				status;
	long long		t0;
	long long		t1;
	int				finished;
} t_control_proc;

typedef struct s_list_philo
{
	int				philo_nr;
	pthread_t		thrd;
	t_control_proc	*die;
	t_control_proc	*eat;
	t_control_proc	*sleep;
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
void			finish_control(t_list_philo *philos);

// ft_isdigit
int				ft_isdigit(int c);
//ft_atoi
int				ft_atoi(const char *str);
//philo_mem
void			free_vars(t_list_philo *philos);
t_list_philo	*alloc_var(int nr_phil);
// philo_print
void			print_status(t_list_philo *philos);
void			print_header(int nr);

#endif