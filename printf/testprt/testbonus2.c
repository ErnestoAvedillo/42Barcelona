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
	printf("%s Test 0 bonus %s %s\n",KGRN,"%-1c", KNRM );
	cont = printf("%-1c", '0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-1c", '0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s %s\n",KGRN,"%1c", KNRM );
	cont = printf("%1c", '0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%1c", '0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN,"%-2c", KNRM );
	cont = printf(" %-2c ", '0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2c ", '0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN,"%-3c", KNRM );
	cont = printf(" %-3c", '0' - 256);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3c", '0' - 256);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN,"%-4c", KNRM );
	cont = printf("%-4c ", '0' + 256);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-4c ", '0' + 256);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN,"< %-1c >< %-2c >< %-3c >", KNRM );
	cont = printf("< %-1c >< %-2c >< %-3c >", '0', 0, '1');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c >< %-2c >< %-3c >", '0', 0, '1');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s %s\n",KGRN,"< %-1c >< %-2c >< %-3c >", KNRM );
	cont = printf("< %-1c >< %-2c >< %-3c >", ' ', ' ', ' ');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c >< %-2c >< %-3c >", ' ', ' ', ' ');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s %s\n",KGRN,"< %-1c >< %-2c >< %-3c >", KNRM );
	cont = printf("< %-1c >< %-2c >< %-3c >", '1', '2', '3');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c >< %-2c >< %-3c >", '1', '2', '3');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"< %-1c >< %-2c >< %-3c >", KNRM );
	cont = printf("< %-1c >< %-2c >< %-3c >", '2', '1', 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c >< %-2c >< %-3c >", '2', '1', 0);
	printf ("respuesta ft_printf %d\n", cont);


	printf("%s Test 8 bonus %s %s\n",KGRN,"< %-1c >< %-2c >< %-3c >", KNRM );
	cont = printf("< %-1c >< %-2c >< %-3c >", 0, '1', '2');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c >< %-2c >< %-3c >", 0, '1', '2');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN, "<%-5c%>", KNRM );
	cont = printf("<%-5c>", '\0');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5c>", '\0');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN, "<%3c%>", KNRM );
	cont = printf("{%3c}", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("{%3c}", 0);
	printf ("respuesta ft_printf %d\n", cont);
/*
	printf("%s Test 10 bonus %s %s\n",KGRN, "<%1.c>", KNRM );
	cont = printf("{%1.c}", 'a');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("{%1.c}", 'a');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN, "<%5.c>", KNRM );
	cont = printf("{%5.c}", 'a');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("{%5.c}", 'a');
	printf ("respuesta ft_printf %d\n", cont);
*/
	printf("%s Test 10 bonus %s %s\n",KGRN, "<%5c>", KNRM );
	cont = printf("{%5c}", 'a');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("{%5c}", 'a');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 12 bonus %s %s\n",KGRN, "<%5c>", KNRM );
	cont = printf("!%59c!", (char)0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("!%59c!", (char)0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 12 bonus %s %s\n",KGRN, "<%1c, %1c, %1c>", KNRM );
	cont = printf("<%1c, %1c, %1c>", '5', 'x', '\n');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%1c, %1c, %1c>", '5', 'x', '\n');
	
	printf ("respuesta ft_printf %d\n", cont);
	printf("%s Test 12 bonus %s %s\n",KGRN, "42%12c42", KNRM );
	cont = printf("42%12c42", (char)0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42%12c42", (char)0);
	printf ("respuesta ft_printf %d\n", cont);

	printf ("respuesta ft_printf %d\n", cont);
	printf("%s Test 12 bonus %s %s\n",KGRN, "42%-c42", KNRM );
	cont = printf("42%-c42", (char)0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42%-c42", (char)0);
	printf ("respuesta ft_printf %d\n", cont);


}
