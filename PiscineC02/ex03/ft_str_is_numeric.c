/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:22:29 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/22 16:37:43 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_str_is_numeric(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= '0' && *str <= '9'))
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
  char str1[]="12334556";
  char str2[]="1243423ing";
  char ret1;
  char ret2;
  ret1 = ft_str_is_numeric (str1);
  ret2 = ft_str_is_numeric (str2);
  printf ("str 1 ret1: %d str 2 ret2: %d\n",ret1,ret2);
	return 0;
}
*/
