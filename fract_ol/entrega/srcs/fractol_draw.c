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

void fractol_draw (t_fract *frac)
{
    int i;
    int j;
    int result;
    t_complex c;

    i = -1;
    while(++i < frac->size_x)
    {
        j = -1;
        while(++j < frac->size_y)
        {
            c.re = ((double)i - frac->origin_x) / frac->escala;
            c.im = ((double)j - frac->origin_y) / frac->escala;
            result = frac->function(frac->z0, c, frac->repet, frac->limit);
            mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, i, j, result * frac->color);
        } 
    }
}
