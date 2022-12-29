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
	int testnr;

	testnr = 1;
	cont =  0;
	printf("%s Test con str %s %s\n",KYEL, "<%s>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5s><%1s>", KNRM );
	cont = printf("<%5s><%1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5s><%1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%-5s><%-1s>", KNRM );
	cont = printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5s><%-1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%.5s><%.1s>", KNRM );
	cont = printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5s><%.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5.s><%1.s>", KNRM );
	cont = printf("<%5.s><%1.s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.s><%1.s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5.5s><%1.1s>", KNRM );
	cont = printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5.5s><%1.1s>", KNRM );
	cont = printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5s><%1.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5.50s><%1.10s>", KNRM );
	cont = printf("<%5.50s><%1.10s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.50s><%1.10s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%50.5s><%10.1s>", KNRM );
	cont = printf("<%50.5s><%10.1s>", "XXXX", "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%50.5s><%10.1s>", "XXXX", "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%*.*s>(5,1)<%*.*s>(10,1)", KNRM );
	cont = printf("<%*.*s><%*.*s>", 5,1, "XXXX", 10, 1, "----");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*s><%*.*s>",  5,1, "XXXX", 10, 1, "----");
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test con char %s %s\n",KYEL, "<%c>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5c><%1c>", KNRM );
	cont = printf("<%5c><%1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5c><%1c>", 'X', '-');
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%-5c><%-1c>", KNRM );
	cont = printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5c><%-1c>", 'X', '-');
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%-5c><%-1c>", KNRM );
	cont = printf("< %-1c %-2c %-3c >", '0', 0, '1');
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-1c %-2c %-3c >", '0', 0, '1');
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "42%50c42", KNRM );
	cont = printf("42%50c42", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("42%50c42", 0);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test con int %s %s\n",KYEL, "<%d>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5d><%1d>", KNRM );
	cont = printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5d><%1d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05d><%01d>", KNRM );
	cont = printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05d><%01d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%+05d><%+01d>", KNRM );
	cont = printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%+05d><%+01d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test 1%d6 bonus %s %s\n",KGRN, testnr, "<%-5d><%-1d>", KNRM );
	cont = printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5d><%-1d>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<% -5d><% -1d>", KNRM );
	cont = printf("<% -5d><% -2d>", -12, -43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% -5d><% -2d>", -12, -43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<% 5d><% 1d>", KNRM );
	cont = printf("<% 5d><% 2d>", -12, -43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% 5d><% 2d>", -12, -43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "\\!/% -2.20d\\!/", KNRM );
	cont = printf("\\!/% -2.20d\\!/",  -646891090 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("\\!/% -2.20d\\!/",  -646891090 );
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%.5d><%.1d>", KNRM );
	cont = printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5d><%.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5.5d><%1.1d>", KNRM );
	cont = printf("<%5.5d><%1.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.5d><%1.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5.50d><%1.10d>", KNRM );
	cont = printf("<%5.50d><%1.10d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5.50d><%1.10d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%50.5d><%10.1d>", KNRM );
	cont = printf("<%50.5d><%10.1d>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%50.5d><%10.1d>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%*.*d><%*.*d>", KNRM );
	cont = printf("<%*.*d><%*.*d>", 2,50,5, 42,1,1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*d><%*.*d>", 2,50,5, 42,1,1);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test con int %s %s\n",KYEL, "<%i>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5i><%1i>", KNRM );
	cont = printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5i><%1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05i><%01i>", KNRM );
	cont = printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05i><%01i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%+05i><%+01i>", KNRM );
	cont = printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%+05i><%+01i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%-5i><%-1i>", KNRM );
	cont = printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5i><%-1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<% 5i><% 1i>", KNRM );
	cont = printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<% 5i><% 1i>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%.5i><%.1i>", KNRM );
	cont = printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5i><%.1i>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test con hex %s %s\n",KYEL, "<%x>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5x><%1x>", KNRM );
	cont = printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5x><%1x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05x><%01x>", KNRM );
	cont = printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05x><%01x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%-5x><%-1x>", KNRM );
	cont = printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-5x><%-1x>", 12, 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%.5x><%.1x>", KNRM );
	cont = printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%.5x><%.1x>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%#5x><%#1x>", KNRM );
	cont = printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%#5x><%#1x>", 12, 42);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test con addr %s %s\n",KYEL, "<%p>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5p><%1p>", KNRM );
	cont = printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%5p><%1p>",(void *) 12,(void *) 43);
	printf ("respuesta ft_printf %d\n", cont);
	testnr++;

	printf("%s Test con %% %s %s\n",KYEL, "<%%XX%%>", KNRM );
	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05%>", KNRM );
	cont = printf("< %05% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %05% >");
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5%>", KNRM );
	cont = printf("< %-5% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %-5% >");
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%5%>", KNRM );
	cont = printf("< %5% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %5% >");
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%*.*s>,-10,20", KNRM );
	cont = printf("<%*.*s>",-10,20,"per");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*s>",-10,20,"per");
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%*d>,-10,20", KNRM );
	cont = printf("<%*d>",-10,20);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*d>",-10,20);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05%>", KNRM );
	cont = printf("< %05% >");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("< %05% >");
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "%-192.131%", KNRM );
	cont = printf("<%-192.131%>");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-192.131%>");
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05.*d>", KNRM );
	cont = printf("<%05.*d>",2,42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05.*d>",2,42);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05.*d>", KNRM );
	cont = printf("<%05.*d>",15,42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05.*d>",15,42);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%05.*d>", KNRM );
	cont = printf("<%05.*d>",-15,42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%05.*d>",-15,42);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%*.*d>,-10,20", KNRM );
	cont = printf("<%*.*d>",-10,20,15);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%*.*d>",-10,20,15);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "<%*.*d>,-10,20", KNRM );
	cont = printf("<%-10.20d>",15);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-10.20d>",15);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "%-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X", KNRM );
	cont = printf("%-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "%-#X, %-#X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X", KNRM );
	cont = printf("%-#X, %-#X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-#X, %-#X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X, %-#.0X", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "%-#.0X", KNRM );
	cont = printf("%-#.0X", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%-#.0X", 0);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "%#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x", KNRM );
	cont = printf("%#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x, %#1.0x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;

	printf("%s Test %d bonus %s %s\n",KGRN, testnr, "%#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x", KNRM );
	cont = printf("%#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x, %#5.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX);
	printf ("respuesta ???printf %d\n", cont);
	testnr++;


}
