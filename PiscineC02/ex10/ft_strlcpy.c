/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:26:29 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/28 19:32:59 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	length_str(char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	return (count);
}

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;
	int				terminar;

	counter = 0;
	terminar = 0;
	if (length_str(dest) < size || length_str(dest) == 0)
		return (0);
	while (src[counter] != '\0' && ! terminar)
	{
		if (size > 0 && (counter < (size - 1)))
			dest[counter] = src[counter];
		else
		{
			dest[counter] = '\0';
			terminar = 1;
		}
		counter++;
	}
	while (src[counter] != '\0')
	{
		dest[counter] = '\0';
		counter++;
	}
	return (counter);
}
/*
int main ()
{
	char str1[]="salut, commentnwww";
	char str2[]="me cago en la t";
	char str3[]="salut, commentnwww";
	char str4[]="me cago en la t";
	unsigned int ret1;
	unsigned int ret2;
	unsigned int misize = 10;

	printf ("str1 : %s\n",str1);
	printf ("str2 : %s\n",str2);


	ret2 = ft_strlcpy( str4, str3, misize);
	printf ("str4 : %s\n",str4);

	ret1 = strlcpy( str2, str1, misize);
	printf ("str2 : %s\n",str2);


	printf ("ret1 : %d\n",ret1);
	printf ("ret2 : %d\n",ret2);

	return 0;
}
*/
