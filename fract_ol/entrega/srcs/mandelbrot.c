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
		printf("convergencia %f + %f i = %f \n", znext.re, znext.im, cmod(znext));
		getchar();
		i++;
	}
	printf("convergencia %f + %f i = %f \n", znext.re, znext.im, cmod(znext));
	i = (int)cmod(znext);
	return (i);
}

void win_mandel(t_fract *frac)
{
	int i;
	int j;

	i = -1;
	j = -1;
	while (++i < frac->size_x)
	{
		while (++j < frac->size_y)
		{
			frac->win[i][j] = mandelbrot(frac);
		}
	}
	return ;
}