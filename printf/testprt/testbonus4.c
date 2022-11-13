/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testbonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:24:46 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 18:24:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "test_lib.h"

void bonustest4(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s %s\n",KGRN," %2p ", KNRM );
	cont = printf(" %2p ", (void *) -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %2p ", (void *)  -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s %s\n",KGRN," %-2p ", KNRM );
	cont = printf(" %-2p ", (void *)  -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2p ", (void *)  -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN," %2p ", KNRM );
	cont = printf(" %2p ", (void *)  1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %2p ", (void *)  1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN," %-2p ", KNRM );
	cont = printf(" %-2p ", (void *)  15);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2p ", (void *)  15);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN," %-3p ", KNRM );
	cont = printf(" %-3p ", (void *)  16);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3p ", (void *)  16);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN," %-4p ", KNRM );
	cont = printf(" %-4p ", (void *)  17);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4p ", (void *)  17);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s %s\n",KGRN," %-9p %-10p ", KNRM );
	cont = printf(" %-9p %-10p ", (void *)  LONG_MIN, (void *)  LONG_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9p %-10p ", (void *)  LONG_MIN, (void *)  LONG_MAX);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s %s\n",KGRN," %-11p %-12p ", KNRM );
	cont = printf(" %-11p %-12p ", (void *)  INT_MIN, (void *)  INT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-11p %-12p ", (void *)  INT_MIN, (void *)  INT_MAX);
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 7 bonus %s %s\n",KGRN, KNRM );
	cont = printf(" %-13p %-14p ", (void *)  ULONG_MAX, - (void *) ULONG_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-13p %-14p ", (void *)  ULONG_MAX, - (void *) ULONG_MAX);
	printf ("respuesta ft_printf %d\n", cont);
*/
	printf("%s Test 8 bonus %s %s\n",KGRN," %-1p %-2p ", KNRM );
	cont = printf(" %-1p %-2p ",  (void *) 0, (void *)  0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1p %-2p ", (void *)  0, (void *)  0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN," %-4p $ %4p ", KNRM );
	cont = printf(" %-4p $ %4p ",  (void *) 0, (void *)  0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4p $ %4p ", (void *)  0, (void *)  0);
	printf ("respuesta ft_printf %d\n", cont);


}
