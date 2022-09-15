/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 12:23:11 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/27 21:10:55 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)

{
	int	counter;

	counter = 0;
	while (s1[counter] != '\0')
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
	char str1[20] = "Aedesfgg";
	char str2[20] = "Zettetme";
	const char str3[20] = "Aedesfgg";
	const char str4[20] = "Zettetme";
	unsigned int n_char;
	int ret1;
	int ret2;

	n_char = 1;
	printf("Comparar A y Z: %d\n", strcmp("B", "Z"));
	printf("Comparar Z y A: %d\n", strcmp("Z", "B"));
	printf("Comparar A y Z: %d\n", ft_strcmp("B", "Z"));
	printf("Comparar Z y A: %d\n", ft_strcmp("Z", "B"));
	printf("Comparar A y A: %d\n", strcmp("A", "A"));
	printf("Comparar A y A: %d\n", ft_strcmp("A", "A"));
	n_char = 5;
	ret1 = 0;
	ret2 = 0;
	ret1 = ft_strcmp (str1,str2);
	ret2 = strcmp (str3,str4);
	printf ("ret1 : %d  ret2: %d\n",ret1,ret2);
	ret1 = ft_strcmp (str1,str1);
	ret2 = strcmp (str3,str3);
	printf ("ret1 : %d  ret2: %d\n",ret1,ret2);
	ret1 = ft_strcmp (str2,str1);
	ret2 = strcmp (str4,str3);
	printf ("ret1 : %d  ret2: %d\n",ret1,ret2);
	return 0;
}
*/
