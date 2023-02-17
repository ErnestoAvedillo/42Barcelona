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

void fractol_draw (t_fract *frac, int (*fractal_func)(t_complex, t_complex))
{
    int i;
    int j;
    t_complex c;

    i = -1;
    while(i < frac->size_x)
    {
        j = -1;
        while(++j < frac->size_y)
        {
            c.re = i;
            c.im = j;
            frac->win[i][j] = fractal_func(frac->z0,c)
        }
    }
}
