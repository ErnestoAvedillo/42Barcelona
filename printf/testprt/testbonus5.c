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

void bonustest5(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1u ", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1u ", 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s\n",KGRN, KNRM );
	cont = printf(" %-2u ",   -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2u ",  -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-4u ", 19);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4u ", 19);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-3u ", 103);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3u ", 103);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-6u ", -16);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-6u ", -16);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-9u ", -101);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9u ", -101);
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 5 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-11u %-12u ", LONG_MAX, LONG_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-11u %-12u ", LONG_MAX, LONG_MIN);
	printf ("respuesta ft_printf %d\n", cont);
*/
	printf("%s Test 6 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-9u %-10u ", INT_MAX, INT_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9u %-10u ", INT_MAX, INT_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-13u %-14u ", UINT_MAX, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-13u %-14u ", UINT_MAX, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1u %-2u ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1u %-2u ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-4u $ %4u ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4u $ %4u ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

}
