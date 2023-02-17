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

int deal_key(int key, void *param)
{
	printf("recibido %i -- direccion %p\n", key, param);
	return (0);
}

int main ()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	t_fract	*frac;

	frac = create_fract(1000, 1000, 500, 500);
	win_mandel(frac);
	return (0);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr,1000,1000,"mi primera ventana");
	x = 100;
	y = x;
	while (y <= 300)
	{
		x = 100;
		while (x <= 700)
		{
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	mlx_key_hook(win_ptr, deal_key,(void*)0 );
	mlx_loop(mlx_ptr);
	return (0);
}

