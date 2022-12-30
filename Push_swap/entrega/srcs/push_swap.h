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
# include"./printf/ft_printf.h"
# include"./libft/libft.h"

typedef struct l_stack
{
    int     nbr_elements
    void    *ptr
}   t_stack;

typedef struct l_element
{
	int     value;
	int		real_pos;
	int		curr_pos;
	int		moves;
}		t_element;


//check_errors.c
int check_errors(int av, char **ac);




# endif
