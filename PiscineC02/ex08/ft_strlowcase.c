/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:25:20 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/22 16:45:33 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strlowcase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		if ((str[counter] >= 'A' && str[counter] <= 'Z'))
		{
			str[counter] += 32;
		}
		counter++;
	}
	return (str);
}
/*
int main ()
{
	char str1[]="ÑLRHFWÑEO89";
	char str2[]="WEOGK'0";
	char *ret1;
	char *ret2;
	printf ("str1 : %s\n",str1);
	printf ("str2 : %s\n",str2);
	ret1 = ft_strlowcase (str1);
	ret2 = ft_strlowcase (str2);
	printf ("str1 : %s\n",str1);
	printf ("str2 : %s\n",str2);
	printf ("str1 : %s  ret1: %s\n",str1,ret1);
	printf ("str2 : %s  ret2: %s\n",str2,ret2);
	return 0;
}
*/
