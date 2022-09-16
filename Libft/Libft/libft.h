/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 18:18:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void	*content
	struct s_list	*next;
}			t_list;

typedef struct s_split_next
{
	
}			t_split_next;

int 	ft_isalpha(int c);
