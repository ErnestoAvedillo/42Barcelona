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
	t_list_philo *philos;

	if (av < 5)
	{
		printf("\n");
		return (0);
	}
	philo = get_params(av, ac);
	philos = start_proc(philo);
	free(philo);
	join_thread(philos);
	return (0);
}