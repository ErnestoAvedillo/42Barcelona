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

#ifndef CHECKER_H
# define CHECKER_H
# include<limits.h>
# include"../nextline/get_next_line.h"
# include"./push_common.h"
# define NBR_MOVES 11
# define LEN_MOVES_NAME 5

//input_moves
int			input_moves(t_stack **stacks);
typedef int	(*operation_move)(t_stack**);
void		check_final_stacks(t_stack **stacks);
typedef struct l_list_moves {
char		*name[LEN_MOVES_NAME];
void		*ptr_function;
} t_list_moves;
#endif
