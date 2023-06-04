/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:52:06 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/10 21:52:09 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int av, char **ac)
{
	t_philo *philo;

	if (av < 5)
	{
		printf("\n");
		return (0);
	}
	philo = get_params(av, ac);
	if (!philo)
		{
		printf("ERROR TO ALLOCATE MEMORY1\n");
		return (0);
		}
	philo = start_proc(philo);
	if (!philo)
		{
		printf("ERROR TO ALLOCATE MEMORY2\n");
		return (0);
		}
		finish_control(philo);
	//	join_thread(philo);
		free_vars(philo);
		return (0);
}