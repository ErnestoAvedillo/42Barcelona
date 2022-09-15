/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:24:11 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/22 16:43:29 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_str_is_printable(char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 127))
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
  char str2[]="▬1243423ing";
  char ret1;
  char ret2;
  ret1 = ft_str_is_printable (str1);
  ret2 = ft_str_is_printable (str2);
  printf ("str 1 ret1: %d str 2 ret2: %d\n",ret1,ret2);
	return 0;
}*/
