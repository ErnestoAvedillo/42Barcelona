/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:35:17 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:35:24 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int var);

void	ft_is_negative(int var)
{
	char	val_p;
	char	val_n;

	val_p = 'P';
	val_n = 'N';
	if (var < 0)
	{
		write (1, &val_n, 1);
	}
	else
	{
		write (1, &val_p, 1);
	}
}
/*
int main()
{
    int mi_var;
    mi_var = -2;
    ft_is_negative(mi_var);


    return 0;
}
*/
