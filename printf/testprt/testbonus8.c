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

void bonustest8(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s %s\n",KGRN,"<%.4s><%.1s>", KNRM );
	cont = printf("<%.4s><%.1s>", "", "-");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4s><%.1s>", "", "-");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s %s\n",KGRN,"<%.2s><%.2s>", KNRM );
	cont = printf("<%.2s><%.2s>", " - ", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.2s>", " - ", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN,"<%.1s><%.2s><%.3s><%.4s>", KNRM );
	cont = printf("<%.1s><%.2s><%.3s><%.4s>", " - ", "", "4", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.1s><%.2s><%.3s><%.4s>", " - ", "", "4", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN,"<%.2s><%.3s><%.4s><%.5s><%.1s>", KNRM );
	cont = printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", " - ", "", "4", "", "2 ");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", " - ", "", "4", "", "2 ");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN,"<%.2s><%.3s><%.4s><%.5s><%.1s>", KNRM );
	cont = printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "xxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "xxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN,"<%.2s><%.3s><%.4s><%.5s><%.1s>", KNRM );
	cont = printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "x", "xx", "xx", "xx", "xx");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "x", "xx", "xx", "xx", "xx");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN,"<%.4d>", KNRM );
	cont = printf("<%.4d>", -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4d>", -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN,"<%.4d>", KNRM );
	cont = printf("<%.4d>", 1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4d>", 1);
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 5 bonus %s %s\n",KGRN, KNRM );
	cont = printf("<%-11u><%-12u>", LONG_MAX, LONG_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-11u><%-12u>", LONG_MAX, LONG_MIN);
	printf ("respuesta ft_printf %d\n", cont);
*/
	printf("%s Test 6 bonus %s %s\n",KGRN,"<%.12d><%.12d>", KNRM );
	cont = printf("<%.12d><%.12d>", INT_MAX, INT_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.12d><%.12d>", INT_MAX, INT_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%.4d><%.4d>", KNRM );
	cont = printf("<%.4d><%.4d>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4d><%.4d>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%#4x><%#4x>", KNRM );
	cont = printf("<%#4x><%#4x>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#4x><%#4x>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%#4X><%#4X>", KNRM );
	cont = printf("<%#4X><%#4X>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#4X><%#4X>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%#x><%#x>", KNRM );
	cont = printf("<%#x><%#x>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#x><%#x>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%#X><%#X>", KNRM );
	cont = printf("<%#X><%#X>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#X><%#X>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN,"<%4x><%4x>", KNRM );
	cont = printf("<%4x><%4x>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%4x><%4x>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);


}
