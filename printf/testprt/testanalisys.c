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
	printf("%s Test 1 bonus %s %s\n",KGRN, "<%5s><%1s>", KNRM );
	cont = printf("<%5s><%1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5s><%1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN, "<%-5s><%-1s>", KNRM );
	cont = printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN, "<%.5s><%.1s>", KNRM );
	cont = printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN, "<%5.s><%1.s>", KNRM );
	cont = printf("<%5.s><%1.s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.s><%1.s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 bonus %s %s\n",KGRN, "<%5.5s><%1.1s>", KNRM );
	cont = printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 bonus %s %s\n",KGRN, "<%5.5s><%1.1s>", KNRM );
	cont = printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN, "<%5.50s><%1.10s>", KNRM );
	cont = printf("<%5.50s><%1.10s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.50s><%1.10s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s %s\n",KGRN, "<%50.5s><%10.1s>", KNRM );
	cont = printf("<%50.5s><%10.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%50.5s><%10.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN, "<%*.*s>(5,1)<%*.*s>(10,1)", KNRM );
	cont = printf("<%*.*s><%*.*s>", 5,1, "XXXX", 10, 1, "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*s><%*.*s>",  5,1, "XXXX", 10, 1, "----");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con char %s %s\n",KBLU, "<%c>", KNRM );
	printf("%s Test 10 bonus %s %s\n",KGRN, "<%5c><%1c>", KNRM );
	cont = printf("<%5c><%1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5c><%1c>", 'X', '-');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 11 bonus %s %s\n",KGRN, "<%-5c><%-1c>", KNRM );
	cont = printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 12 bonus %s %s\n",KGRN, "<%-5c><%-1c>", KNRM );
	cont = printf("< %-1c %-2c %-3c >", '0', 0, '1');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c %-2c %-3c >", '0', 0, '1');
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con int %s %s\n",KBLU, "<%d>", KNRM );
	printf("%s Test 13 bonus %s %s\n",KGRN, "<%5d><%1d>", KNRM );
	cont = printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 14 bonus %s %s\n",KGRN, "<%05d><%01d>", KNRM );
	cont = printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 15 bonus %s %s\n",KGRN, "<%+05d><%+01d>", KNRM );
	cont = printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 16 bonus %s %s\n",KGRN, "<%-5d><%-1d>", KNRM );
	cont = printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 17 bonus %s %s\n",KGRN, "<% 5d><% 1d>", KNRM );
	cont = printf("<% 5d><% d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% 5d><% 2d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 18 bonus %s %s\n",KGRN, "<%.5d><%.1d>", KNRM );
	cont = printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 19 bonus %s %s\n",KGRN, "<%5.5d><%1.1d>", KNRM );
	cont = printf("<%5.5d><%1.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5d><%1.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 20 bonus %s %s\n",KGRN, "<%5.50d><%1.10d>", KNRM );
	cont = printf("<%5.50d><%1.10d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.50d><%1.10d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 21 bonus %s %s\n",KGRN, "<%50.5d><%10.1d>", KNRM );
	cont = printf("<%50.5d><%10.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%50.5d><%10.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 22 bonus %s %s\n",KGRN, "<%*.*d><%*.*d>", KNRM );
	cont = printf("<%*.*d><%*.*d>", 2,50,5, 42,1,1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*d><%*.*d>", 2,50,5, 42,1,1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con int %s %s\n",KBLU, "<%i>", KNRM );
	printf("%s Test 23 bonus %s %s\n",KGRN, "<%5i><%1i>", KNRM );
	cont = printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 24 bonus %s %s\n",KGRN, "<%05i><%01i>", KNRM );
	cont = printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 25 bonus %s %s\n",KGRN, "<%+05i><%+01i>", KNRM );
	cont = printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 26 bonus %s %s\n",KGRN, "<%-5i><%-1i>", KNRM );
	cont = printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 27 bonus %s %s\n",KGRN, "<% 5i><% 1i>", KNRM );
	cont = printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 28 bonus %s %s\n",KGRN, "<%.5i><%.1i>", KNRM );
	cont = printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con hex %s %s\n",KBLU, "<%x>", KNRM );
	printf("%s Test 29 bonus %s %s\n",KGRN, "<%5x><%1x>", KNRM );
	cont = printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 30 bonus %s %s\n",KGRN, "<%05x><%01x>", KNRM );
	cont = printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 31 bonus %s %s\n",KGRN, "<%-5x><%-1x>", KNRM );
	cont = printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 32 bonus %s %s\n",KGRN, "<%.5x><%.1x>", KNRM );
	cont = printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 33 bonus %s %s\n",KGRN, "<%#5x><%#1x>", KNRM );
	cont = printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con addr %s %s\n",KBLU, "<%p>", KNRM );
	printf("%s Test 34 bonus %s %s\n",KGRN, "<%5p><%1p>", KNRM );
	cont = printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test con %% %s %s\n",KBLU, "<%%XX%%>", KNRM );
	printf("%s Test 35 bonus %s %s\n",KGRN, "<%5%>", KNRM );
	cont = printf("< %05% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %05% >");
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 36 bonus %s %s\n",KGRN, "<%5%>", KNRM );
	cont = printf("< %-5% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-5% >");
	printf ("respuesta ???printf %d\n", cont);

	printf("%s Test 37 bonus %s %s\n",KGRN, "<%5%>", KNRM );
	cont = printf("< %5% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %5% >");
	printf ("respuesta ???printf %d\n", cont);


}
