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
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include "colors.h"

//for print prouposes
# define SPACING 8
# define COL_LEN 71
# define NEXT_COL 54
# define NEW_BLOCK 20

typedef struct s_control_proc
{
	unsigned int	time;
	long long		status;
	long long		t1;
}	t_control_proc;

typedef struct s_philo
{
	int				nr_ph;
	unsigned int	die;
	unsigned int	eat;
	unsigned int	sleep;
	unsigned int	lim_eats;
	int				proc_finished;
	int				start;
	int				isdead;
	long long		t0;
	pthread_t		thrd_ctrl;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	*mutex_prt;
	pthread_mutex_t	*dead;
}	t_philo;

typedef struct s_list_philo
{
	int				philo_nr;
	pthread_t		thrd;
	long long		die_t1;
	unsigned int	nr_eats;
	int				max_philos;
	int				fork_left;
	int				fork_rght;
	int				*start;
	int				istart;
	int				prt_meals_eated;
	t_philo			*header;
	void			*next;
}	t_list_philo;

//philo_utils
int				ft_putnbr(long long int nbr);
t_list_philo	*start_proc(t_philo *philo);
void			join_thread(t_list_philo *first_philo);
void			finish_control(t_list_philo *first_philo);
//int				dying_cntrol(t_list_philo *philos);
void			*dying_cntrol(void *var);

// ft_isdigit
int				ft_isdigit(int c);
//ft_atoi
int				ft_atoi(const char *str);
//philo_free
void			free_vars(t_list_philo *first_philo);
//philo_mem
t_list_philo	*alloc_var(int nr_phil);
//philo_init
t_philo			*get_params(int av, char **ac);
int				init_mutex(t_philo *phi_head);
int				check_is_number(int av, char **ac);
// philo_print
int				print_status(t_list_philo *philos, char *origen, char *color);
void			print_header(void);
void			print_meals_eaten(t_list_philo *first_philo);

// philo_work_proc
void			*work_proc(void *var);

// philo_time_tool
long long		get_time(void);
int				ft_usleep(int i, t_list_philo *philos);
#endif