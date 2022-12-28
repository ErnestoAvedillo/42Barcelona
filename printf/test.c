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
	if (av == 1 || is_func(ac,"analysis")) 
		testanalisys();
	if (av == 1 || is_func(ac, "standard") ||is_func(ac, "onlyman"))
		stdtest();
	if (av == 1 || is_func(ac, "special") || is_func(ac, "onlyman"))
		spectest();
	if (av == 1 || is_func(ac, "strict") || is_func(ac, "onlyman"))
		stricttest();
	if (av == 1 || is_func(ac,"bonus0")) 
		bonustest();
	if (av == 1 || is_func(ac,"bonus1")) 
		bonustest1();
	if (av == 1 || is_func(ac,"bonus2")) 
		bonustest2();
	if (av == 1 || is_func(ac,"bonus3")) 
		bonustest3();
	if (av == 1 || is_func(ac,"bonus4")) 
		bonustest4();
	if (av == 1 || is_func(ac,"bonus5")) 
		bonustest5();
	if (av == 1 || is_func(ac,"bonus6")) 
		bonustest6();
	if (av == 1 || is_func(ac,"bonus7")) 
		bonustest7();
	if (av == 1 || is_func(ac,"bonus8")) 
		bonustest8();
	if (is_func(ac,"-h")) 
		printhelp();

	return (0);
}
