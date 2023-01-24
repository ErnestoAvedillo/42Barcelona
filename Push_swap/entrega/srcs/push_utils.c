/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:19:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/05 08:19:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	*search_item(int i, t_stack *stack)
{
	t_element	*element;

	element = stack->elem1;
	while (element)
	{
		if (element->soll_pos == i)
			return (element);
		element = element->next;
	}
	return (NULL);
}

int	get_sentido(int valor)
{
	if (valor >= 0)
		return (1);
	return (0);
}

void	restore_ist_pos(t_stack **stacks)
{
	t_element	*element;
	int			i;

	i = 1;
	element = stacks[0]->elem1;
	while (element)
	{
		element->ist_pos = i++;
		element = element->next;
	}
	stacks[0]->nbr_elements = i - 1;
	i = 1;
	element = stacks[1]->elem1;
	while (element)
	{
		element->ist_pos = i++;
		element = element->next;
	}
	stacks[1]->nbr_elements = i - 1;
	return ;
}
