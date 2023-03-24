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
t_color	new_color(uint r, uint g, uint b, uint a)
{
	t_color	color;

	//color = b || (g << 8) || (r << 16) || (a << 24);
	//color = b + (g << 8) + (r << 16) + (a << 24);
	
		color.r = (char)r;
		color.g = (char)g;
		color.b = (char)b;
		color.a = (char)a;
	
//	printf("el color %x-%x-%x-%x es: %x\n", a<<24, r<<16, g<<8, b, color);
//	printf("el sin shift %x-%x-%x-%x es: %x\n", a, r, g, b, color);

	return (color);
}

void	palette(int n, t_color *color_pal)
{
	int		i;
	double	grado1;
	double	grado;
	double	grado_bn;

	i = 0;
	color_pal[i] = new_color(0, 0, 0, 0);
	while (++i <= ITER)
	{
		grado_bn = (1 - i / (double)ITER);
		//grado1 = i / (double)ITER;
		//grado1 = pow((2 * (double)i / ITER - 1), 2);
		grado1 = pow((double)i / ITER, 4);
		grado = -pow((2 * (double)i/ ITER - 1) , 2) + 1;
		if (n == XK_1)
			color_pal[i] = new_color((int)(grado * 0xFF), (int)(grado * 0xFF), (int)(grado * 0xFF), 0);
		else if (n == XK_2)
			color_pal[i] = new_color((int)grado1 * 0xff, (int)grado1 * 0xff, (int)grado1 * 0xff, 0);
		else if (n == XK_3)
			color_pal[i] = new_color(0xff, (int)(grado1 * 0x9f) + 0x50, (int)(grado1 * 0x9f) + 0x50, 0);
		else if (n == XK_4)
			color_pal[i] = new_color((int)(grado_bn * 0xFF), (int)(grado_bn * 0xFF), (int)(grado_bn * 0xFF), 0);
		else if (n == XK_5)
			color_pal[i] = new_color(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0);
		else
			color_pal[i] = new_color(rand() % 0xff, rand() % 0xff, rand() % 0xff, 0xa0);
		printf("%i-- %x-- %f,%f,%f\n", i, (int)(grado_bn * 0xFF), grado, grado1, grado_bn);
	}
	return ;
}

/*    color_pal[i] = new_color(0xff, i / ITER % 0x4f + 0xb0, i / \
ITER % 0x4f + 0xb0, 0);
*/