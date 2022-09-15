/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:42:52 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 18:42:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char	var_c;

	var_c = 'a';
	while (var_c <= 'z')
	{
		write(1, &var_c, 1);
		var_c++;
	}
}
/*
int main()
{
    
    ft_print_alphabet();


    return 0;
}
*/
