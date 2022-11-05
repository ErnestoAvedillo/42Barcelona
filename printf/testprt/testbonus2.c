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

void bonustest2(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s\n",KGRN, KNRM );
	cont = printf("%-1c", '0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-1c", '0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s\n",KGRN, KNRM );
	cont = printf("%1c", '0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%1c", '0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-2c ", '0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2c ", '0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-3c", '0' - 256);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3c", '0' - 256);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s\n",KGRN, KNRM );
	cont = printf("%-4c ", '0' + 256);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-4c ", '0' + 256);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1c %-2c %-3c ", '0', 0, '1');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1c %-2c %-3c ", ' ', ' ', ' ');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1c %-2c %-3c ", '1', '2', '3');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1c %-2c %-3c ", '1', '2', '3');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1c %-2c %-3c ", '2', '1', 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1c %-2c %-3c ", '2', '1', 0);
	printf ("respuesta ft_printf %d\n", cont);


	printf("%s Test 8 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1c %-2c %-3c ", 0, '1', '2');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1c %-2c %-3c ", 0, '1', '2');
	printf ("respuesta ft_printf %d\n", cont);



}
