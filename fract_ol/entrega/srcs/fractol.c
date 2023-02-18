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
		printf("paso\n");
		frac->escala +=50;
		fractol_draw(frac);
	}
	else if (key == 0)
	{
		printf("paso\n");
		frac->escala -=50;
		fractol_draw(frac);
	}
	return (0);
}

int main ()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	t_fract	*frac;

	frac = create_fract(1000, 1000, 500, 500, mandelbrot);
	fractol_draw(frac);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,frac->size_x,frac->size_y,"mi primera ventana");
	x = 0;
	y = 0;
	while (y < frac->size_y)
	{
		x = 0;
		while (x < frac->size_x)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, frac->win[x][y]);
			x++;
		}
		y++;
	}
	mlx_key_hook(win_ptr, deal_key,(t_fract *)frac );
	mlx_loop(mlx_ptr);
	free(frac);
	return (0);
}

