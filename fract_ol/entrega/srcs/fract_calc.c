/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:11 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/11 14:58:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int fract_calc(t_complex c, t_complex z0)
{
    int i;
    t_complex znext;
    double modulo;

    i = 0;
    while (i <= MAX)
    {
        znext = csum(z0, c);
        modulo = cmod(znext);
        printf ("convergencia %f + %f i = %f /n", znext.re, znext.im, modulo );
        getchar();
        i++;
    }
    return(i);
}