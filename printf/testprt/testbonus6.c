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

void bonustest6(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s %s\n",KGRN," %-1x ", KNRM );
	cont = printf(" %-1x ", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1x ", 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s %s\n",KGRN," %-2x ", KNRM );
	cont = printf(" %-2x ",   -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2x ",  -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN," %-4x ", KNRM );
	cont = printf(" %-4x ", 19);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4x ", 19);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN," %-3x ", KNRM );
	cont = printf(" %-3x ", 103);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3x ", 103);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN," %-6x ", KNRM );
	cont = printf(" %-6x ", -16);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-6x ", -16);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN," %-9x ", KNRM );
	cont = printf(" %-9x ", -101);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9x ", -101);
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 5 bonus %s %s\n",KGRN, KNRM );
	cont = printf(" %-11u %-12u ", LONG_MAX, LONG_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-11u %-12u ", LONG_MAX, LONG_MIN);
	printf ("respuesta ft_printf %d\n", cont);
*/
	printf("%s Test 6 bonus %s %s\n",KGRN," %-9x %-10x ", KNRM );
	cont = printf(" %-9x %-10x ", INT_MAX, INT_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9x %-10x ", INT_MAX, INT_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN," %-13x %-14x ", KNRM );
	cont = printf(" %-13x %-14x ", UINT_MAX, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-13x %-14x ", UINT_MAX, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s %s\n",KGRN," %-1x %-2x ",  KNRM );
	cont = printf(" %-1x %-2x ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1x %-2x ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN," %-4x $ %4x ", KNRM );
	cont = printf(" %-4x $ %4x ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4x $ %4x ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

}
