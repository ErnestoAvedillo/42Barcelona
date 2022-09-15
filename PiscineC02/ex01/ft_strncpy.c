/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:21:00 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/28 18:43:10 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		count;

	count = 0;
	while (src[count] != '\0' && count < n)
	{
		dest[count] = src[count];
		count++;
	}
	if (count < n && src[count] != '\0')
	{	
		while (dest[count] != '\0')
		{
			dest [count] = '\0';
			count++;
		}
	}
	return (dest);
}
/*
int main ()
{
	char str1[]="Sample string";
	char str2[40];
	char str3[40];
	char *ret1;
	char *ret2;

	ret1 = strncpy (str2,str1, 5);
	ret2 = strncpy (str3,"copy successful",5);
	printf ("str1: %s copiado a str2: %s\nstr3: %s\n",str1,str2,str3);
	printf ("ret1: %s ret2: %s\n",ret1,ret2);
	printf ("ret1: %p ret2: %p\n",ret1,ret2);
	ret1 = ft_strncpy (str2,str1,5);
	ret2 = ft_strncpy (str3,"copy successful",5);
	printf ("str1: %s copiado a str2: %s\nstr3: %s\n",str1,str2,str3);
	printf ("ret1: %s ret2: %s\n",ret1,ret2);
	printf ("ret1: %p ret2: %p\n",ret1,ret2);

	return 0;
}
*/
