/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:33:44 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:33:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void);

void	ft_print_reverse_alphabet(void)
{
	char	var_c;

	var_c = 'z';
	while (var_c >= 'a')
	{
		write(1, &var_c, 1);
		var_c--;
	}
}
/*
int main()
{
    
    ft_print_reverse_alphabet();


    return 0;
}
*/
