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

int	mouse_events_pre(int mouse, int x, int y, t_fract *frac)
{
	printf("mouse %i, x %i, y, %i", mouse, x, y);
	if (mouse == MOUSE_BTN_ROT_UP)
	{
		printf("BTN ROT UP posicion x = %i ; posicion y = %i\n", x, y);
		new_scale(SCALE_UP, frac, x, y);
		fractol_draw(frac);
	}
	else if (mouse == MOUSE_BTN_MIDDLE)
	{
		frac->button_pressed = MOUSE_BTN_MIDDLE;
	}
	else if (mouse == MOUSE_BTN_ROT_DW)
	{
		printf("BTN ROT DWN posicion x = %i ; posicion y = %i\n", x, y);
		new_scale(SCALE_DW, frac, x, y);
		fractol_draw(frac);
	}	
	else if (mouse == MOUSE_BTN_LEFT)
	{
		printf("BTN LEFT posicion x = %i ; posicion y = %i\n", x, y);
		if (x > 0 && y > 0)
		{
			frac->button_pressed = MOUSE_BTN_LEFT;
			frac->mouse_pos.x = x;
			frac->mouse_pos.y = y;
		}
	}
	else if (mouse == MOUSE_BTN_RIGHT)
	{
		printf("BTN RIGHT posicion x = %i ; posicion y = %i\n", x, y);
		frac->button_pressed = MOUSE_BTN_RIGHT;
		if (frac->fract_code == FRACT_JULIA && x > 0 && y > 0)
		{
			frac->c.re = frac->c1.re + frac->escala_x * x;
			frac->c.im = frac->c1.im + frac->escala_y * y;
			fractol_draw(frac);
		}
	}
	return (0);
}

int	mouse_events_rel(int mouse, int x, int y, t_fract *frac)
{
	t_complex	pos;

	printf("mouse %i, x %i, y, %i\n", mouse, x, y);
	frac->button_pressed = 0;
	if (mouse == MOUSE_BTN_LEFT)
	{
		frac->c1.re += (frac->mouse_pos.x - x) * frac->escala_x;
		frac->c1.im += (frac->mouse_pos.y - y) * frac->escala_y;
		fractol_draw(frac);
	}
	if (mouse == MOUSE_BTN_RIGHT)
	{
		pos.re = frac->c1.re + frac->escala_x * x;
		pos.im = frac->c1.im + frac->escala_y * y;
		printf("result  = %i\n", frac->function(frac->c, pos, frac->limit));
	}
	printf("mouse x %f, y, %f, escala x = %f , escala y = %f", frac->c1.re, \
			frac->c1.im, frac->escala_x, frac->escala_y);
	return (0);
}

//int mouse_events_mov(int mouse, int x, int y, t_fract *frac)
	//printf("recibido posicion %i %i-- direccion %p\n", x, y, frac);
int	mouse_events_mov(int x, int y, t_fract *frac)
{
	t_complex pos;
	int res;
	t_img_buff buf;
	char *micolor;

	if (x > 0 && y > 0 && frac->button_pressed == MOUSE_BTN_RIGHT)
	{
		frac->c.re = frac->c1.re + frac->escala_x * x;
		frac->c.im = frac->c1.im + frac->escala_y * y;
		fractol_draw(frac);
	}
	else if (frac->button_pressed == MOUSE_BTN_LEFT)
	{
		frac->c1.re += (frac->mouse_pos.x - x) * frac->escala_x;
		frac->c1.im += (frac->mouse_pos.y - y) * frac->escala_y;
		fractol_draw(frac);
		frac->mouse_pos.x = x;
		frac->mouse_pos.y = y;
	}
	else
	{
		buf.buffer = mlx_get_data_addr(frac->image, &buf.pixel_bits,
									   &buf.line_bytes, &buf.endian);
		pos.re = frac->c1.re + frac->escala_x * x;
		pos.im = frac->c1.im + frac->escala_y * y;
		res = frac->function(frac->c, pos, frac->limit);
		micolor = &buf.buffer[y * buf.line_bytes + x * buf.pixel_bits / 8];
		printf("result  = %i color %x%x%x%x en pantalla %x-%x-%x-%x \n", res, frac->color->r, frac->color->g, frac->color->b, frac->color->a, *(micolor - 0), *(micolor + 1), *(micolor + 2), *(micolor + 3));
		printf("result  = %i en pantalla %x-%x-%x-%x \n", res, *(micolor - 0), *(micolor + 1), *(micolor + 2), *(micolor + 3));
	}
	return (0);
}
