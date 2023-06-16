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

int	checkerrors(int av, char **ac)
{
	if (av < 5)
	{
		printf("Incorrect number of arguments.\n");
		printf("****usage ./philo Nr T_die T_eat T_sleep [Max_eats]***\n");
		printf("\tNr: Number of philosofers\n");
		printf("\tT_die: time to die in miliseconds\n");
		printf("\tT_eat: time eating in miliseconds\n");
		printf("\tT_sleep: time sleeping in miliseconds\n");
		printf("\tMax_eats: Minimum number of eats must eat all philosophers\n");
		return (0);
	}
	if (!check_is_number(av, ac))
	{
		printf("Arguments must contain only numbers\n");
		return (0);
	}
	return (1);
}

int	main(int av, char **ac)
{
	t_philo			*header;
	t_list_philo	*first_philo;

	if (!checkerrors(av, ac))
		return (0);
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
