/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stricttest.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:27:21 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/01 17:30:14 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"../entrega/ft_printf.h"
#include"test_lib.h"

void stricttest(void)
{
	int cont;

	cont = 0;
	printf("%stest 1 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("\001\n");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("\001\n");
	ft_printf("%d\n",cont );
	printf("%stest 2 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("\001\002\007\v\010\f\r\n");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("%d\n",cont );
	printf("%stest 3 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%%");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%");
	ft_printf("%d\n",cont );

}

