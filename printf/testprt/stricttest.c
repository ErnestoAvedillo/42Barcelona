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
#include"test_lib.h"

void stricttest(void)
{
	int cont;

	cont = 0;
	printf("%stest 1 %s %s\n",KBLU,"\001\n", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("\001\n");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("\001\n");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 2 %s %s\n",KBLU,"\001\002\007\v\010\f\r\n", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("\001\002\007\v\010\f\r\n");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("\001\002\007\v\010\f\r\n");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 3 %s %s\n",KBLU,"%%c", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%%c");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%c");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 4 %s %s\n",KBLU,"%%%%%%", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%%%%%%");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%%%%%");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 5 %s %s\n",KBLU,"%%%c", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%%%c", 'x');
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%%%c", 'x');
	ft_printf("Resultado %d\n",cont );
	printf("%stest 6 %s %s\n",KBLU," %c", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf(" %c", 'x');
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf(" %c", 'x');
	ft_printf("Resultado %d\n",cont );
	printf("%stest 6 %s %s\n",KBLU,"%c ", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%c ", 'x');
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%c ", 'x');
	ft_printf("Resultado %d\n",cont );
	printf("%stest 7 %s %s\n",KBLU,"%c%c%c", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%c%c%c", 'a', '\t', 'b');
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%c%c%c", 'a', '\t', 'b');
	ft_printf("Resultado %d\n",cont );
	printf("%stest 7 %s %s\n",KBLU,"%cs%cs%c", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%cs%cs%c", 'c', 'b', 'a');
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%cs%cs%c", 'c', 'b', 'a');
	ft_printf("Resultado %d\n",cont );
	printf("%stest 8 %s %s\n",KBLU,"%s", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s", "");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s", "");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 9 %s %s\n",KBLU,"%s", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
//	cont =  printf("%s", (char *)NULL);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s", (char *)NULL);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 10 %s %s\n",KBLU,"%s", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s", "some string with %s hehe");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s", "some string with %s hehe");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 11 %s %s\n",KBLU,"%s", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf(" %s", "can it handle \t and \n?");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf(" %s", "can it handle \t and \n?");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 12 %s %s\n",KBLU,"%sx", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 12 %s %s\n",KBLU,"%s%s%s", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%s%s%s", "And ", "some", "joined");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%s%s%s", "And ", "some", "joined");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 13 %s %s\n",KBLU,"%ss%ss%ss", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%ss%ss%ss", "And ", "some", "joined");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%ss%ss%ss", "And ", "some", "joined");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 14 %s %s\n",KBLU,"%p", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%p", "");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%p", "");
	ft_printf("Resultado %d\n",cont );
	printf("%stest 15 %s %s\n",KBLU,"%p", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%p", NULL);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%p", NULL);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 16 %s %s\n",KBLU,"%d", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%d", 0);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%d", 0);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 17 %s %s\n",KBLU,"%i", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%i", 0);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%i", 0);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 18 %s %s\n",KBLU,"%u", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%u", 0);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%u", 0);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 19 %s %s\n",KBLU,"%x", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%x", 0);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%x", 0);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 20 %s %s\n",KBLU,"%X", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("%X", 0);
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("%X", 0);
	ft_printf("Resultado %d\n",cont );
	printf("%stest 21 %s %s\n",KBLU,"Ogb9Z9%uQ%x%iO8N)JS+jK^%u%%S%cH5.%sED&", KNRM );
	printf("%simpresion con printf%s\n",KGRN, KNRM );
	cont =  printf("Ogb9Z9%uQ%x%iO8N)JS+jK^%u%%S%cH5.%sED&", -999400266, 162720528, -178549422, -1891286730, 264728837, "(8B.,}\v5J`R9mP1pd`=k]/\nz]xGLwd+Ci\tDZ5sMO[w$98PlYTpr'PRna\\\vkVI\fk5@&eYE");
	printf("Resultado %d\n",cont );
	printf("%simpresion con ft_printf%s\n",KGRN, KNRM );
	cont =  ft_printf("Ogb9Z9%uQ%x%iO8N)JS+jK^%u%%S%cH5.%sED&", -999400266, 162720528, -178549422, -1891286730, 264728837, "(8B.,}\v5J`R9mP1pd`=k]/\nz]xGLwd+Ci\tDZ5sMO[w$98PlYTpr'PRna\\\vkVI\fk5@&eYE");
	ft_printf("Resultado %d\n",cont );


}

