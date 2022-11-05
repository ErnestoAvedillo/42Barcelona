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

void bonustest3(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s\n",KGRN, KNRM );
	cont = printf("%1s", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%1s", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s\n",KGRN, KNRM );
	cont = printf("%-1s", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-1s", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-2s ", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2s ", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-3s", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3s", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-s ", "-");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-s ", "-");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-1s %-2s ", "", "-");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1s %-2s ", "", "-");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-3s %-4s ", " - ", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3s %-4s ", " - ", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-2s %-3s %-4s %-5s ", " - ", "", "4", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2s %-3s %-4s %-5s ", " - ", "", "4", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3s %-3s %-4s %-5s %-3s ", " - ", "", "4", "", "2 ");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s\n",KGRN, KNRM );
	cont = printf(" %5s ", "2 ");
	printf ("respuesta ???printf %d\n (int) ft_strlen(prtstr)", cont);
	cont = ft_printf(" %5s ", "2 ");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s\n",KGRN, KNRM );
	cont = printf(" %-5s ", "2 ");
	printf ("respuesta ???printf %d\n (int) ft_strlen(prtstr)", cont);
	cont = ft_printf(" %-5s ", "2 ");
	printf ("respuesta ft_printf %d\n", cont);



}
