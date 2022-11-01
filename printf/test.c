/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:53:52 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/07 09:55:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"test.h"

int is_func(char **ac, char *str)
{
	int i = 0;

	while (ac[i])
	{
		if (ft_strncmp(ac[i], str, ft_strlen(str)) == 0)
			return (1);
		i++;
	}
	return (0);
}

void printhelp (void)
{
	printf("USAGE\n");
	printf("-h: for this help\n");
	printf("standard: for the standard tests\n");
	printf("special: for the special tests\n");
	printf("strict: for the strict tests\n");
	printf("bonus: for the bonus tests\n");
}

int main (int av, char **ac)
{
	if (av == 1 || is_func(ac,"standard")) 
		stdtest();
	if (av == 1 || is_func(ac,"special")) 
		spectest();
	if (av == 1 || is_func(ac,"strict")) 
		stricttest();
	if (av == 1 || is_func(ac,"bonus")) 
		bonustest();
	if (is_func(ac,"-h")) 
		printhelp();

	return (0);
}
