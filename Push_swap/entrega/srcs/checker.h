/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER
# define CHECKER
# include<limits.h>
# include"../nextline/get_next_line.h"
# include"./push_common.h"

//input_moves
int			input_moves(t_stack **stacks);

typedef int (*operation_move)(t_stack**);
#define NBR_MOVES 11
static char *LIST_MOVES[11] = {"sa\n", "sb\n", "ss\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", "pa\n", "pb\n"};
static void *FCN_MOVES[11] = {sa, sb, ss, ra, rb, rr, rra, rrb, rrr, pa, pb};
#endif
