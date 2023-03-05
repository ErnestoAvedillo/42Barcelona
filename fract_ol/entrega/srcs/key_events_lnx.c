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
	int aux;
	int x;
	int y;

	printf("recibido %x -- direccion %p\n", key, frac);
	if (key == XK_uparrow)
	{
		mlx_mouse_get_pos(frac->mlx_ptr, frac->win_ptr, &x, &y);
		new_scale(SCALE_UP, frac, x, y);
		fractol_draw(frac);
	}
	else if (key == XK_downarrow)
	{
		mlx_mouse_get_pos(frac->mlx_ptr, frac->win_ptr, &x, &y);
		new_scale(SCALE_UP, frac, x, y);
		fractol_draw(frac);
	}	
	else if (key == 1)
	{
		frac->c1.re += 0.1;
		fractol_draw(frac);
	}
	else if (key == 3)
	{
		frac->c1.re -= 0.1;
		fractol_draw(frac);
	}
	else if (key == 14)
	{
		frac->c1.im += 0.1;
		fractol_draw(frac);
	}
	else if (key == 8)
	{
		frac->c1.im += 0.01;
		fractol_draw(frac);
	}
	else if (key == 17)
	{
		aux = frac->color.r;
		frac->color.r = frac->color.b;
		frac->color.b = frac->color.g;
		frac->color.g = aux;
		fractol_draw(frac);
	}
	else if (key == 5)
	{
		aux = frac->color.g;
		frac->color.g = frac->color.b;
		frac->color.b = frac->color.r;
		frac->color.r = aux;
		fractol_draw(frac);
	}
	else if (key == 16)
	{
		frac->limit += 1;
		fractol_draw(frac);
	}
	else if (key == 4)
	{
		if (frac->limit > 1)
			frac->limit -= 1;
		fractol_draw(frac);
	}
	return (0);	
}
