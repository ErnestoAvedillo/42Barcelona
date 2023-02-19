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

int deal_key(int key, t_fract *frac)
{
	printf("recibido %i -- direccion %p\n", key, frac);
	if (key == 12)
	{
		frac->escala +=100;
		fractol_draw(frac);
	}
	else if (key == 0)
	{
		frac->escala -=100;
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
		frac->color -=0xFF;
		fractol_draw(frac);
	}
	else if (key == 5)
	{
		frac->color +=0xFF;;
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

int main ()
{
	t_fract	*frac;

	frac = create_fract(1000, 1000, 500, 500, mandelbrot);
	fractol_draw(frac);
	mlx_key_hook(frac->win_ptr, deal_key,(t_fract *)frac );
	mlx_hook(frac->win_ptr, 17, 1L << 17, close_win, (t_fract *) frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}

