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
# include"../printf/ft_printf_bonus.h"
# include"../libft/libft.h"

typedef struct l_stack
{
    int     nbr_elements;
	int		cur_frst_elem;
	int		optim_move;
	void	*optim_elem;
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
//sort_utils_1
int 		calculate_moves(t_element *element, t_stack *stack);
void 		coplete_elements(t_stack *stack);
void 		calc_all_moves (t_stack *stack);
//sort_utils_2
void		moves_2_up (t_stack **stacks);
t_element 	*get_last_elem (t_stack *stack);
void 		restore_ist_pos (t_stack **stacks);

//push_free
void 		free_all_stacks(t_stack **stacks);
int 		free_stack (t_stack *ptr);
//movements
//swap
void    	swap (t_stack *stack);
int    		ss (t_stack **stacks);
int 		sa (t_stack **stacks);
int 		sb (t_stack **stacks);

//push
void	 	push (t_stack *stack_a, t_stack *stack_b);
int	    	pa(t_stack **stacks);
int	    	pb(t_stack **stacks);
//rotate
void 		rotate (t_stack *stack);
int    		rr (t_stack **stacks);
int    		ra (t_stack **stacks);
int    		rb (t_stack **stacks);
//revrotate
void 		revrotate (t_stack *stack);
int    		rrr (t_stack **stacks);
int    		rra (t_stack **stacks);
int    		rrb (t_stack **stacks);

//push_utils
void 		print_stacks(t_stack **stacks);
void 		*search_item(int i, t_stack *stack);
int 		get_sentido (int valor);
void 		print_element (t_element *elem);


# endif
