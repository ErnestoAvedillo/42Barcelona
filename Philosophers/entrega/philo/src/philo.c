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

int	main(int av, char **ac)
{
	t_philo			*header;
	t_list_philo	*first_philo;

	if (av < 5)
	{
		printf("\n");
		return (0);
	}
	header = get_params(av, ac);
	if (!header)
	{
		printf("DATA ERROR OR ERROR TO ALLOCATE MEMORY\n");
		return (0);
	}
	first_philo = start_proc(header);
	if (!first_philo)
	{
		printf("ERROR TO ALLOCATE MEMORY\n");
		return (0);
	}
	finish_control(first_philo);
	join_thread(first_philo);
	print_meals_eaten(first_philo);
	free_vars(first_philo);
	return (0);
}
