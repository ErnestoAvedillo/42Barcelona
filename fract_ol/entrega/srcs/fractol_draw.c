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

#include "fractol.h"

void	put_pixel_color(char *pixel, t_color color)
{
	pixel[0] = color.r;
	pixel[1] = color.g;
	pixel[2] = color.b;
	pixel[3] = color.a;
}

void	fractol_draw(t_fract *frac)
{
	t_indexes	ind;
	int			result;
	t_img_buff	buf;

	buf.buffer = mlx_get_data_addr(frac->image, &buf.pixel_bits, \
			&buf.line_bytes, &buf.endian);
	ind.i = frac->frame -1;
	while (++ind.i < frac->size_x - frac->frame)
	{
		ind.j = frac->frame - 1;
		while (++ind.j < frac->size_y - frac->frame)
		{
			frac->z0.re = (frac->c1.re + ind.i * frac->escala_x);
			frac->z0.im = (frac->c1.im + ind.j * frac->escala_y);
			result = frac->function(frac->c, frac->z0, frac->limit);
			put_pixel_color(&buf.buffer[ind.j * buf.line_bytes + \
					ind.i * buf.pixel_bits / 8], frac->color[result]);
		}
	}
	mlx_put_image_to_window(frac->mlx_ptr, frac->win_ptr, frac->image, 0, 0);
}

void	new_scale(int sense, t_fract *frac, int x, int y)
{
	t_complex	cur;

	x -= frac->frame;
	y -= frac->frame;
	if (sense == SCALE_UP)
	{
		cur = casign (frac->c1.re + x * frac->escala_x, \
				frac->c1.im + y * frac->escala_y);
		frac->escala_x /= frac->zoom_fact;
		frac->escala_y /= frac->zoom_fact;
		frac->c1 = casign(cur.re - x * frac->escala_x, \
				cur.im - y * frac->escala_y);
	}
	else if (sense == SCALE_DW)
	{
		cur = casign (frac->c1.re + x * frac->escala_x, \
				frac->c1.im + y * frac->escala_y);
		frac->escala_x *= frac->zoom_fact;
		frac->escala_y *= frac->zoom_fact;
		frac->c1 = casign(cur.re - x * frac->escala_x, cur.im - \
				y * frac->escala_y);
	}
}
