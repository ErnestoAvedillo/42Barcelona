/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:34 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:47:40 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

/*
	Returns the moves to be done
	1  --> for rr
	-1 --> for rrr
	2  --> for ra
	3  --> for rb
	-2 --> for rra
	-3 --> for rrb
	4  --> for ra & rrb
	-4  --> for rra & rb
	if there is no moves to be done, returns 0
*/
int	still_moves(t_stack **stacks)
{
	if (stacks[0]->optim_move > 0 && stacks[1]->optim_move > 0)
		return (1);
	if (stacks[0]->optim_move < 0 && stacks[1]->optim_move < 0)
		return (-1);
	if (stacks[0]->optim_move > 0 && stacks[1]->optim_move == 0)
		return (2);
	if (stacks[0]->optim_move < 0 && stacks[1]->optim_move == 0)
		return (-2);
	if (stacks[0]->optim_move == 0 && stacks[1]->optim_move > 0)
		return (3);
	if (stacks[0]->optim_move == 0 && stacks[1]->optim_move < 0)
		return (-3);
	if (stacks[0]->optim_move > 0 && stacks[1]->optim_move < 0)
		return (4);
	if (stacks[0]->optim_move < 0 && stacks[1]->optim_move > 0)
		return (-4);
	return (0);
}

int	execute_move(int (*move)(t_stack **, int), t_stack **stacks, int print_move)
{
	int	i;

	i = move(stacks, print_move);
	if (move == rr || move == ra)
		stacks[0]->optim_move--;
	if (move == rr || move == rb)
		stacks[1]->optim_move--;
	if (move == rrr || move == rra)
		stacks[0]->optim_move++;
	if (move == rrr || move == rrb)
		stacks[1]->optim_move++;
	return (i);
}

void	define_pos_mov(int *pos_mov)
{
	pos_mov[0] = 1;
	pos_mov[1] = -1;
	pos_mov[2] = 2;
	pos_mov[3] = -2;
	pos_mov[4] = 3;
	pos_mov[5] = -3;
	pos_mov[6] = 4;
	pos_mov[7] = -4;
}

void	define_moves(void **moves)
{
	moves[0] = rr;
	moves[1] = rrr;
	moves[2] = ra;
	moves[3] = rra;
	moves[4] = rb;
	moves[5] = rrb;
	moves[6] = ra;
	moves[7] = rra;
}

void	move2top(t_stack **stacks)
{
	int		i;
	int		movement;
	int		pos_mov[8];
	void	*moves[8];

	define_pos_mov(pos_mov);
	define_moves(moves);
	movement = still_moves(stacks);
	while (movement != 0)
	{
		i = -1;
		while (++i < 8)
			if (movement == pos_mov[i])
				execute_move(moves[i], stacks, 1);
		movement = still_moves(stacks);
	}
}
/*	while (movement == 1)
	{
		rr(stacks, 1);
		stacks[0]->optim_move--;
		stacks[1]->optim_move--;
		movement = still_moves(stacks);
	}
	while (movement == -1)
	{
		rrr(stacks, 1);
		stacks[0]->optim_move++;
		stacks[1]->optim_move++;
		movement = still_moves(stacks);
	}
	while (movement == 2 || movement == 4)
	{
		ra(stacks, 1);
		stacks[0]->optim_move--;
		movement = still_moves(stacks);
	}
	while (movement == -2 || movement == -4)
	{
		rra(stacks, 1);
		stacks[0]->optim_move++;
		movement = still_moves(stacks);
	}
	while (movement == 3)
	{
		rb(stacks, 1);
		stacks[1]->optim_move--;
		movement = still_moves(stacks);
	}
	while (movement == -3)
	{
		rrb(stacks, 1);
		stacks[1]->optim_move++;
		movement = still_moves(stacks);
	}
}*/