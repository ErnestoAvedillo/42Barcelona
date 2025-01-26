/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palette.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 13:37:12 by eavedill          #+#    #+#             */
/*   Updated: 2023/03/05 13:38:03 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* Return a new color, each value can go from 0 to 255.
* With alpha at 0 the image is opaque, and with it at 255 is completely 
transparent. */
t_color	nw_col(unsigned int r, unsigned int g, unsigned int b, \
	unsigned int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	palette(int n, t_color *palte)
{
	int		i;
	int		gr;
	double	gr_bn;

	i = -1;
	while (++i < ITER)
	{
		gr_bn = (int)(0xff * (1 - i / (double)ITER));
		gr = (int)(0xff * (-pow((2 * (double)i / ITER - 1), 2) + 1));
		if (n == XK_1)
			palte[i] = nw_col(gr, gr, gr, 0);
		else if (n == XK_2)
			palte[i] = nw_col(0, gr, gr, 0);
		else if (n == XK_3)
			palte[i] = nw_col(gr, gr, 0, 0);
		else if (n == XK_4)
			palte[i] = nw_col(gr_bn, gr_bn, gr_bn, 0);
		else if (n == XK_5)
			palte[i] = nw_col(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0);
		else
			palte[i] = nw_col(rand() % 0xff, rand() % 0xff, \
				rand() % 0xff, 0xa0);
	}
	if (n == XK_4)
		palte[0] = nw_col(0, 0, 0, 0);
}

/*		//grado1 = i / (double)ITER;
		//grado1 = pow((2 * (double)i / ITER - 1), 2);
		printf("%i-- %x-- %f,%f,%f\n", i, (int)(grado_bn * 0xFF), 
		grado, grado1, grado_bn);
    color_pal[i] = nw_col(0xff, i / ITER % 0x4f + 0xb0, i / \
ITER % 0x4f + 0xb0, 0);
*/