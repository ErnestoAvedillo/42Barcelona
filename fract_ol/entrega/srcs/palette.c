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
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

void	palette(int n, t_color *color_pal)
{
	int		i;
	double	grado1;
	double	grado;
	double	grado_bn;

	i = 0;
	while (i < ITER)
	{
		grado_bn = (double)(1 - i) / ITER;
		grado1 = (double)(i / ITER);
		grado = (double) - pow(i / ITER, 6) + 1;
		if (n == XK_1)
			color_pal[i] = new_color(0, (int)(grado1 * (double)0xFF), (int)(grado1 * (double) 0xFF), 0);
		else if (n == XK_2)
			color_pal[i] = new_color((int) grado1 * (double)0xff, (int) grado1 * (double)0xff, 0, 0);
		else if (n == XK_3)
			color_pal[i] = new_color((int) (grado * (double)0x4f) + 0xb0, 0xff, (int) (grado * (double)0x4f) + 0xb0, 0);
		else if (n == XK_4)
			color_pal[i] = new_color((int) (grado_bn * (double)0xFF), (int) (grado_bn * (double)0xFF), (int) (grado_bn * (double)0xFF) , 0);
		else if (n == XK_5)
			color_pal[i] = new_color(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0);
		else
			color_pal[i] = new_color(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0xa0);
		i++;
	}
	return ;
}

/*    color_pal[i] = new_color(0xff, i / ITER % 0x4f + 0xb0, i / \
ITER % 0x4f + 0xb0, 0);
*/