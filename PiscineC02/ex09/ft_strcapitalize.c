/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:25:56 by eavedill          #+#    #+#             */
/*   Updated: 2022/07/28 19:10:43 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	verif_prev_char(char c)
{
	if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	counter;
	int	to_change;

	to_change = 1;
	counter = 0;
	while (str[counter] != '\0')
	{
		if ((str[counter] >= 'A' && str[counter] <= 'Z'))
			str[counter] += 32;
		counter++;
	}
	counter = 0;
	while (str[counter] != '\0')
	{
		if ((str[counter] >= 'a' && str[counter] <= 'z') && to_change == 1)
		{
			str[counter] -= 32;
		}
		to_change = verif_prev_char(str[counter]);
		counter++;
	}
	return (str);
}
/*
int main ()
{
	char str1[]="P08N'[z,Q.Ig)OR5fu*@7%*	KDGn";
	char str2[]="Y5i64UOc]A*kf&PX9`ogz1W%A@)q~M :S>iqx/@bla";
	char *ret1;
	char *ret2;
	printf ("str1 : %s\n",str1);
	printf ("str2 : %s\n",str2);
	ret1 = ft_strcapitalize (str1);
	ret2 = ft_strcapitalize (str2);
	printf ("%s\n","P08n'[Z,Q.Ig)Or5fu*@7%*	Kdg");
	printf ("%s\n",ret1);
	printf ("%s\n","Y5i64uoc]A*Kf&Px9`Ogz1w%A@)Q~M :S>Iqx/@Bl");
	printf ("%s\n",ret2);
	return 0;
}
*/
