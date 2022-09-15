/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:33:56 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/27 21:08:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (s1[counter] != '\0' && counter < n)
	{
		if (s1[counter] != s2[counter])
			return (s1[counter] - s2[counter]);
		counter++;
	}
	return (0);
}
/*
int main ()
{
	char str1[7]="eeesfgg";
	char str2[6]="eeeame";
	char str3[7]="eeesfgg";
	char str4[6]="eeetme";
	int n_char;
	int ret1;
	int ret2;

	n_char = 5;
	printf("Comparar A y Z: %d\n", strncmp("A", "Z",n_char));
	printf("Comparar Z y A: %d\n", strncmp("Z", "A",n_char));
	printf("Comparar A y A: %d\n", strncmp("A", "A",n_char));
	printf("Comparar A y A: %d\n", ft_strncmp("A", "A",n_char));
	ret1 = 0;
	ret2 = 0;
	ret1 = ft_strncmp (str1,str2,n_char);
	ret2 = strncmp (str1,str2,n_char);
	printf ("ret1 : %d  ret2: %d\n",ret1,ret2);
	ret1 = ft_strncmp (str1,str3,n_char);
	ret2 = strncmp (str1,str3,n_char);
	printf ("ret1 : %d  ret2: %d\n",ret1,ret2);
	ret1 = ft_strncmp (str1,str4,n_char);
	ret2 = strncmp (str1,str4,n_char);
	printf ("ret1 : %d  ret2: %d\n",ret1,ret2);
	ret1 = ft_strncmp (str4,str1,n_char);
	ret2 = strncmp (str4,str1,n_char);
	return 0;
}
*/
