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

	printf("%s Test 10 bonus %s %s\n",KGRN," %-8.5x $ %8.5x ", KNRM );
	cont = printf(" %-8.5x $ %8.5x ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-8.5x $ %8.5x ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN,"^.^/%#42.42x^.^/", KNRM );
	cont = printf("^.^/%#42.42x^.^/",  -2029487914);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#42.42x^.^/", -2029487914);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN,"^.^/%#x^.^/", KNRM );
	cont = printf("^.^/%#x^.^/",  -2029487914);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#x^.^/", -2029487914);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN,"^.^/%#x^.^/", KNRM );
	cont = printf("^.^/%#x^.^/",  0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#x^.^/", 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN,"^.^/%#x^.^/", KNRM );
	cont = printf("^.^/%#x^.^/",  9);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#x^.^/", 9);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s %s\n",KGRN," %#x %#x ", KNRM );
	cont = printf(" %#x %#x ", INT_MAX, INT_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %#x %#x ", INT_MAX, INT_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN," %#x %#x ", KNRM );
	cont = printf(" %#x %#x ", UINT_MAX, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %#x %#x ", UINT_MAX, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN," %#x %#x ", KNRM );
	cont = printf(" %#lx %#x ", LONG_MIN, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %#x %#x ", LONG_MIN, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,">------------<%#9.2x>------------<", KNRM );
	cont = printf(">------------<%#9.2x>------------<", -1827643996);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(">------------<%#9.2x>------------<", -1827643996);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%#9.2x>", KNRM );
	cont = printf("<%#9.2x>", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#9.2x>", 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#20.4x^.^/", KNRM );
	cont = printf("^.^/%#20.4x^.^/", 19162350);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#20.4x^.^/", 19162350);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#20.10x^.^/", KNRM );
	cont = printf("^.^/%#20.10x^.^/", 19162350);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#20.10x^.^/", 19162350);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"\\!/%#40.24x\\!/", KNRM );
	cont = printf("\\!/%#40.24x\\!/", -1827643996);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/%#40.24x\\!/", -1827643996);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#20x^.^/", KNRM );
	cont = printf("^.^/%#20x^.^/", 19162350);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#20x^.^/", 19162350);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%-#9.2x>", KNRM );
	cont = printf("<%-#9.2x>", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-#9.2x>", 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%0#20x^.^/", KNRM );
	cont = printf("^.^/%0#20x^.^/", 19162350);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%0#20x^.^/", 19162350);
	printf ("respuesta ft_printf %d\n", cont);
 
	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#42.9x^.^/", KNRM );
	cont = printf("^.^/%#42.10x^.^/", 1669661377);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#42.10x^.^/", 1669661377);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#16.10x^.^/", KNRM );
	cont = printf("^.^/%0#16.10x^.^/", -1069367408);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%0#16.10x^.^/", -1069367408);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#16.10x^.^/", KNRM );
	cont = printf("^.^/%#-16.10x^.^/", -1069367408);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#-16.10x^.^/", -1069367408);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#16.10x^.^/", KNRM );
	cont = printf("^.^/%#-16.7x^.^/", -1069367408);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#-16.7x^.^/", -1069367408);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#32.8x^.^/", KNRM );
	cont = printf("^.^/%#32.8x^.^/", 170057286);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("^.^/%#32.8x^.^/", 170057286);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"^.^/%#32.8x^.^/", KNRM );
	cont = printf("42%-#61.8x42", 59253329);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42%-#61.8x42", 59253329);
	printf ("respuesta ft_printf %d\n", cont);




}
