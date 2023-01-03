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
	int		real_pos;
	int		curr_pos;
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



# endif
