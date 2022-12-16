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

void bonustest(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s %s\n",KGRN,"> %+d <", KNRM );
	cont = printf("> %+d < \n", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "> %+d <", KNRM );
	cont = printf("> %+d < \n", -1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", -1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN, "> %+d <", KNRM );
	cont = printf("> %+d < \n", 9 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", 9 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN, "> %+d <", KNRM );
	cont = printf("> %+d < \n", -15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", -15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN,"> %+d <", KNRM );
	cont = printf("> %+d < \n", 95 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", 95 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s %s\n",KGRN,"> %+d <", KNRM );
	cont = printf("> %+d < \n", -125 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", -125 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s %s\n",KGRN,"> %+d <", KNRM );
	cont = printf("> %+d < \n", 960 );
	printf ("respuesta ???printf %d\n",cont);
	cont = ft_printf("> %+d < \n", 960 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s %s\n",KGRN,"> %-1d <", KNRM );
	cont = printf("> %-1d <", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %-1d <", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN,"> %-4d <", KNRM );
	cont = printf("> %-4d <", 16 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %-4d <", 16 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN,"> %-5d <", KNRM );
	cont = printf("< %-5d <", -15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-5d <", -15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 11 bonus %s %s\n",KGRN,"> %-9d <", KNRM );
	cont = printf("< %-9d >", INT_MAX );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-9d >", INT_MAX );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 12 bonus %s %s\n",KGRN,"> %-12d <", KNRM );
	cont = printf("< %-12d >", INT_MIN );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-12d >", INT_MIN );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 13 bonus %s %s\n",KGRN,"> %-7d <", KNRM );
	cont = printf("< %7d >", -14 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %7d >", -14 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 14 bonus %s %s\n",KGRN,"> %-8.5d <", KNRM );
	cont = printf("< %-8.5d >", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-8.5d >", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"> %+5d <", KNRM );
	cont = printf("< %+5d >", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %+5d >", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 16 bonus %s %s\n",KGRN,"> %+5d <", KNRM );
	cont = printf("< %+5d >", 1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %+5d >", 1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 17 bonus %s %s\n",KGRN,"> %05d <", KNRM );
	cont = printf("< %05d >", 1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %05d >", 1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 18 bonus %s %s\n",KGRN,"> %05d <", KNRM );
	cont = printf("< %05d >", -1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %05d >", -1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 19 bonus %s %s\n",KGRN,"> %5.d <", KNRM );
	cont = printf("< %5.d >", 1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %5.d >", 1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 20 bonus %s %s\n",KGRN,"> %5.d <", KNRM );
	cont = printf("< %5.d >", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %5.d >", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 21 bonus %s %s\n",KGRN,"> %-9.5d <", KNRM );
	cont = printf("< %-9.5d >", -2 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-9.5d >", -2 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 22 bonus %s %s\n",KGRN,"> %-3.7d <", KNRM );
	cont = printf("< %-3.7d >", -235 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-3.7d >", -235 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 21 bonus %s %s\n",KGRN,"> %-9.5d <", KNRM );
	cont = printf("< %-9.5d >", 2 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-9.5d >", 2 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 22 bonus %s %s\n",KGRN,"> %-3.7d <", KNRM );
	cont = printf("< %-3.7d >", 235 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-3.7d >", 235 );
	printf ("respuesta ft_printf %d\n", cont);



}
