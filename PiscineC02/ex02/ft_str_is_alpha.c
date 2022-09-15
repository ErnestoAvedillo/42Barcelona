/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:21:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 21:34:45 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <string.h>

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!((*str >= 'A' && *str <= 'Z') \
			|| (*str >= 'a' && *str <= 'z')))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/*
int main ()
{
  char str1[]="Samplestring";
  char str2[]="Sample22 string";
  char ret1;
  char ret2;
  ret1 = ft_str_is_alpha (str1);
  ret2 = ft_str_is_alpha (str2);
  printf ("str 1 ret1: %d str 2 ret2: %d\n",ret1,ret2);
	return 0;
}
*/
