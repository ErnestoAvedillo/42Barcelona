/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:27:08 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/28 19:29:07 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <unistd.h>

void	print_each_char_hex(int val)
{
	int		div;
	int		mod;
	char	*val_hex;

	val_hex = "0123456789abcdef";
	div = val / 16;
	mod = val % 16;
	if (div > 0)
	{
		print_each_char_hex(div);
	}
	write(1, &val_hex[mod], 1);
}

void	print_hex(int val, int sizereq)
{
	char	cero_char;
	int		count;
	int		curr_nr_char;
	int		div;

	div = val;
	count = 1;
	while (div / 16)
	{
		div /= 16;
		count++;
	}
	curr_nr_char = count;
	cero_char = '0';
	if (curr_nr_char < sizereq)
	{
		while (count < sizereq)
		{
			write(1, &cero_char, 1);
			count++;
		}
	}
	print_each_char_hex(val);
}

void	ft_putstr_non_printable(char *str)
{
	char	back_slash;
	int		counter;

	counter = 0;
	back_slash = '\\';
	while (str[counter] != '\0')
	{
		if (!(str[counter] >= 32 && str[counter] <= 127))
		{
			write(1, &back_slash, 1);
			print_hex(str[counter], 2);
		}
		else
		{
			write(1, &str[counter], 1);
		}
		counter++;
	}
	return ;
}
/*	
int main ()
{
	char str1[]="Coucou\ntu vas bien ?";
	char str2[]="▬124û3423ing";
	print_hex(16,2);
	printf ("\n");
	print_hex(17,3);
	printf ("\n");
	print_hex(30,4);
	printf ("\n");

	ft_putstr_non_printable (str1);
	printf ("\nstr 1: %s\n",str1);
	ft_putstr_non_printable (str2);
	printf ("\nstr 2: %s\n",str2);
	return 0;
}
*/
