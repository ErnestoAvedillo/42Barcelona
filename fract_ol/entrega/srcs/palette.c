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
uint	new_color(uint r, uint g, uint b, uint a)
{
	uint	color;

	//color = b || (g << 8) || (r << 16) || (a << 24);
	color = b + (g << 8) + (r << 16) + (a << 24);
	/*
		color = (char)r;
		color.g = (char)g;
		color.b = (char)b;
		color.a = (char)a;
	*/
	printf("el color %x-%x-%x-%x es: %x\n", a<<24, r<<16, g<<8, b, color);
	printf("el sin shift %x-%x-%x-%x es: %x\n", a, r, g, b, color);

	return (color);
}

void	palette(int n, uint *color_pal)
{
	int		i;
	double	grado1;
	double	grado;
	double	grado_bn;

	i = 0;
	color_pal[0] = new_color(0, 0, 0, 0);
	while (++i < ITER)
	{
		grado_bn = (double)((1-i) / ITER);
		grado1 = (double)(i / ITER);
		grado = (double)pow(i / ITER - 1, 6);
		if (n == XK_1)
			color_pal[i] = new_color(0xFF, 0xFF, 0xFF, 0);
		else if (n == XK_2)
			color_pal[i] = new_color((int) grado * (double)0xff, (int) grado * (double)0xff, 0, 0);
		else if (n == XK_3)
			color_pal[i] = new_color((int) (grado_bn * (double)0x4f) + 0xb0, 0xff, (int) (grado1 * (double)0x4f) + 0xb0, 0);
		else if (n == XK_4)
			color_pal[i] = new_color((int) (grado1 * (double)0xFF), (int) (grado1 * (double)0xFF), (int) (grado1 * (double)0xFF) , 0);
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