/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:30:51 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/27 21:40:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	counter1;
	int	counter2;

	if (to_find[0] == '\0')
		return (str);
	counter1 = 0;
	while (str[counter1] != '\0' && to_find[0] != '\0')
	{
		counter2 = 0;
		while (str[counter1 + counter2] == to_find[counter2])
		{
			if (to_find[counter2 + 1] == '\0')
				return (&str[counter1]);
			counter2++;
		}
		counter1++;
	}
	if (str[counter1] == '\0')
		return (0);
	return (str + counter1);
}
/*
int main ()
{
	const char str1[30]="ebecfgg";
	const char str2[30]="ec";
	char str3[30]="ebecfgg";
	char str4[30]="ec";
	const char str5[30]="";
	char str6[30]="";
	const char str7[30]="hh";
	char str8[30]="hh";
	unsigned int n_char;
	char *ret1;
	char *ret2;
	n_char = 1;
	printf ("str1 : %p  str2: %p\n",&str1,&str3);
	printf ("str1 : %s  str2: %s\n",str1,str2);
	
	ret2 = strstr (str1,str2);
	printf ("str2: %p\n",ret2);
	ret1 = ft_strstr (str3,str4);
	printf ("str1: %p\n",ret1);

	
	printf ("str1 : %p  str2: %p\n",&str1,&str3);
	printf ("str1 : %s  str2: %s\n",str1,str5);
	ret2 = strstr (str1,str5);
	printf ("str2: %p\n",ret2);
	ret1 = ft_strstr (str3,str6);
	printf ("str1: %p\n",ret1);

	printf ("str1 : %p  str2: %p\n",&str1,&str3);
	printf ("str1 : %s  str2: %s\n",str1,str7);
	ret2 = strstr (str1,str7);
	printf ("str2: %p\n",ret2);
	ret1 = ft_strstr (str3,str8);
	printf ("str1: %p\n",ret1);

	return 0;
}
*/
