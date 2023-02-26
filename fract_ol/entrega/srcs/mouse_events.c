/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:50:25 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/26 15:50:58 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int mouse_events_pre(int mouse, int x, int y, t_fract *frac)
{

	printf("recibido pressed %i posicion %i %i-- direccion %p\n", mouse, x, y, frac);
	if (mouse == 4)
	{
		frac->escala +=100;
		frac->origin_x += 150;
//		frac->z0.re += 100;
//		frac->z0.im += 100;
//		frac->origin_y -= 100;
		fractol_draw(frac);
	}
	else if (mouse == 5)
	{
		frac->escala -= 100;
		frac->origin_x -= 150;
//		frac->z0.re += 100;
//		frac->z0.im += 100;
//		frac->origin_y += 100;
		fractol_draw(frac);
	}	
	else if (mouse == 1)
	{
		frac->mouse_pos.x = x;
		frac->mouse_pos.y = y;
	}	

	return (0);	
}

int mouse_events_rel(int mouse, int x, int y, t_fract *frac)
{

	printf("recibido release %i posicion %i %i-- direccion %p\n", mouse, x, y, frac);
	if (mouse == 1)
	{
		frac->origin_x -= frac->mouse_pos.x - x;
		frac->origin_y -= frac->mouse_pos.y - y;
		fractol_draw(frac);
	}

	return (0);	
}
