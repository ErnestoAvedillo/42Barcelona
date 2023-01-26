/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include"push_common.h"

#define SIGN_MOV 0
#define	SIGN_STK 1
#define	MAX_ELEM 2
#define	MAX_STK 3
#define	MAX_ADD_ELEM 4
#define MAX_ADD_STK 5

//sort_stack
void		sort_stack( t_stack **stacks);
// sort_stack_st2
void		sort_stack_st2(t_stack **stacks);
// sort_stack_st3
void		sort_stack_st3(t_stack **stacks);
// sort_utils_1
int			calculate_moves(t_element *element, t_stack *stack);
void		coplete_elements(t_stack *stack);
void		calc_all_moves(t_stack *stack);
//sort_utils_2
void		moves_2_up(t_stack **stacks);
t_element	*get_last_elem(t_stack *stack);
//basic input
int			basic_input(t_stack **stacks);
void		solve_3_st(t_stack **stacks);
//basic_5_input
void		sort_5_elm_stack(t_stack **stacks);
void		sort_4_elm_stack(t_stack **stacks);
#endif
