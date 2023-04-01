/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 08:28:36 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/01 13:57:19 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"fractol.h"

int	get_fractal(char *name)
{
	if (!ft_strncmp(name, "M", 2))
		return (FRACT_MAND);
	else if (!ft_strncmp(name, "J", 2))
		return (FRACT_JULIA);
	else if (!ft_strncmp(name, "T", 2))
		return (FRACT_TRICORN);
	else if (!ft_strncmp(name, "B", 2))
		return (FRACT_BURN);
	return (0);
}

static void	*get_frac_cfunct(int fract_type)
{
	if (fract_type == FRACT_MAND)
		return (mandelbrot);
	else if (fract_type == FRACT_JULIA)
		return (julia);
	else if (fract_type == FRACT_TRICORN)
		return (tricorn);
	return (burning);
}

t_fract	*create_fract(int fract_type, t_complex init_c)
{
	t_fract	*frac;

	frac = (t_fract *)malloc(sizeof(t_fract));
	frac->color = (t_color *) malloc (ITER * sizeof(t_color));
	palette(XK_5, frac->color);
	frac->fract_code = fract_type;
	frac->function = get_frac_cfunct(fract_type);
	frac->size_x = SIZE_X;
	frac->size_y = SIZE_Y;
	frac->frame = WIN_FRAME;
	frac->c1 = casign(ORIG_X_MANDEL, ORIG_Y_MANDEL);
	frac->c = casign(init_c.re, init_c.im);
	frac->z0 = casign(init_c.re, init_c.im);
	frac->escala_x = (double)ESC_MANDEL;
	frac->escala_y = frac->escala_x;
	frac->zoom_fact = 1.2;
	frac->limit = 4;
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr, frac->size_x, frac->size_y, \
				"Los fractales de Ernesto");
	frac->image = mlx_new_image(frac->mlx_ptr, frac->size_x, frac->size_y);
	frac->key_pressed = 0;
	frac->button_pressed = 0;
	return (frac);
}

t_complex	get_z0(int frac_type, int av, char **ac)
{
	t_complex	out;

	out = casign(0, 0);
	if (frac_type == FRACT_JULIA || frac_type == FRACT_MAND)
	{
		if (av >= 3)
			out.re = atof(ac[2]);
		if (av >= 4)
			out.im = atof(ac[3]);
	}
	return (out);
}

void	free_fract(t_fract *frac)
{
	mlx_destroy_image(frac->mlx_ptr, frac->image);
	mlx_destroy_window(frac->mlx_ptr, frac->win_ptr);
	free(frac->mlx_ptr);
	free(frac->color);
	free(frac);
	return ;
}

	//mlx_destroy_display(frac->mlx_ptr);
	//free(frac->mlx_ptr);
	/*free(frac->win_ptr);*/
	/*free(frac->image);*/
