/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:24:37 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/22 16:44:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if ((str[counter] >= 'a' && str[counter] <= 'z'))
		{
			str[counter] -= 32;
		}
		counter++;
	}
	return (str);
}
/*
int main ()
{
	char str1[]="lhehf 203rufeewf";
	char str2[]="´kn w9uwinj";
	char *ret1;
	char *ret2;
	printf ("str1 : %s\n",str1);
	printf ("str2 : %s\n",str2);
	ret1 = ft_strupcase (str1);
	ret2 = ft_strupcase (str2);
	printf ("str1 : %s\n",str1);
	printf ("str2 : %s\n",str2);
	printf ("str1 : %s  ret1: %s\n",str1,ret1);
	printf ("str2 : %s  ret2: %s\n",str2,ret2);
	return 0;
}
*/
