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
		frac->escala *= frac->zoom_fact;
		mlx_mouse_get_pos(frac->mlx_ptr, frac->win_ptr, &x, &y);
		frac->origin_x = frac->origin_x * frac->zoom_fact - x * (frac->zoom_fact - 1);
		frac->origin_y = frac->origin_y * frac->zoom_fact - y * (frac->zoom_fact - 1);
		fractol_draw(frac);
		printf("ofigen X %f --  origen Y %f\n", frac->origin_x, frac->origin_y);
		printf(" pos x %i -- Pos y %i \n", x, y);
	}
	else if (key == XK_downarrow)
	{
		frac->escala /= frac->zoom_fact;
		mlx_mouse_get_pos(frac->mlx_ptr, frac->win_ptr, &x, &y);
		frac->origin_x = frac->origin_x / frac->zoom_fact - x * (1 / frac->zoom_fact - 1);
		frac->origin_y = frac->origin_y / frac->zoom_fact - y * (1 / frac->zoom_fact - 1);
		printf("ofigen X %f --  origen Y %f\n", frac->origin_x, frac->origin_y);
		printf(" pos x %i -- Pos y %i \n", x, y);
		fractol_draw(frac);
	}	
	else if (key == 1)
	{
		frac->origin_x -=100;
		fractol_draw(frac);
	}
	else if (key == 3)
	{
		frac->origin_x +=100;
		fractol_draw(frac);
	}
	else if (key == 14)
	{
		frac->origin_y -=100;
		fractol_draw(frac);
	}
	else if (key == 8)
	{
		frac->origin_y +=100;
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
