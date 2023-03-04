/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:24:07 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/04 11:28:02 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fractol.h"


int main ()
{
	t_fract	*frac;

	frac = create_fract(750, 750, 355, 355, mandelbrot);
	fractol_draw(frac);
	mlx_key_hook(frac->win_ptr, key_events,(t_fract *)frac );
	mlx_mouse_hook_pre(frac->win_ptr, mouse_events_pre, (t_fract *)frac );
	mlx_mouse_hook_rel(frac->win_ptr, mouse_events_rel, (t_fract *)frac);
	mlx_mouse_hook_mov(frac->win_ptr, mouse_events_mov, (t_fract *)frac);
	mlx_hook(frac->win_ptr, 17, 1L << 17, close_win, (t_fract *) frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}

