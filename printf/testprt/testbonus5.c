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

void bonustest5(void)
{
	int cont;

	cont =  0;
	printf("%s Test 0 bonus %s %s\n",KGRN," %-1u ", KNRM );
	cont = printf(" %-1u ", 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1u ", 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 0 bis bonus %s %s\n",KGRN," %-2u ", KNRM );
	cont = printf(" %-2u ",   -1);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-2u ",  -1);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 1 bonus %s %s\n",KGRN," %-4u ", KNRM );
	cont = printf(" %-4u ", 19);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4u ", 19);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 2 bonus %s %s\n",KGRN," %-3u ", KNRM );
	cont = printf(" %-3u ", 103);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-3u ", 103);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 3 bonus %s %s\n",KGRN," %-6u ", KNRM );
	cont = printf(" %-6u ", -16);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-6u ", -16);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 4 bonus %s %s\n",KGRN," %-9u ", KNRM );
	cont = printf(" %-9u ", -101);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9u ", -101);
	printf ("respuesta ft_printf %d\n", cont);

/*	printf("%s Test 5 bonus %s %s\n",KGRN, KNRM );
	cont = printf(" %-11u %-12u ", LONG_MAX, LONG_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-11u %-12u ", LONG_MAX, LONG_MIN);
	printf ("respuesta ft_printf %d\n", cont);
*/
	printf("%s Test 6 bonus %s %s\n",KGRN," %-9u %-10u ", KNRM );
	cont = printf(" %-9u %-10u ", INT_MAX, INT_MIN);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-9u %-10u ", INT_MAX, INT_MIN);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 7 bonus %s %s\n",KGRN," %-13u %-14u ", KNRM );
	cont = printf(" %-13u %-14u ", UINT_MAX, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-13u %-14u ", UINT_MAX, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 8 bonus %s %s\n",KGRN," %-1u %-2u ", KNRM );
	cont = printf(" %-1u %-2u ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-1u %-2u ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 9 bonus %s %s\n",KGRN," %-4u $ %4u ", KNRM );
	cont = printf(" %-4u $ %4u ",  0, 0);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf(" %-4u $ %4u ", 0, 0);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 10 bonus %s %s\n",KGRN," %-8.5u $ %-5.8u ", KNRM );
	cont = printf("<%-8.5u> $ <%-8.5u> ",  0, 835);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-8.5u> $ <%-8.5u> ", 0, 835);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 11 bonus %s %s\n",KGRN," %--120.50 $ %--120.50 ", KNRM );
	cont = printf("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 12 bonus %s %s\n",KGRN," %0163.109u ", KNRM );
	cont = printf("<%0163.109u>" ,2109506632u);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%0163.109u>" ,2109506632u);
	printf ("respuesta ft_printf %d\n", cont);
	
	printf("%s Test 13 bonus %s %s\n",KGRN," %0163.109u ", KNRM );
	cont = printf("<%0163.109u>" ,2109506632u);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%0163.109u>" ,2109506632u);
	printf ("respuesta ft_printf %d\n", cont);
	
	printf("%s Test 14 bonus %s %s\n",KGRN," %-140.69d ", KNRM );
	cont = printf("<%-140.69d>" ,-1086209677);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-140.69d>" ,-1086209677);
	printf ("respuesta ft_printf %d\n", cont);
	
	printf("%s Test 15 bonus %s %s\n",KGRN," %---91.148s ", KNRM );
	cont = printf("<%---91.148s>" ,"www");
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%---91.148s>" ,"www");
	printf ("respuesta ft_printf %d\n", cont);
	
	printf("%s Test 16 bonus %s %s\n",KGRN," %000132.141i ", KNRM );
	cont = printf("<%000132.141i>" ,-1143516304);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%000132.141i>" ,-1143516304);
	printf ("respuesta ft_printf %d\n", cont);
	
	printf("%s Test 17 bonus %s %s\n",KGRN," %-52.170x ", KNRM );
	cont = printf("<%-52.170x>" ,2879456117u);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("<%-52.170x>" ,2879456117u);
	printf ("respuesta ft_printf %d\n", cont);

	printf("%s Test 18 bonus %s %s\n",KGRN," %0163.109u%-140.69d%---91.148s%000132.141i%-52.170x ", KNRM );
	cont = printf("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170x" ,2109506632u,-1086209677,"\nmD^8<.q*'\rD",-1143516304,2879456117u
);
	printf ("respuesta ???printf %d\n", cont);
	cont = ft_printf("%0163.109u%-140.69d%---91.148s%000132.141i%-52.170x" ,2109506632u,-1086209677,"\nmD^8<.q*'\rD",-1143516304,2879456117u
);
	printf ("respuesta ft_printf %d\n", cont);


}
