/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:11 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/11 14:58:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int mandelbrot(t_complex z0, t_complex c)
{
	int i;
	t_complex znext;
	t_complex power;

	i = 0;
	power = casign(2, 0);
	znext = cequal(z0);
	while (i <= ITER)
	{
		znext = csum(cpower(znext,power), c);
		if (cmod(znext) > (double) MAX)
			break;
		i++;
	}
	//printf("mandelbrot %f + %f i = %f \n", c.re, c.im, cmod(znext));
	//getchar();
	
	if (cmod(znext) > (double) MAX)
		i = MAX;
	else
	i = ft_abs((int)(cmod(znext)* MAX)) ;
	return (i);
}
