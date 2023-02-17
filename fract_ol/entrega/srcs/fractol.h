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

typedef struct s_fract {
    int         **win;
    int         size_x;
    int         size_y;
    int         origin_x;
    int         origin_y;
    t_complex   z0;
    t_complex   c;
} t_fract;

#define MAX 0xFFFFFF
#define ITER 500

int			fract_calc(t_complex c, t_complex z0);
//fractol_utils
t_fract		*create_fract(int size_x, int size_y, int orig_x, int orig_y);
// complex_oper0
t_complex	casign(double a, double b);
t_complex	cequal(t_complex b);
double		cmod(t_complex z);
double		cdeg (t_complex z);
// complex_oper1
t_complex	csum(t_complex a, t_complex b);
t_complex	csub(t_complex a, t_complex b);
t_complex	cmul(t_complex a, t_complex b);
t_complex	cdiv(t_complex a, t_complex b);
t_complex	cpower(t_complex a, t_complex b);
//mandelbrot
void		win_mandel(t_fract *frac);
int			mandelbrot(t_fract *frac);
//fractol_draw
void fractol_draw (t_fract *frac, int (*fractal_func)(t_complex, t_complex));

#endif
