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
#include"math.h"

int deal_key(int key, void *param)
{
	write(1, "recibido\n", 9);
	return (0);
}

int main ()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	double complex z0 = 0 ;
	double complex c = 1;

	fract_calc(z0,c);
	return(0);
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

