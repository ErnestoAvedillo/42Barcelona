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
//sort_stack
void		sort_stack( t_stack **stacks);
//sort_stack_st2
void		sort_stack_st2( t_stack **stacks);
//sort_utils
int 		calculate_moves(t_element *element, t_stack *stack);
void 		coplete_elements(t_stack *stack);
void 		calc_all_moves (t_stack *stack);
//push_free
void 		free_all_stacks(t_stack **stacks);
int 		free_stack (t_stack *ptr);
//movements
//swap
void    	swap (t_stack *stack);
void    	ss (t_stack **stacks);
void 		sa (t_stack **stacks);
void 		sb (t_stack **stacks);

//push
void	 	push (t_stack *stack_a, t_stack *stack_b);
void	    pa(t_stack **stacks);
void	    pb(t_stack **stacks);
//rotate
void 		rotate (t_stack *stack);
void    	rr (t_stack **stacks);
void    	ra (t_stack **stacks);
void    	rb (t_stack **stacks);
//revrotate
void 		revrotate (t_stack *stack);
void    	rrr (t_stack **stacks);
void    	rra (t_stack **stacks);
void    	rrb (t_stack **stacks);

//push_utils
void 		print_stacks(t_stack **stacks);
void 		*search_item(int i, t_stack *stack);
int 		get_sentido (int valor);


# endif
