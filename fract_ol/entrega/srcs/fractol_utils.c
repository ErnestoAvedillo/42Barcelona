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

t_fract	*create_fract(int size_x, int size_y, int orig_x, int orig_y)
{
	t_fract	*frac;
	int		i;
	int		j;

	frac = (t_fract*)malloc(sizeof(t_fract));
	frac->win = (int **)malloc(size_x * sizeof(int));
	i = -1;
	j = -1;
	while (++i < size_x)
	{
		j = -1;
		frac->win[i] = (int *)malloc(size_y * sizeof(int));
		while (++j < size_y)
		{
			frac->win[i][j] = 0;
		}
	}
	frac->size_x = size_x;
	frac->size_y = size_y;
	frac->origin_x = orig_x;
	frac->origin_y = orig_y;
	//frac->z0 = (t_complex *)malloc(sizeof(t_complex));
	frac->z0.re = 0;
	frac->z0.im = 0;
	//frac->c = (t_complex *)malloc(sizeof(t_complex));
	frac->c.re = 0;
	frac->c.im = 0;
	return (frac);
}
