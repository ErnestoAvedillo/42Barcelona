/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:11 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/11 14:58:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int	julia(t_complex c, t_complex z0, int limit)
{
	int			i;
	t_complex	znext;
	t_complex	tmp;

	i = 0;
	znext = cequal(z0);
	while (i <= ITER)
	{
		if ((znext.re * znext.re + znext.im * znext.im) > (double)limit)
			break ;
		tmp.re = znext.re;
		tmp.im = znext.im;
		znext.re = tmp.re * tmp.re - tmp.im * tmp.im + c.re;
		znext.im = 2 * tmp.re * tmp.im + c.im;
		i++;
	}
	return (i);
}
<<<<<<< HEAD
=======

void	conf_julia(t_fract *frac)
{
	frac->fract_code = FRACT_JULIA;
	frac->function = julia;
	frac->c = casign(0, -0.8);
	frac->z0 = casign(0, 0);
	frac->c1 = casign(ORIG_X_JULIA, ORIG_Y_JULIA);
	frac->escala_x = (double)ESC_JULIA;
	frac->escala_y = frac->escala_x;
}
>>>>>>> 7fd21a0fa3f737f23759be2bdb299b1ac15c448e
