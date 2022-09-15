/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:28:02 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/24 12:47:24 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strcat(char *dest, char *src)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (dest[counter1] != '\0')
	{
		counter1++;
	}
	counter2 = 0;
	while (src[counter2] != '\0' )
	{
		dest[counter1] = src[counter2];
		counter1++;
		counter2++;
	}
	dest[counter1] = '\0';
	return (dest);
}
/*
int main ()
{
	char str1[30]="ebesfgg";
	const char str2[30]="eceame";
	char str3[30]="ebesfgg";
	char str4[30]="eceame";
	unsigned int n_char;
	char *ret1;
	char *ret2;
	n_char = 1;
	printf ("str1 : %p  str2: %p\n",&str1,&str3);
	printf ("str1 : %s  str2: %s\n",str1,str3);
	
	ret2 = strcat (str1,str2);
	printf ("str2: %p\n",ret2);
	ret1 = ft_strcat (str3,str4);
	printf ("str1: %p\n",ret1);

	n_char = 0;
	while (str1[n_char] != '\0')
	{
		write(1,&str1[n_char],1);
		n_char++;
	}
	printf("\n");
	n_char = 0;
	while (str3[n_char] != '\0')
	{
		write(1,&str3[n_char],1);
		n_char++;
	}

	return 0;
}
*/
