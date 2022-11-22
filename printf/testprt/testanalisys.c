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
	cont = ft_printf("<%5s><%1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5s><%-1s>", KNRM );
	cont = printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5s><%.1s>", KNRM );
	cont = printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5.s><%1.s>", KNRM );
	cont = printf("<%5.s><%1.s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.s><%1.s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5.5s><%1.1s>", KNRM );
	cont = printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5.5s><%1.1s>", KNRM );
	cont = printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5.50s><%1.10s>", KNRM );
	cont = printf("<%5.50s><%1.10s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.50s><%1.10s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%50.5s><%10.1s>", KNRM );
	cont = printf("<%50.5s><%10.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%50.5s><%10.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 1 bonus %s %s\n",KGRN, "<%*.*s><%*.*s>", KNRM );
	cont = printf("<%*.*s><%*.*s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*s><%*.*s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<% 5s><% 1s>", KNRM );
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
	cont = ft_printf("<%5c><%1c>", 'X', '-');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN, "<%-5c><%-1c>", KNRM );
	cont = printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con int %s %s\n",KBLU, "<%d>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5d><%1d>", KNRM );
	cont = printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05d><%01d>", KNRM );
	cont = printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%+05d><%+01d>", KNRM );
	cont = printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5d><%-1d>", KNRM );
	cont = printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<% 5d><% 1d>", KNRM );
	cont = printf("<% 5d><% d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% 5d><% 2d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5d><%.1d>", KNRM );
	cont = printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5.5d><%1.1d>", KNRM );
	cont = printf("<%5.5d><%1.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5d><%1.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5.50d><%1.10d>", KNRM );
	cont = printf("<%5.50d><%1.10d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.50d><%1.10d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%50.5d><%10.1d>", KNRM );
	cont = printf("<%50.5d><%10.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%50.5d><%10.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con int %s %s\n",KBLU, "<%i>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5i><%1i>", KNRM );
	cont = printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05i><%01i>", KNRM );
	cont = printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%+05i><%+01i>", KNRM );
	cont = printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5i><%-1i>", KNRM );
	cont = printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<% 5i><% 1i>", KNRM );
	cont = printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5i><%.1i>", KNRM );
	cont = printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con hex %s %s\n",KBLU, "<%x>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5x><%1x>", KNRM );
	cont = printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05x><%01x>", KNRM );
	cont = printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5x><%-1x>", KNRM );
	cont = printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5x><%.1x>", KNRM );
	cont = printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN, "<%#5x><%#1x>", KNRM );
	cont = printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con addr %s %s\n",KBLU, "<%p>", KNRM );
	printf("%s Test 0 bonus %s %s\n",KGRN, "<%5p><%1p>", KNRM );
	cont = printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 0 bonus %s %s\n",KGRN, "<%05p><%01p>", KNRM );
	cont = printf("<%05p><%01p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);
*/
/*	printf("%s Test 1 bonus %s %s\n",KGRN, "<%-5p><%-1p>", KNRM );
	cont = printf("<%-5p><%-1p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5p><%-1p>",(void *) 12,(void *) 43);
	printf ("respuesta ft_printf %d\n", cont);
*/
/*	printf("%s Test 1 bonus %s %s\n",KGRN, "<%.5p><%.1p>", KNRM );
	cont = printf("<%.5p><%.1p>",(void *) 12,(void *) 42);
	printf ("respuesta ???printf %d\n", cont);
*/


}
