/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:11:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/17 19:12:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void put_pixel_color(char *pixel, t_color color)
{
	//pixel = color.r <<24 | color.g << 16 | color.b << 8 | color.a;
	pixel[0] = color.r;
	pixel[1] = color.g;
	pixel[2] = color.b;
	//pixel[3] = color.a;
	pixel[3] = 0;
}


void fractol_draw (t_fract *frac)
{
	int i;
	int j;
	int k;
	int result;
	int pixel_bits;
	int line_bytes;
	int endian;
	int max;
	int min;
	char *buffer = mlx_get_data_addr(frac->image, &pixel_bits, &line_bytes, &endian);

	i = frac->frame;
	k = 0;
	max = 0;
	min = ITER;
	while(++i < frac->size_x - frac->frame)
	{
		j = frac->frame;
		while(++j < frac->size_y - frac->frame)
		{
			frac->z0.re = (frac->c1.re + i * frac->escala_x);
			frac->z0.im = (frac->c1.im + j * frac->escala_y);
			result = frac->function(frac->c, frac->z0, frac->limit);
			if (result > max)
				max = result;
			if (result < min)
				min = result;
			put_pixel_color (&buffer[j * line_bytes + i * pixel_bits / 8 ] , frac->color[result]);
			k++;
		} 
	}
	printf ("rango %i -- %i\n", max, min);
	mlx_put_image_to_window(frac->mlx_ptr,frac->win_ptr, frac->image, 0, 0);
}

void	new_scale(int sense, t_fract *frac, int x, int y)
{
	t_complex	cur;
	x -= frac->frame;
	y -= frac->frame;

	if (sense == SCALE_UP)
	{
		cur = casign (frac->c1.re + x * frac->escala_x, frac->c1.im + y * frac->escala_y);
		frac->escala_x /= frac->zoom_fact;
		frac->escala_y /= frac->zoom_fact;
		frac->c1 = casign(cur.re - x * frac->escala_x, cur.im - y * frac->escala_y);
	}
	else if (sense == SCALE_DW)
	{
		cur = casign (frac->c1.re + x * frac->escala_x, frac->c1.im + y * frac->escala_y);
		frac->escala_x *= frac->zoom_fact;
		frac->escala_y *= frac->zoom_fact;
		frac->c1 = casign(cur.re - x * frac->escala_x,cur.im - y * frac->escala_y);
	}
}