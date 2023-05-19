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
#include "colors.h"

//for print prouposes
#define SPACING 8
#define COL_LEN 50
#define NEXT_COL SPACING * 9

typedef struct s_control_proc
{
	unsigned int	time;
	long long		status;
	long long		t0;
	long long		t1;
} t_control_proc;

typedef struct s_list_philo
{
	int				philo_nr;
	pthread_t		thrd;
	t_control_proc	*die;
	t_control_proc	*eat;
	t_control_proc	*sleep;
	int				think;
	unsigned int	lim_eats;
	unsigned int	nr_eats;
	int				max_philos;
	int				fork_left;
	int				fork_rght;
	int				*start;
	int				*arr_forks;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_prt;
	pthread_mutex_t	*dead;
	void			*next;
} t_list_philo;

typedef struct s_philo
{
	int				nr_ph;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	nr_eats;
	int				proc_finished;
	int				start;
	int				*arr_forks;
	pthread_mutex_t *mutex_forks;
	pthread_mutex_t *mutex_prt;
	pthread_mutex_t *dead;
	t_list_philo	*first_philo;

} t_philo;

//const char *prt_concepts[] = {"Address","thread","die","eat","sleep","sleep","nr_eats","max_phil","left_fork","rigt_fork"};


//philo_utils
t_philo			*get_params(int av, char **ac);
t_philo			*start_proc(t_philo *philo);
void			join_thread(t_philo *philos);
void			finish_control(t_philo *philos);
long long		get_time(void);
void			ft_usleep(int nbr, t_list_philo *philos);

// ft_isdigit
int				ft_isdigit(int c);
//ft_atoi
int				ft_atoi(const char *str);
//philo_free
void			free_vars(t_philo *philos);
//philo_mem
t_list_philo	*alloc_var(int nr_phil);
//philo_init_mutex
int init_mutex(t_philo *phi_head);
// philo_print
void			print_status(t_list_philo *philos, char *origen);
void			print_header(void);
void			print_msg(t_list_philo *philos, char *str);
//philo_work_proc
void			*work_proc(void *var);
void			ft_putnbr (long long int nbr);

#endif