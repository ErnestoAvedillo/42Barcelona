/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 08:18:37 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/05 08:18:43 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

t_element	*ft_new_element(t_element *content, int value)
{
	t_element	*ptr;

	ptr = (t_element *)malloc (sizeof (t_element));
	if (ptr == NULL)
		return (NULL);
	content->next = ptr ;
	ptr->value = value;
	ptr->soll_pos = 0;
	ptr->ist_pos = 0;
	ptr->moves = 0;
	ptr->next = NULL;
	return (ptr);
}

void	*create_elements(t_element *elem1, int nbr_elem, char **ac)
{
	t_element	*cur_ptr;
	int			i;

	i = 0;
	cur_ptr = elem1;
	while (nbr_elem > ++i)
	{
		cur_ptr = ft_new_element(cur_ptr, ft_atoi(ac[i]));
		if (!cur_ptr)
			return (NULL);
	}
	return (cur_ptr);
}

t_stack	*retrieve_data(int av, char **ac)
{
	t_element	*cur_ptr;
	t_stack		*stack;

	stack = (t_stack *) malloc (sizeof (t_stack));
	if (!stack)
		return (NULL);
	cur_ptr = (t_element *)malloc(sizeof(t_element));
	if (!cur_ptr)
		free_stack(stack);
	else
	{
		stack->elem1 = cur_ptr;
		cur_ptr->value = ft_atoi(ac[0]);
		if (!create_elements(cur_ptr, av, ac))
			free_stack(stack);
		else
		stack->nbr_elements = av;
		stack->cur_frst_elem = 1;
		stack->optim_move = 0;
		stack->optim_elem = NULL;
		return (stack);
	}
	return (NULL);
}

t_stack	**createstacks(int av, char **ac)
{
	t_stack	**stacks;

	stacks = (t_stack **) malloc (3 * sizeof (t_stack));
	stacks[0] = retrieve_data(av, ac);
	if (!stacks[0])
		return (NULL);
	stacks[1] = malloc (sizeof (t_stack));
	if (!stacks[1])
	{
		free_stack (stacks[0]);
		stacks[1]->nbr_elements = 0;
		stacks[1]->cur_frst_elem = 0;
		stacks[1]->optim_move = 0;
		stacks[1]->elem1 = NULL;
		return (NULL);
	}
	stacks [2] = NULL;
	return (stacks);
}
