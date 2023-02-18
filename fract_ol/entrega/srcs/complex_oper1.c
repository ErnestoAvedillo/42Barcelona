/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_oper1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 13:08:22 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/12 13:08:33 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

t_complex	csum(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re + b.re;
	c.im = a.im + b.im;
	return (c);
}

t_complex	csub(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re - b.re;
	c.im = a.im - b.im;
	return (c);
}

t_complex	cmul(t_complex a, t_complex b)
{
	t_complex	c;

	c.re = a.re * b.re - a.im * b.im;
	c.im = a.re * b.im + a.im * b.re;
	return (c);
}

t_complex	cdiv(t_complex a, t_complex b)
{
	t_complex	c;
	t_complex	d;
	t_complex	e;

	e.re = b.re;
	e.im = -b.im;
	c = cmul(a, e);
	d = cmul(b, e);
	c.re /= d.re;
	c.im /= d.re;
	return (c);
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
t_complex	cpower(t_complex a, t_complex b)
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
	aux1 = pow(module, b.re) / exp(b.im * theta);
	aux2 = log(module) * b.im + b.re * theta;
	c.re = aux1 * cos(aux2);
	c.im = aux1 * sin(aux2);
	return (c);
}
