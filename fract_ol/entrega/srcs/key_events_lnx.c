/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:44 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/26 15:51:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int key_events(int key, t_fract *frac)
{
	int x;
	int y;

	printf("hola recibido %x -- direccion %p\n", key, frac);
	if (key == XK_uparrow)
	{
		mlx_mouse_get_pos(frac->mlx_ptr, frac->win_ptr, &x, &y);
		printf("KEY ARRW UP posicion x = %i ; posicion y = %i\n", x, y);
		new_scale(SCALE_UP, frac, x, y);
	}
	else if (key == XK_downarrow)
	{
		mlx_mouse_get_pos(frac->mlx_ptr, frac->win_ptr, &x, &y);
		printf("KEY ARRW DWN posicion x = %i ; posicion y = %i\n", x, y);
		new_scale(SCALE_UP, frac, x, y);
	}
	else if (key == XK_m)
	{
		frac->fract_code = FRACT_MAND;
		frac->function = mandelbrot;
		frac->c = casign(0, 0);
		frac->z0 = casign(0, 0);
		frac->c1 = casign(ORIG_SUP_RE, ORIG_SUP_IM);
		frac->escala_x = (double)(ORIG_INF_RE - ORIG_SUP_RE) / (frac->size_x - 2 * frac->frame);
		frac->escala_y = frac->escala_x;
	}
	else if (key == XK_j)
	{
		frac->fract_code = FRACT_JULIA;
		frac->function = julia;
		frac->c = casign(0, -0.8);
		frac->z0 = casign(0,0);
		frac->c1 = casign(ORIG_SUP_RE, ORIG_SUP_IM);
		frac->escala_x = (double)(ORIG_INF_RE - ORIG_SUP_RE) / (frac->size_x - 2 * frac->frame);
		frac->escala_y = frac->escala_x;
	}
	else if (key == XK_b)
	{
		frac->fract_code = FRACT_BURN;
		frac->function = burning;
		frac->c = casign(0, 0);
		frac->z0 = casign(0, 0);
		frac->c1 = casign(ORIG_SUP_RE, ORIG_SUP_IM);
		frac->escala_x = (double)(ORIG_INF_RE - ORIG_SUP_RE) / (frac->size_x - 2 * frac->frame);
		frac->escala_y = frac->escala_x;
		frac->limit = 4;
	}
	else if (key == XK_t)
	{
		frac->fract_code = FRACT_TRICORN;
		frac->function = tricorn;
		frac->c = casign(0,-0.8);
		frac->z0 = casign(0,0);
		frac->c1 = casign(ORIG_SUP_RE, ORIG_SUP_IM);
		frac->escala_x = (double)(ORIG_INF_RE - ORIG_SUP_RE) / (frac->size_x - 2 * frac->frame);
		frac->escala_y = frac->escala_x;
	}
	else if (key >= XK_1 && key <= XK_5)
		frac->color = palette(key);
	else if (key == XK_ESC)
		close_win(frac);
	else if (key == 1)
		frac->c1.re += 0.1;
	else if (key == 3)
		frac->c1.re -= 0.1;
	else if (key == 14)
		frac->c1.im += 0.1;
	else if (key == 8)
		frac->c1.im += 0.01;
	else if (key == 16)
		frac->limit += 1;
	else if (key == 4)
	{
		if (frac->limit > 1)
			frac->limit -= 1;
	}
	fractol_draw(frac);
	return (0);	
}
