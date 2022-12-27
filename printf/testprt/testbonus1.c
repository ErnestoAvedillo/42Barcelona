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

void bonustest1(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s %s\n",KGRN,"> %01d <", KNRM );
	cont = printf("> %01d < \n", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %01d < \n", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN,"> %01d <", KNRM );
	cont = printf("> %01d < \n", -1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %1d < \n", -1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN,"> %03d <", KNRM );
	cont = printf("> %03d < \n", 9 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %03d < \n", 9 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN,"> %+04d <", KNRM );
	cont = printf("> %+04d < \n", -15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+04d < \n", -15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s %s\n",KGRN,"> %+04d <", KNRM );
	cont = printf("> %+04d < \n", 15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+04d < \n", 15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s %s\n",KGRN,"> %04d <", KNRM );
	cont = printf("> %04d < \n", 15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %04d < \n", 15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN,"> %04d <", KNRM );
	cont = printf("> %04d < \n", -15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %04d < \n", -15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN,"> %04d <", KNRM );
	cont = printf("> %04d < \n", -125 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %04d < \n", -125 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 11 bonus %s %s\n",KGRN,"> %+d <", KNRM );
	cont = printf("> %+d < \n", 960 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", 960 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 12 bonus %s %s\n",KGRN,"> %-2d <", KNRM );
	cont = printf("< %-2d >", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-2d >", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 13 bonus %s %s\n",KGRN,"> %-4d <", KNRM );
	cont = printf("< %-4d >", 16 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-4d >", 16 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 14 bonus %s %s\n",KGRN,"> %-5d <", KNRM );
	cont = printf("< %-5d >", -15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-5d >", -15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"> %-9d <", KNRM );
	cont = printf("< %-9d >", INT_MAX );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-9d >", INT_MAX );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"\\!/% -2.20d\\!/", KNRM );
	cont = printf("\\!/% -2.20d\\!/",  -646891090 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -2.20d\\!/",  -646891090 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"\\!/% -20.2d\\!/", KNRM );
	cont = printf("\\!/% -20.2d\\!/",  -646891090 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -20.2d\\!/",  -646891090 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"\\!/% -20.2d\\!/", KNRM );
	cont = printf("\\!/% -20.2d\\!/",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -20.2d\\!/",  0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"42%+16.26d42", KNRM );
	cont = printf("42%+16.26d42",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42%+16.26d42",  0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"42% 16.26d42", KNRM );
	cont = printf("42% 16.26d42",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42% 16.26d42",  0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"42% -16.26d42", KNRM );
	cont = printf("42% -16.26d42",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42% -16.26d42",  0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"42% 26.16d42", KNRM );
	cont = printf("42% 26.16d42",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42% 26.16d42",  0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"42% -26.16d42", KNRM );
	cont = printf("42% -26.16d42",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42% -26.16d42",  0 );
	printf ("respuesta ft_printf %d\n", cont);
	printf("1\n");

	printf("%s Test 15 bonus %s %s\n",KGRN,"% 015d", KNRM );
	cont = printf("% 015d",  0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("% 015d",  0 );
	printf ("respuesta ft_printf %d\n", cont);
	printf("1\n");
/*
	printf("%s Test 15 bonus %s %s\n",KGRN,"\\!/% 06.2d\\!/", KNRM );
	cont = printf("\\!/% 06.2d\\!/",  646891090 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 06.2d\\!/",  646891090 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"\\!/% 06.2d\\!/", KNRM );
	cont = printf("\\!/% 06.2d\\!/",  2 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 06.2d\\!/",  2 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN,"!% 02.36d!", KNRM );
	cont = printf("!% 02.36d!",  1598578416 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("!% 02.36d!",  1598578416 );
	printf ("respuesta ft_printf %d\n", cont);
*/
	cont = printf("\\!/% d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 1d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 1d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 2d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 2d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 4d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 4d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 4.1d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 4.1d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 1.4d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 1.4d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);

	cont = printf("\\!/% -d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% -1d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -1d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% -2d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -2d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% -4d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -4d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% -4.1d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -4.1d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% -1.4d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -1.4d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);

	cont = printf("\\!/% 0d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 0d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 01d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 01d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 02d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 02d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
	cont = printf("\\!/% 04d\\!/\n",  20 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 04d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
//	cont = printf("\\!/% 04.1d\\!/\n",  20 );
//	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 04.1d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);
//	cont = printf("\\!/% 01.4d\\!/\n",  20 );
//	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% 01.4d\\!/\n",  20 );
	printf ("respuesta ft_printf %d\n", cont);



}
