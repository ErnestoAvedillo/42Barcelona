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
	printf("%s Test 0 bonus %s\n",KGRN, KNRM );
	cont = printf("> %01d < \n", 0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %01d < \n", 0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s\n",KGRN, KNRM );
	cont = printf("> %01d < \n", -1 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %1d < \n", -1 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf("> %02d < \n", 9 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %02d < \n", 9 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s\n",KGRN, KNRM );
	cont = printf("> %02d < \n", -15 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %02d < \n", -15 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s\n",KGRN, KNRM );
	cont = printf("> %03d < \n", 95 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %03d < \n", 95 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s\n",KGRN, KNRM );
	cont = printf("> %04d < \n", -125 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %04d < \n", -125 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s\n",KGRN, KNRM );
	cont = printf("> %+d < \n", 960 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("> %+d < \n", 960 );
	printf ("respuesta ft_printf %d\n", cont);



}
