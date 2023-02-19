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

t_fract	*create_fract(int size_x, int size_y, int orig_x, int orig_y \
					, int (*fractal_func)(t_complex, t_complex, int, int))
{
	t_fract	*frac;
	int		i;
	int		j;

	frac = (t_fract *)malloc(sizeof(t_fract));
	frac->win = (int **)malloc(size_x * sizeof(int *));
	i = -1;
	j = -1;
	while (++i < size_x)
	{
		j = -1;
		frac->win[i] = (int *) malloc(size_y * sizeof(int));
		while (++j < size_y)
		{
			frac->win[i][j] = 0;
		}
	}
	frac->function = fractal_func;
	frac->size_x = size_x;
	frac->size_y = size_y;
	frac->frame = 50;
	frac->origin_x = orig_x;
	frac->origin_y = orig_y;
	frac->z0.re = 0;
	frac->z0.im = 0;
	frac->escala = 200;
	frac->color = 0x777777;
	frac->repet = 200;
	frac->limit = 3;
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
