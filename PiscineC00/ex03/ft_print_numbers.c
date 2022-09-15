/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 16:05:38 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/20 13:16:53 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void);

void	ft_print_numbers(void)
{
	char	var_c ;

	var_c = '0';
	while (var_c <= '9')
	{
		write(1, &var_c, 1);
		var_c++;
	}
}
/*
int main()
{
    
    ft_print_numbers();


    return 0;
}
*/
