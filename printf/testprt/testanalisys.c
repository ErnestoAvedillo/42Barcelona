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

void testanalisys(void)
{
	int cont;

	cont =  0;
	printf("%s Test con str %s %s\n",KBLU, "<%s>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5s><%1s>", KNRM );
	cont = printf("<%5s><%1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5s><%-1s>", KNRM );
	cont = printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5s><%.1s>", KNRM );
	cont = printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);

/*	printf("%s Test 1 bonus %s %s\n",KGRN, "<% 5s><% 1s>", KNRM );
	cont = printf("<% s><% s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%#5s><%#1s>", KNRM );
	cont = printf("<%#5s><%#1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
*/
	printf("%s Test con char %s %s\n",KBLU, "<%c>", KNRM );
	printf("%s Test 2 bonus %s %s\n",KGRN, "<%5c><%1c>", KNRM );
	cont = printf("<%5c><%1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN, "<%-5c><%-1c>", KNRM );
	cont = printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test con int %s %s\n",KBLU, "<%d>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5d><%1d>", KNRM );
	cont = printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05d><%01d>", KNRM );
	cont = printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%+05d><%+01d>", KNRM );
	cont = printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5d><%-1d>", KNRM );
	cont = printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<% 5d><% 1d>", KNRM );
	cont = printf("<% 5d><% 1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5d><%.1d>", KNRM );
	cont = printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test con int %s %s\n",KBLU, "<%i>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5i><%1i>", KNRM );
	cont = printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05i><%01i>", KNRM );
	cont = printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%+05i><%+01i>", KNRM );
	cont = printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5i><%-1i>", KNRM );
	cont = printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<% 5i><% 1i>", KNRM );
	cont = printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5i><%.1i>", KNRM );
	cont = printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test con hex %s %s\n",KBLU, "<%x>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5x><%1x>", KNRM );
	cont = printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05x><%01x>", KNRM );
	cont = printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5x><%-1x>", KNRM );
	cont = printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5x><%.1x>", KNRM );
	cont = printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%#5x><%#1x>", KNRM );
	cont = printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test con addr %s %s\n",KBLU, "<%p>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5p><%1p>", KNRM );
	cont = printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);

/*	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05p><%01p>", KNRM );
	cont = printf("<%05p><%01p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);
*/
	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5p><%-1p>", KNRM );
	cont = printf("<%-5p><%-1p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);

/*	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5p><%.1p>", KNRM );
	cont = printf("<%.5p><%.1p>",(void *) 12,(void *) 42);
	printf ("respuesta ???printf %d\n", cont);
*/


/*	printf("%s Test 2 bonus %s %s\n",KGRN, "<%.5c><%.1c>", KNRM );
	cont = printf("<%.5c><%.1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN, "<% 5c><% 1c>", KNRM );
	cont = printf("<% 5c><% 1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN, "<%#5c><%#1c>", KNRM );
	cont = printf("<%#5c><%#1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);


	printf("%s Test 0 bis bonus %s\n",KGRN, KNRM );
	cont = printf("<%.2s><%.2s>", " - ", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.2s>", " - ", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.1s><%.2s><%.3s><%.4s>", " - ", "", "4", "");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.1s><%.2s><%.3s><%.4s>", " - ", "", "4", "");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", " - ", "", "4", "", "2 ");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", " - ", "", "4", "", "2 ");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "xxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "xxxx", "xxxxx", "xxxxx", "xxxxx", "xxxxx");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "x", "xx", "xx", "xx", "xx");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.2s><%.3s><%.4s><%.5s><%.1s>", "x", "xx", "xx", "xx", "xx");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.4d>", -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4d>", -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.4d>", 1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4d>", 1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s\n",KGRN, KNRM );
	cont = printf("<%-11u><%-12u>", LONG_MAX, LONG_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-11u><%-12u>", LONG_MAX, LONG_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.12d><%.12d>", INT_MAX, INT_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.12d><%.12d>", INT_MAX, INT_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s\n",KGRN, KNRM );
	cont = printf("<%.4d><%.4d>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.4d><%.4d>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s\n",KGRN, KNRM );
	cont = printf("<%#4x><%#4x>", -14, 14);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#4x><%#4x>", -14, 14);
	printf ("respuesta ft_printf %d\n", cont);
*/

}
