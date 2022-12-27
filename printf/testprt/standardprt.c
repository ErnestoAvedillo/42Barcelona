/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   standardprt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:32:24 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/12 19:32:31 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"test_lib.h"

void stdtest(void)
{
	int cont;
	unsigned int uval;

	printf("%s Test 0 impresion basica %s\n",KGRN, KNRM );
	printf ("Esto es una prueba de impresion BASICA\n");
	ft_printf("Esto es una prueba de impresion BASICA\n");

	printf("%s Test 1 impresion con argumento char %s\n",KGRN, KNRM );
	cont = printf ("Esto es una prueba de impresion ???printf %s", "mi prueba\n");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("Esto es una prueba de impresion ft_printf %s", "mi prueba\n");
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 impresion con argumento int %s\n",KGRN, KNRM );
	cont = printf ("???printf con d %d\n", 125);
	printf ("respuesta ft_printf %d\n", cont);

	cont = ft_printf ("ft_printf con i %i\n", 125);
	ft_printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 impresion con argumento unsigned int %s\n",KGRN, KNRM );
	uval = 4294967295;
	cont = printf ("   printf con u %u\n", uval);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("ft_printf con u %u\n", uval);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 impresion con argumento address %s\n",KGRN, KNRM );
	cont = printf ("   printf con p %p\n", &uval);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("ft_printf con p %p\n", &uval);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 5 impresion con argumento hexadecimal %s\n",KGRN, KNRM );
	uval = 4294967295;
	cont = printf ("   printf con x %x\n", uval);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("ft_printf con x %x\n", uval);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 6 impresion con argumento hexadecimal %s\n",KGRN, KNRM );
	uval = 4294967295;
	cont = printf ("   printf con X %X\n", uval);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("ft_printf con X %X\n", uval);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 impresion con varios argumentos %s\n",KGRN, KNRM );
	uval = 4294967295;
	cont = printf ("   printf con varios argumentos %d -- %p\n", uval, &cont);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("ft_printf con varios argumentos %d -- %p\n", uval, &cont);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 impresion con no printable %s\n",KGRN, KNRM );
	uval = 4294967295;
	cont = printf ("%s???printf con no printable%s \n",KGRN, KNRM);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%sft_printf con no printable%s \n",KGRN, KNRM);
	printf ("respuesta ft_printf %d\n", cont);

	return;
}