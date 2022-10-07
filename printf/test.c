/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 09:53:52 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/07 09:55:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"test.h"

//int main (int av, char **ac)
int main (void)
{
	char	str[] = "Esto es una %d prueba %d de %d porcentaje%"
	int		var1;
	int		var2;
	int		var3;

	var1 = 1;
	var2 = 2;
	var3 = 3;

	ft_printf(str,var1,var2,var3)

}
