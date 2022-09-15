/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:19:59 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/26 21:21:48 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
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
  ret1 = strcpy (str2,str1);
  ret2 = strcpy (str3,"copy successful");
  printf ("str1: %s copiado a str2: %s\nstr3: %s\n",str1,str2,str3);
  printf ("ret1: %s ret2: %s\n",ret1,ret2);
  printf ("ret1: %p ret2: %p\n",str2,str3);
  printf ("ret1: %p ret2: %p\n",ret1,ret2);

  ret1 = ft_strcpy (str2,str1);
  ret2 = ft_strcpy (str3,"copy successful");
  printf ("str1: %s copiado a str2: %s\nstr3: %s\n",str1,str2,str3);
  printf ("ret1: %s ret2: %s\n",ret1,ret2);
  printf ("ret1: %p ret2: %p\n",str2,str3);
  printf ("ret1: %p ret2: %p\n",ret1,ret2);
  return (0);
}
*/
