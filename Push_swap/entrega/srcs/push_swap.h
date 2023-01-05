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

#ifndef PUSH_SWAP
# define PUSH_SWAP
# include<limits.h>
# include"../printf/ft_printf.h"
# include"../libft/libft.h"

typedef struct l_stack
{
    int     nbr_elements;
	int		cur_frst_elem;
    void    *elem1;
}   t_stack;

typedef struct l_element
{
	int     value;
	int		soll_pos;
	int		ist_pos;
	int		moves;
	void	*next;
}		t_element;

#define INT_STR_LOWER	"2147483648"
#define INT_STR_UPPER	"2147483647"

//check_errors.c
int			check_errors(int av, char **ac);
t_stack 	**createstacks(int av, char **ac);
int 		free_stack (t_stack *ptr);
void		sort_stack( t_stack **stacks);
void 		print_stacks(t_stack **stacks);
int 		calculate_moves(t_element *element, t_stack *stack);
void 		coplete_elements(t_stack *stack);
void 		calc_all_moves (t_stack *stack);

//movements
void    swap (t_stack *stack);
void 	push (t_stack *stack_a, t_stack *stack_b);
void 	rotate (t_stack *stack);
void    swap2 (t_stack **stacks);
void    rotate2 (t_stack **stacks);
void 	revrotate (t_stack *stack);
void    revrotate2 (t_stack **stacks);


# endif
