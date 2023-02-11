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

int fract_calc(double complex c, double complex z0)
{
    int i;
    double complex znext;
    while (i <= max)
    {
        znext = cpow(z0,2) + c;
        modulo = cabs(z0-znext);
        printf ("convergencia %f + %f i /n", creal(z0-znext), cimag(z0-znext), modulo );
        getchar();
    }
    
}