/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:44 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/02 09:32:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	generate_fract(int key, t_fract *frac)
{
	if (key == XK_M)
		conf_mandel(frac);
	else if (key == XK_J)
		conf_julia(frac);
	else if (key == XK_B)
		conf_burning(frac);
	else if (key == XK_T)
		conf_tricorn(frac);
	return ;
}

static void	move_with_arrows(int key, t_fract *frac)
{
	if (key == XK_LEFTARROW)
		frac->c1.re += 50 * frac->escala_x;
	if (key == XK_RIGHTARROW)
		frac->c1.re -= 50 * frac->escala_x;
	if (key == XK_UPARROW)
		frac->c1.im += 50 * frac->escala_y;
	else if (key == XK_DOWNARROW)
		frac->c1.im -= 50 * frac->escala_y;
}

int	key_events(int key, t_fract *frac)
{
	if (key >= XK_LEFTARROW && key <= XK_UPARROW)
		move_with_arrows(key, frac);
	else if (key >= XK_1 && key <= XK_5)
		palette(key, frac->color);
	else if (key == XK_ESC)
		close_win(frac);
	else
		generate_fract(key, frac);
	fractol_draw(frac);
	return (0);
}

//	int	x;
//	int	y;

/*	if (key == XK_UPARROW)
	{
//		mlx_mouse_get_pos(frac->win_ptr, &x, &y);
//		new_scale(SCALE_UP, frac, x, y);
	}
	else if (key == XK_DOWNARROW)
	{
//		mlx_mouse_get_pos(frac->win_ptr, &x, &y);
//		new_scale(SCALE_DW, frac, x, y);
	}
*/
/*	else if (key == 1)
	{
		frac->c1.re += 0.1;
	}
	else if (key == 3)
	{
		frac->c1.re -= 0.1;
	}
	else if (key == 14)
	{
		frac->c1.im += 0.1;
	}
	else if (key == 8)
	{
		frac->c1.im += 0.01;
	}
	else if (key == 16)
	{
		frac->limit += 1;
	}
	else if (key == 4)
	{
		if (frac->limit > 1)
			frac->limit -= 1;
	}
*/
