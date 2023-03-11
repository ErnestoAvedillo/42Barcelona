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
* With alpha at 0 the image is opaque, and with it at 255 is completely transparent. */
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

t_color *palette (int n)
{
    t_color *color_pal;
    int i;

    color_pal = (t_color*) malloc (ITER * sizeof(t_color));
    i = 0;
    while (i < ITER)
    {
        if (n == XK_1)
            color_pal[i] = new_color(i, 0xFF * i / ITER, i, 0);
        else if (n == XK_2)
            color_pal[i] = new_color(0xFF * i,  i, 0xFF, 0);
        else if (n == XK_3)
            color_pal[i] = new_color(0xFF * i / ITER, 0xFF * i / ITER, 0xFF * i / ITER, 0);
        else if (n == XK_4)
            color_pal[i] = new_color(0x20 * (i / ITER), 0xff * (i / ITER), 0x40 * (i / ITER), 0);
        else
            color_pal[i] = new_color(0x20 * i, 0x30 * i, 0x10 * i, 0);
        i++;
    }
    return(color_pal) ;
}

