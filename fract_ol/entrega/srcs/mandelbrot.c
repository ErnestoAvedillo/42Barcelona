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

int	mandelbrot(t_complex z0, t_complex c, int limit)
{
	int			i;
	t_complex	znext;
	t_complex	tmp;

	i = 0;
	znext = cequal(z0);
	while (i < ITER)
	{
		if ((znext.re * znext.re + znext.im * znext.im) > (double)limit)
			break ;
		tmp.re = znext.re;
		tmp.im = znext.im;
		znext.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		znext.im = 2 * tmp.re * tmp.im + c.im;
		i++;
	}
	if (i == ITER)
		i = 99;
	return (i);
}

void	conf_mandel(t_fract *frac)
{
	frac->fract_code = FRACT_MAND;
	frac->function = mandelbrot;
	frac->c = casign(0, 0);
	frac->z0 = casign(0, 0);
	frac->c1 = casign(ORIG_X_MANDEL, ORIG_Y_MANDEL);
	frac->escala_x = (double)ESC_MANDEL;
	frac->escala_y = frac->escala_x;
	palette(XK_5, frac->color);
}
