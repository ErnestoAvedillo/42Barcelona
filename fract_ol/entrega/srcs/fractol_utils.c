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

t_fract	*create_fract()
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
	frac->fract_code = FRACT_MAND;
	frac->function = mandelbrot;
	frac->size_x = SIZE_X;
	frac->size_y = SIZE_Y;
	frac->frame = 50;
	frac->c1 = casign(ORIG_X_MANDEL, ORIG_Y_MANDEL);
	frac->c = casign(0,0);
	frac->z0 = casign(0,0);
	frac->escala_x = (double)ESC_MANDEL;
	frac->escala_y = frac->escala_x;
	frac->zoom_fact = 1.2;
	frac->color = palette(XK_5);
	frac->limit = 4;
	frac->mlx_ptr = mlx_init();
	frac->win_ptr = mlx_new_window(frac->mlx_ptr,frac->size_x,frac->size_y,"Los fractales de Ernesto");
	frac->image = mlx_new_image(frac->mlx_ptr,frac->size_x,frac->size_y);
	frac->key_pressed = 0;
	frac->button_pressed = 0;
	return (frac);
}

void	free_fract(t_fract *frac)
{
	int	i;

	i = -1;
	while (++i < frac->size_x)
		free(frac->win[i]);
	free(frac->win);
	free(frac->mlx_ptr);
	free(frac->win_ptr);
	printf("pepe\n");
	free(frac->color);
	free(frac);
	return ;
}

