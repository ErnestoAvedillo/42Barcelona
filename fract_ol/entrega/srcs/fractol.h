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
#include "/usr/include/X11/keysymdef.h"
/// #include<limits.h>
#include<time.h>

typedef struct s_complex {
	double	re;
	double	im;
}   t_complex;

typedef struct s_mouse_pos {
	int	x;
	int	y;
}   t_mouse_pos;

typedef	struct	s_color{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_fract {
	int			(*function)(t_complex, t_complex, int, int);
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image;
	int			**win;
	int			size_x;
	int			size_y;
	int			frame;
	double origin_x;
	double origin_y;
	t_complex	z0;
	int			escala;
	double 		zoom_fact;
	t_color 	color;
	int			repet;
	int			limit;
	t_mouse_pos	mouse_pos;
} t_fract;

#define XK_uparrow 0xff52	 /* U+2191 UPWARDS ARROW */
#define XK_downarrow 0xff54	 /* U+2193 DOWNWARDS ARROW */

#define MAX 0xFFFFFFFFF
#define ITER 20
#define MITTE_IMG_X 355
#define MITTE_IMG_Y 355

//int			fract_calc(t_complex c, t_complex z0);
//fractol_utils
t_fract		*create_fract(int size_x, int size_y, int orig_x, int orig_y \
						, int (*fractal_func)(t_complex, t_complex, int, int));
void		free_fract (t_fract *frac);
t_color		new_color(int r, int g, int b, int a);
void		put_pixel_color(char *pixel, t_color color, int factor);
// complex_oper0
t_complex	casign(double a, double b);
t_complex	cequal(t_complex b);
double		cmod(t_complex z);
double		cdeg (t_complex z);
t_complex	csqr(t_complex a);
// complex_oper1
t_complex	csum(t_complex a, t_complex b);
t_complex	csub(t_complex a, t_complex b);
t_complex	cmul(t_complex a, t_complex b);
t_complex	cdiv(t_complex a, t_complex b);
t_complex	cpower(t_complex a, t_complex b);
//mandelbrot
void		win_mandel(t_fract *frac);
int			mandelbrot(t_complex z0, t_complex c,int iter,int limit);
//fractol_draw
void		fractol_draw (t_fract *frac);
//close_win
int	close_win(t_fract *frac);
//keyevents
int key_events(int key, t_fract *frac);
//mouse_events
int mouse_events_pre(int mouse, int x, int y, t_fract *frac);
int mouse_events_rel(int mouse, int x, int y, t_fract *frac);
int mouse_events_mov(int mouse, int x, int y, t_fract *frac);
#endif
