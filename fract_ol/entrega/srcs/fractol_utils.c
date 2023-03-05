/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:28:36 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/14 08:28:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fractol.h"

t_fract	*create_fract(int (*fractal_func)(t_complex, t_complex, int, int))
{
	t_fract	*frac;
	int		i;
	int		j;

	frac = (t_fract *)malloc(sizeof(t_fract));
	frac->win = (int **)malloc(SIZE_X * sizeof(int *));
	i = -1;
	j = -1;
	while (++i < SIZE_X)
	{
		j = -1;
		frac->win[i] = (int *) malloc(SIZE_Y * sizeof(int));
		while (++j < SIZE_Y)
		{
			frac->win[i][j] = 0;
		}
	}
	frac->function = fractal_func;
	frac->size_x = SIZE_X;
	frac->size_y = SIZE_Y;
	frac->frame = 50;
	frac->c1 = casign(ORIG_SUP_RE, ORIG_SUP_IM);
	frac->c = casign(0,0);
	frac->z0 = casign(0, 0);
	frac->escala_x = (double)(ORIG_INF_RE - ORIG_SUP_RE) / (frac->size_x - 2 * frac->frame);
	frac->escala_y = (double) (ORIG_INF_IM - ORIG_SUP_IM) /  (frac->size_y - 2 * frac->frame);
	frac->zoom_fact = 1.2;
	frac->color = new_color(0x60, 0x70, 0x40, 0x0);
	frac->repet = 150;
	frac->limit = 4;
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr,frac->size_x,frac->size_y,"Los fractales de Ernesto");
	frac->image = mlx_new_image(frac->mlx_ptr,frac->size_x,frac->size_y);
	return (frac);
}

void	free_fract(t_fract *frac)
{
	int	i;

	i = -1;
	while (++i < frac->size_x)
		free(frac->win[i]);
	free(frac->win);
	free (frac->mlx_ptr);
	free(frac->win_ptr);
	free(frac);
	return ;
}

void put_pixel_color(char *pixel, t_color color, int factor)
{
	pixel[0] = color.r * factor;
	pixel[1] = color.g;
	pixel[2] = color.b;
	pixel[3] = color.a;
}

/* Return a new color, each value can go from 0 to 255.
* With alpha at 0 the image is opaque, and with it at 255 is completely transparent. */
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r = (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}