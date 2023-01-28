/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_common.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:38:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/12/29 17:38:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_COMMON_H
# define PUSH_COMMON_H
# include<limits.h>
# include"../printf/ft_printf_bonus.h"
# include"../libft/libft.h"

typedef struct l_stack
{
	int		nbr_elements;
	int		cur_frst_elem;
	int		optim_move;
	void	*optim_elem;
	void	*elem1;
}	t_stack;

typedef struct l_element
{
	int		value;
	int		soll_pos;
	int		ist_pos;
	int		moves;
	void	*next;
}		t_element;

# define INT_STR_LOWER	"2147483648"
# define INT_STR_UPPER	"2147483647"

// check_errors.c
int			check_errors(int av, char **ac);
//check_duplicates
int			check_duplicates(t_stack **stacks);
// create_stacks
t_stack		**createstacks(int av, char **ac);
//sort_stack
void		sort_stack(t_stack **stacks);
//push_free
void		free_all_stacks(t_stack **stacks);
int			free_stack(t_stack *ptr);
void		free_double_point(char **ptr);
//movements
//swap
void		swap(t_stack *stack);
int			ss(t_stack **stacks, int print_move);
int			sa(t_stack **stacks, int print_move);
int			sb(t_stack **stacks, int print_move);
//push
void		push(t_stack *stack_a, t_stack *stack_b);
int			pa(t_stack **stacks, int print_move);
int			pb(t_stack **stacks, int print_move);
//rotate
void		rotate(t_stack *stack);
int			rr(t_stack **stacks, int print_move);
int			ra(t_stack **stacks, int print_move);
int			rb(t_stack **stacks, int print_move);
//revrotate
void		revrotate(t_stack *stack);
int			rrr(t_stack **stacks, int print_move);
int			rra(t_stack **stacks, int print_move);
int			rrb(t_stack **stacks, int print_move);
//push_utils
void		*search_item(int i, t_stack *stack);
int			get_sentido(int valor);
void		print_element(t_element *elem);
void		restore_ist_pos(t_stack **stacks);
//input_data
char		**input_data(char **ac);
int			len_array(char **ptr);
void		print_stacks(t_stack **stacks);
//
int			check_stacks_status(t_stack **stacks, int print, int both_stks);

#endif
