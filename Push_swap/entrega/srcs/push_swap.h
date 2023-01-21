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

#define NBR_MOVES 11
#define LIST_MOVES [] = { \
	{"sa",(*sa)(t_stack**)}, \
	{"sb",(*sb)(t_stack**)}, \
	{"ss",(*ss)(t_stack**)}, \
	{"ra",(*ra)(t_stack**)}, \
	{"rb",(*rb)(t_stack**)}, \
	{"rr",(*rr)(t_stack**)}, \
	{"rra",(*rra)(t_stack**)}, \
	{"rrb",(*rrb)(t_stack**)}, \
	{"rrr",(*rrr)(t_stack**)}, \
	{"pa",(*pa)(t_stack**)}, \
	{"pb",(*pb)(t_stack**)} \
}
#define INT_STR_LOWER	"2147483648"
#define INT_STR_UPPER	"2147483647"

//check_errors.c
int			check_errors(int av, char **ac);
//check_duplicates
int 		check_duplicates(t_stack **stacks);
// create_stacks
t_stack 	**createstacks(int av, char **ac);
//sort_stack
void		sort_stack( t_stack **stacks);
// sort_stack_st2
void sort_stack_st2(t_stack **stacks);
// sort_stack_st3
void sort_stack_st3(t_stack **stacks);
// sort_utils_1
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
void 		free_double_point (char **ptr);
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
//input_data
char    	**input_data(char **ac);
int			len_array (char **ptr);
//basic input
int			basic_input(t_stack **stacks);
void 		solve_3_st(t_stack **stacks);
//basic_5_input
void 		sort_5_elm_stack(t_stack **stacks);
void 		sort_4_elm_stack(t_stack **stacks);
//input_moves
void input_moves(t_stack **stacks);

#endif
