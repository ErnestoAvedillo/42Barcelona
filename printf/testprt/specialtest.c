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

#include"../entrega/ft_printf.h"
#include"test_lib.h"

void spectest(void)
{
	int cont;

	cont  = 0;
	printf("%s Test 0 str NULL %s\n",KGRN, KNRM );
	//cont = printf(" NULL %s NULL \n",(char *)NULL );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (" NULL %s NULL \n",(char *)NULL );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 imprime 0 en formato %%p %s\n",KGRN, KNRM );
//	cont = printf(" %p -- %p \n",0 ,0 );
	printf ("respuesta ???printf %d\n", cont);
//preguntar que espera el paco que salga
	cont = ft_printf (" %p -- %p \n", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 0 n formato x %s\n",KGRN, KNRM );
	cont = printf(" %x \n",0 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (" %x \n",0 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2A 42 n formato x %s\n",KGRN, KNRM );
	cont = printf(" %x \n",42 );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (" %x \n",42 );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 test de %% %s\n",KGRN, KNRM );
	cont = printf("A%%A\n" );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf ("A%%A\n" );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 test de %%%% %s\n",KGRN, KNRM );
	cont = printf("A%%%%A\n" );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf ("A%%%%A\n" );
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6A test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n",'A', "42", 42, 42 ,42 , 42, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n",'A', "42", 42, 42 ,42 , 42, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6B test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6C test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n",'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n",'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6D test variado %s\n",KGRN, KNRM );
	cont = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%"\
		, 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%"\
		, 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 formato c %s\n",KGRN, KNRM );
	cont = printf(">%c %c %c< \n",'4', 4, '1' );
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf (">%c %c %c< \n",'4', 4, '1' );
	printf ("respuesta ft_printf %d\n", cont);

}