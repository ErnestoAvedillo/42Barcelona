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
	//printf("mouse %i, x %i, y, %i", mouse, x, y);
	if (mouse == MOUSE_BTN_ROT_UP)
	{
		printf("BTN ROT UP posicion x = %i ; posicion y = %i\n",x , y);
		new_scale(SCALE_UP, frac, x , y);
		fractol_draw(frac);
	}
	else if (mouse == MOUSE_BTN_ROT_DW)
	{
		printf("BTN ROT DWN posicion x = %i ; posicion y = %i\n",x , y);
		new_scale(SCALE_DW, frac, x, y);
		fractol_draw(frac);
	}	
	else if (mouse == MOUSE_BTN_LEFT)
	{
		printf("BTN LEFT posicion x = %i ; posicion y = %i\n",x , y);
		frac->mouse_pos.x = x;
		frac->mouse_pos.y = y;
	}
	else if (mouse == MOUSE_BTN_RIGHT)
	{
		printf("BTN RIGHT posicion x = %i ; posicion y = %i\n",x , y);

	}

	return (0);	
}

int mouse_events_rel(int mouse, int x, int y, t_fract *frac)
{

	if (mouse == MOUSE_BTN_LEFT)
	{
		frac->c1.re += (frac->mouse_pos.x - x) * frac->escala_x;
		frac->c1.im += (frac->mouse_pos.y - y) * frac->escala_y;
		fractol_draw(frac);
	}

	return (0);
}
int mouse_events_mov(int mouse, int x, int y, t_fract *frac)
{

	printf("recibido move %i posicion %i %i-- direccion %p\n", mouse, x, y, frac);

	return (0);
}
