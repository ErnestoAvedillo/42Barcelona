/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specialtest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:57:28 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 11:57:35 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"test_lib.h"

void spectest(void)
{
	int cont;

	cont  = 0;
	printf("%s Test 0 str NULL %s\n",KGRN, KNRM );
	cont = printf(" NULL %s NULL ",(char *)NULL );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (" NULL %s NULL ",(char *)NULL );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 imprime 0 en formato %%p %s\n",KGRN, KNRM );
	cont = printf(" %p -- %p ",(void *) 0, (void *) 0 );
	printf ("respuesta ???printf %d\n", cont);
//preguntar que espera el paco que salga
	cont = ft_printf (" %p -- %p ", (void *) 0, (void *) 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 0 n formato x %s\n",KGRN, KNRM );
	cont = printf(" %x ",0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (" %x ",0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2A 42 n formato x %s\n",KGRN, KNRM );
	cont = printf(" %x ",42 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (" %x ",42 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 test de %% %s\n",KGRN, KNRM );
	cont = printf("A%%A " );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf ("A%%A " );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 test de %%%% %s\n",KGRN, KNRM );
	cont = printf("A%%%%A " );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf ("A%%%%A " );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6A test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% ",'A', "42", 42, 42 ,42 , 42, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% ",'A', "42", 42, 42 ,42 , 42, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6B test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% ", 'B', "-42", -42, -42 ,-42 ,-42, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% ", 'B', "-42", -42, -42 ,-42 ,-42, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6C test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%% ",'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%% ",'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6D test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%"\
		, 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%"\
		, 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 formato c %s\n",KGRN, KNRM );
	cont = printf(">%c %c %c< ",'4', 4, '1' );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (">%c %c %c< ",'4', 4, '1' );
	printf ("respuesta ft_printf %d\n", cont);

}