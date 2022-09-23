/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:14:47 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 20:03:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	counter;
	printf("entro -%s- %s- %d-\n",s1 , s2 , n );
	counter = 0;
	while (s1[counter] != '\0' && s2[counter] != '\0' && counter < n)
	{
		printf("%c %c\n",s1[counter], s2[counter] );
		if (s1[counter] != s2[counter])
			return (s1[counter] - s2[counter]);
		counter++;
	}
//	if ((s1[counter] != s2[counter]) && counter < n)
//		return (s1[counter] - s2[counter]);
	return (0);
}
