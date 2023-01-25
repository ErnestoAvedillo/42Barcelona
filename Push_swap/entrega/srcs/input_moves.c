/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:09 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/24 10:14:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
/*
void *def_arr_mov_func()
{
	void *move_func;
	move_func = (void *)malloc(NBR_MOVES * sizeof(void));
	if (!move_func)
		return (NULL);
	move_func[0] = &sa;
	move_func[1] = &sb;
	move_func[2] = &ss;
	move_func[3] = &ra;
	move_func[4] = rb;
	move_func[5] = rr;
	move_func[6] = rra;
	move_func[7] = rrb;
	move_func[8] = rrr;
	move_func[9] = pa;
	move_func[10] = pb;
	return (move_func);
}
*/
char **def_arr_mov_names(t_stack **stacks)
{
	int i;
	char **move_names;

	i = -1;
	move_names = (char **)malloc(sizeof(char));
	if (!move_names)
		return (NULL);
	print_stacks(stacks);
	while (++i < NBR_MOVES)
	{
		move_names[i] = (char *)malloc(LEN_MOVES_NAME * sizeof(char));
		if (!move_names[i])
		{
			free_double_point(move_names);
			return (NULL);
		}
	}
	ft_strlcpy(move_names[0], "sa\n", 3);
	ft_strlcpy(move_names[1], "sb\n", 3);
	ft_strlcpy(move_names[2], "ss\n", 3);
	ft_strlcpy(move_names[3], "ra\n", 3);
	ft_strlcpy(move_names[4], "rb\n", 3);
	ft_strlcpy(move_names[5], "rr\n", 3);
	ft_strlcpy(move_names[6], "rra\n", 3);
	ft_strlcpy(move_names[7], "rrb\n", 3);
	ft_strlcpy(move_names[8], "rrr\n", 3);
	ft_strlcpy(move_names[9], "pa\n", 3);
	ft_strlcpy(move_names[10], "pb\n", 3);
	return (move_names);
}

int make_move(int (*move)(t_stack **, int), t_stack **stacks, int print_move)
{
	return (move(stacks, print_move));
}

int input_moves(t_stack **stacks)
{
	int es_ok;
	int i;
	char *str;
	char **data_moves;
	void *move_func[11] = {sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb};

	//move_func = {sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb};
	data_moves = def_arr_mov_names(stacks);
	print_stacks(stacks);
	if (!data_moves)
		return (0);
	str = get_next_line(0);
	while (str)
	{
		i = -1;
		es_ok = 0;
		while (++i < NBR_MOVES)
		{
			if (!ft_strncmp(str, data_moves[i], ft_strlen(data_moves[i])))
			{
				make_move(move_func[i], stacks, 1);
				es_ok = 1;
				break;
			}
		}
		if (es_ok == 0)
			return (1);
		str = get_next_line(0);
	}
	return (0);
}
