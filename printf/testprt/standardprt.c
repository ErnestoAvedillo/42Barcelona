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
#include"../entrega/ft_printf.h"
#include"test_lib.h"

void stdtest(void)
{
	char	str[] = "Esto es una %d prueba %d de %d porcentaje%";
	int		var1;
	int		var2;
	int		var3;

	var1 = 25;
	var2 = 2;
	var3 = 66;

	ft_printf(str,var1,var2,var3);
	return;
}