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
	if (mouse == MOUSE_BTN_ROT_UP)
		new_scale(SCALE_UP, frac, x, y);
	else if (mouse == MOUSE_BTN_MIDDLE)
		frac->button_pressed = MOUSE_BTN_MIDDLE;
	else if (mouse == MOUSE_BTN_ROT_DW)
		new_scale(SCALE_DW, frac, x, y);
	else if (mouse == MOUSE_BTN_RIGHT)
	{
		frac->button_pressed = MOUSE_BTN_RIGHT;
		if (frac->fract_code == FRACT_JULIA && x > 0 && y > 0)
		{
			frac->c.re = frac->c1.re + frac->escala_x * x;
			frac->c.im = frac->c1.im + frac->escala_y * y;
		}
	}
	if (mouse == MOUSE_BTN_LEFT && x > 0 && y > 0)
	{
		frac->button_pressed = MOUSE_BTN_LEFT;
		frac->mouse_pos.x = x;
		frac->mouse_pos.y = y;
	}
	else
		fractol_draw(frac);
	return (0);
}

int	mouse_events_rel(int mouse, int x, int y, t_fract *frac)
{
	frac->button_pressed = 0;
	if (mouse == MOUSE_BTN_LEFT)
	{
		frac->c1.re += (frac->mouse_pos.x - x) * frac->escala_x;
		frac->c1.im += (frac->mouse_pos.y - y) * frac->escala_y;
		fractol_draw(frac);
	}
	return (0);
}
/*	//t_complex	pos;
	if (mouse == MOUSE_BTN_RIGHT)
	{
		pos.re = frac->c1.re + frac->escala_x * x;
		pos.im = frac->c1.im + frac->escala_y * y;
	}
*/

int	mouse_events_mov(int x, int y, t_fract *frac)
{
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
	return (0);
}

/*	t_complex	pos;
	int			res;
	t_img_buff	buf;
	char		*micolor;
*/
/*	else
	{
		buf.buffer = mlx_get_data_addr(frac->image, &buf.pixel_bits, \
										&buf.line_bytes, &buf.endian);
		pos.re = frac->c1.re + frac->escala_x * x;
		pos.im = frac->c1.im + frac->escala_y * y;
		res = frac->function(frac->c, pos, frac->limit);
		micolor = &buf.buffer[y * buf.line_bytes + x * buf.pixel_bits / 8];
	}
*/