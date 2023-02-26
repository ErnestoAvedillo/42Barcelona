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

/* 
Demostración de la función
								  (c = d * i)
		(c+d*i)         (theta *i)
(a + b*i)       = (m * e         )

    (c + d*i)   (i*theta)*(c + d*i)
= m          *e                     =

	c    ln(m)*d*i    (-d * theta)    (c*theta*i)
= m   * e          * e             * e            =

   c    (-d * theta)    (ln(m)*d + c*theta)*i
= m  * e             * e
*/
t_complex	csqr(t_complex a)
{
	t_complex	c;
	double		module;
	double		theta;
	double		aux1;
	double		aux2;

	module = cmod(a);
	if (module == 0)
		return (a);
	theta = cdeg (a);
	aux1 = pow(module, 2) ;
	aux2 = 2 * theta;
	c.re = aux1 * cos(aux2);
	c.im = aux1 * sin(aux2);
	return (c);
}
