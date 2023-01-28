/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 13:47:34 by eavedill          #+#    #+#             */
/*   Updated: 2023/01/08 13:47:40 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	save_cur_min_move(t_element *elma, t_element *elmb, t_stack **stks)
{
	stks[0]->optim_move = elma->moves;
	stks[0]->optim_elem = elma;
	stks[1]->optim_move = elmb->moves;
	stks[1]->optim_elem = elmb;
	return ;
}

void	analyze_moves(t_stack **stk, t_element *a, t_element *b)
{
	int	def[6];

	def[SIGN_MOV] = ft_issamesign(a->moves, b->moves);
	def[SIGN_STK] = ft_issamesign(stk[0]->optim_move, stk[1]->optim_move);
	def[MAX_ELEM] = ft_max(ft_abs(a->moves), ft_abs(b->moves));
	def[MAX_STK] = ft_max(ft_abs(stk[0]->optim_move), \
						ft_abs(stk[1]->optim_move));
	def[MAX_ADD_ELEM] = ft_abs(a->moves) + ft_abs(b->moves);
	def[MAX_ADD_STK] = ft_abs(stk[0]->optim_move) + ft_abs(stk[1]->optim_move);
	if (def[SIGN_MOV] && def[SIGN_STK] && (def[MAX_ELEM] < def[MAX_STK]))
		save_cur_min_move(a, b, stk);
	if (!def[SIGN_MOV] && def[SIGN_STK] && (def[MAX_ADD_ELEM] < def[MAX_STK]))
		save_cur_min_move(a, b, stk);
	if (def[SIGN_MOV] && !def[SIGN_STK] && (def[MAX_ELEM] < def[MAX_ADD_STK]))
		save_cur_min_move(a, b, stk);
	if (!def[SIGN_MOV] && !def[SIGN_STK] && \
		(def[MAX_ADD_ELEM] < def[MAX_ADD_STK]))
		save_cur_min_move(a, b, stk);
	return ;
}

int	belong_2_interval(t_stack **stacks, t_element *elema, t_element *elemb)
{
	t_element	*elemb_next;
	int			interv_sup;
	int			interv_low;

	elemb_next = elemb->next;
	if (!elemb_next)
		elemb_next = stacks[1]->elem1;
	if (elemb->soll_pos < elemb_next->soll_pos)
	{
		interv_low = 0;
		interv_sup = elemb->soll_pos;
		if (elema->soll_pos > interv_low && elema->soll_pos < interv_sup)
			return (1);
		interv_low = elemb_next->soll_pos;
		interv_sup = stacks[0]->nbr_elements + stacks[1]->nbr_elements;
		if (elema->soll_pos > interv_low && elema->soll_pos < interv_sup)
			return (1);
		return (0);
	}
	interv_low = elemb_next->soll_pos;
	interv_sup = elemb->soll_pos;
	if (elema->soll_pos > interv_low && elema->soll_pos < interv_sup)
		return (1);
	return (0);
}

static void	init_optim_move(t_stack **stks)
{
	stks[1]->optim_move = stks[1]->nbr_elements;
	stks[1]->optim_elem = stks[1]->elem1;
	stks[0]->optim_move = stks[0]->nbr_elements;
	stks[0]->optim_elem = stks[0]->elem1;
}

/*
Element stack a = 0
Elementb stack b = 1
Elementb_next stack b = 2
*/
void	seek_min_moves(t_stack **stks)
{
	t_element	*elmnt[3];
	int			belongs;

	elmnt[2] = stks[1]->elem1;
	elmnt[1] = get_last_elem(stks[1]);
	init_optim_move(stks);
	elmnt[0] = stks[0]->elem1;
	while (elmnt[0])
	{
		elmnt[2] = stks[1]->elem1;
		elmnt[1] = get_last_elem(stks[1]);
		while (elmnt[2])
		{
			belongs = belong_2_interval(stks, elmnt[0], elmnt[1]);
			if (belongs)
				analyze_moves(stks, elmnt[0], elmnt[2]);
			elmnt[1] = elmnt[2];
			elmnt[2] = elmnt[1]->next;
			if (ft_abs(stks[0]->optim_move) + ft_abs(stks[1]->optim_move) <= 1)
				return ;
		}
		elmnt[0] = elmnt[0]->next;
	}
}
