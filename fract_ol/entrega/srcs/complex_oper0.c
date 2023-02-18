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

t_complex	casign(double a, double b)
{
	t_complex	c;

	c.re = a;
	c.im = b;
	return (c);
}

t_complex	cequal(t_complex b)
{
	t_complex a;

	a.re = b.re;
	a.im = b.im;
	return (a);
}

double	cmod(t_complex z)
{
	double	i;

	i = sqrt(pow(z.re, 2) + pow(z.im, 2));
	return (i);
}

double	cdeg(t_complex z)
{
	double	i;

	i = atan2(z.im, z.re);
	return (i);
}
