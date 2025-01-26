/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:11 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/11 14:58:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	brn_abs(double n)
{
	if (n >= 0)
		return (n);
	return (n * -1);
}

int	burning(t_complex z0, t_complex c, int limit)
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
		znext.im = brn_abs(2 * tmp.re * tmp.im) + c.im;
		i++;
	}
	if (i == ITER)
		i = 0;
	return (i);
}

void	conf_burning(t_fract *frac)
{
	frac->fract_code = FRACT_BURN;
	frac->function = burning;
	frac->c = casign(0, 0);
	frac->z0 = casign(0, 0);
	frac->c1 = casign(ORIG_X_BURNING, ORIG_Y_BURNING);
	frac->escala_x = (double)ESC_BURNING;
	frac->escala_y = frac->escala_x;
	frac->limit = 4;
	palette(XK_4, frac->color);
}
