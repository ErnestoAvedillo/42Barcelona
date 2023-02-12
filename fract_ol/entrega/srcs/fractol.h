/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 12:27:21 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/04 12:29:35 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
#include "../mlx/mlx.h"
#include"../libft/libft.h"
#include<math.h>
#include<stdio.h>

typedef struct s_complex {
    double re;
    double im;
}   t_complex;

#define MAX 0xFFFFFF

int     fract_calc(t_complex c, t_complex z0);
//complex_oper0
t_complex casign(double a, double b);
double cmod(t_complex z);
double cdeg (t_complex z);
t_complex csum(t_complex a, t_complex b);
t_complex csub(t_complex a, t_complex b);
//complex_oper1
t_complex cmul(t_complex a, t_complex b);
t_complex cdiv(t_complex a, t_complex b);
t_complex cpower(t_complex a, t_complex b);

#endif
