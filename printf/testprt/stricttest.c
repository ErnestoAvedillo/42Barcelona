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
	cont =  printf("%%c");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%c");
	ft_printf("%d\n",cont );
	printf("%stest 4 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%%%%%%");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%%%%%");
	ft_printf("%d\n",cont );
	printf("%stest 5 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%%%c", 'x');
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%%c", 'x');
	ft_printf("%d\n",cont );
	printf("%stest 6 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf(" %c", 'x');
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf(" %c", 'x');
	ft_printf("%d\n",cont );
	printf("%stest 6 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%c ", 'x');
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%c ", 'x');
	ft_printf("%d\n",cont );
	printf("%stest 7 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%c%c%c", 'a', '\t', 'b');
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%c%c%c", 'a', '\t', 'b');
	ft_printf("%d\n",cont );
	printf("%stest 7 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%cs%cs%c", 'c', 'b', 'a');
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%cs%cs%c", 'c', 'b', 'a');
	ft_printf("%d\n",cont );
	printf("%stest 8 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s", "");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s", "");
	ft_printf("%d\n",cont );
	printf("%stest 9 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s", (char *)NULL);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s", (char *)NULL);
	ft_printf("%d\n",cont );
	printf("%stest 10 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s", "some string with %s hehe");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s", "some string with %s hehe");
	ft_printf("%d\n",cont );
	printf("%stest 11 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf(" %s", "can it handle \t and \n?");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf(" %s", "can it handle \t and \n?");
	ft_printf("%d\n",cont );
	printf("%stest 12 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
	ft_printf("%d\n",cont );
	printf("%stest 12 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s%s%s", "And ", "some", "joined");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s%s%s", "And ", "some", "joined");
	ft_printf("%d\n",cont );
	printf("%stest 13 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%ss%ss%ss", "And ", "some", "joined");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%ss%ss%ss", "And ", "some", "joined");
	ft_printf("%d\n",cont );
	printf("%stest 14 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%p", "");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%p", "");
	ft_printf("%d\n",cont );
	printf("%stest 15 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%p", NULL);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%p", NULL);
	ft_printf("%d\n",cont );
	printf("%stest 16 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%d", 0);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%d", 0);
	ft_printf("%d\n",cont );
	printf("%stest 17 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%i", 0);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%i", 0);
	ft_printf("%d\n",cont );
	printf("%stest 18 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%u", 0);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%u", 0);
	ft_printf("%d\n",cont );
	printf("%stest 19 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%x", 0);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%x", 0);
	ft_printf("%d\n",cont );
	printf("%stest 20 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%X", 0);
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%X", 0);
	ft_printf("%d\n",cont );
	printf("%stest 21 %s\n",KBLU, KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("Ogb9Z9%uQ%x%iO8N)JS+jK^%u%%S%cH5.%sED&", -999400266, 162720528, -178549422, -1891286730, 264728837, "(8B.,}\v5J`R9mP1pd`=k]/\nz]xGLwd+Ci\tDZ5sMO[w$98PlYTpr'PRna\\\vkVI\fk5@&eYE");
	printf("%d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("Ogb9Z9%uQ%x%iO8N)JS+jK^%u%%S%cH5.%sED&", -999400266, 162720528, -178549422, -1891286730, 264728837, "(8B.,}\v5J`R9mP1pd`=k]/\nz]xGLwd+Ci\tDZ5sMO[w$98PlYTpr'PRna\\\vkVI\fk5@&eYE");
	ft_printf("%d\n",cont );


}

