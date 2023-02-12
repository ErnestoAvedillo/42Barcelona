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
	t_complex z0;
	t_complex z1;
	t_complex c;

	z0 = casign(1, 3);
	printf("el valor z0 es %f + %f i\n", z0.re, z0.im);
	printf("el modulo z0 es %f \n", cmod(z0));
	printf("la fase z0 es %f \n", cdeg(z0));
	c = casign(2, 4);
	printf("el valor c es %f + %f i\n", c.re, c.im);
	z1 = csum(z0, c);
	printf("el valor suma es %f + %f i\n", z1.re, z1.im);
	z1 = cmul(z0, c);
	printf("el valor mult es %f + %f i\n", z1.re, z1.im);
	z1 = cdiv(z0, c);
	printf("el valor div es %f + %f i\n", z1.re, z1.im);
	z1 = cpower(z0, c);
	printf("el valor power es %f + %f i\n", z1.re, z1.im);

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

