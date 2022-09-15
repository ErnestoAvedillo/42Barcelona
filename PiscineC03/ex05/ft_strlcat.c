/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:55:24 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/28 18:08:05 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	counter1;

	counter1 = 0;
	while (str[counter1] != '\0')
	{
		counter1++;
	}
	return (counter1);
}

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	int				counter1;
	unsigned int	len_dest;
	int				len_src;
	int				ret_val;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	ret_val = 0;
	if (size <= len_dest)
		ret_val = len_src + size;
	counter1 = 0;
	while (src[counter1] != '\0' && (len_dest + 1) < size)
	{
		dest[len_dest] = src[counter1];
		len_dest++;
		counter1++;
	}
	dest[len_dest] = '\0';
	return (ret_val);
}
/*
int main ()
{
	char str1[30]="ebesfgg";
	const char str2[30]="eceame";
	char str3[30]="ebesfgg";
	char str4[30]="eceame";
	unsigned int n_char;
	int ret1;
	int ret2;
	n_char = 8;
	printf ("str1 : %p  str2: %p\n",&str1,&str4);
	printf ("str1 : %s  str2: %s\n",str1,str4);
	
	ret2 = strlcat (str1,str2,4);
	printf ("str2: %d\n",ret2);
	ret1 = ft_strlcat (str3,str4,4);
	printf ("str1: %d\n",ret1);

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
