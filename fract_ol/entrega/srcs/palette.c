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

t_color	*palette(int n)
{
	t_color	*color_pal;
	int		i;
	double	grado;
	double	grado_bn;

	color_pal = (t_color *) malloc (ITER * sizeof(t_color));
	i = 0;
	while (i < ITER)
	{
		grado_bn = (double)(1 - i) / ITER;
		grado = (double)-2 * pow(i / ITER, 2) + 2 * i / ITER;
		grado = (double) 1.2 * log(-i / ITER + 1);
		if (n == XK_1)
			color_pal[i] = new_color(0, (int)(grado * (double)0xFF), (int)(grado * (double) 0xFF), 0);
		else if (n == XK_2)
			color_pal[i] = new_color((int) grado % 0x4f + 0xb0, (int) grado % 0x4f + 0xb0, 0, 0);
		else if (n == XK_3)
			color_pal[i] = new_color((int) sin(i) % 0x4f + 0xb0, 0xff, (int) sin(i) % 0x4f + 0xb0, 0);
		else if (n == XK_4)
			color_pal[i] = new_color((int) 0xFF * grado_bn, (int) 0xFF * grado_bn, (int) 0xFF * grado_bn, 0);
		else if (n == XK_5)
			color_pal[i] = new_color(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0);
		else
			color_pal[i] = new_color(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0xa0);
		i++;
	}
	return (color_pal);
}

/*    color_pal[i] = new_color(0xff, i / ITER % 0x4f + 0xb0, i / \
ITER % 0x4f + 0xb0, 0);
*/