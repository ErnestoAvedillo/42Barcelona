/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_oper0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:08:22 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/12 13:08:33 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_complex casign(double a, double b)
{
    t_complex c;

    c.re =  a;
    c.im =  b;
    return (c);
}

double cmod(t_complex z)
{
    double i;

    i = sqrt(pow(z.re, 2) + pow(z.im,2));
    return (i);
}

double cdeg (t_complex z)
{
    double i;

    i = atan2(z.re, z.im);
    return (i);
}

t_complex sum(t_complex a, t_complex b)
{
    t_complex   c;

    c.re =  a.re + b.re;
    c.im =  a.im + b.im;
    return (c);
}

t_complex csub(t_complex a, t_complex b)
{
    t_complex   c;

    c.re =  a.re - b.re;
    c.im =  a.im - b.im;
    return (c);
}


