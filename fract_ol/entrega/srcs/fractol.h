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
# include"../mlx/mlx.h"
# include"../printf/ft_printf_bonus.h"
# include<math.h>
# include<stdio.h>
/// #include<limits.h>
# ifdef KEY_MOUSE_COD_LNX_H
#  include "key_mouse_cod_lnx.h"
# endif
# ifdef KEY_MOUSE_COD_MAC_H
#  include "key_mouse_cod_mac.h"
# endif

# include<time.h>

typedef struct s_complex {
	double	re;
	double	im;
}	t_complex;

typedef struct s_mouse_pos
{
	int x;
	int y;
} t_mouse_pos;

typedef struct s_indexes
{
	int	i;
	int	j;
	int	k;
} t_indexes;

typedef struct s_img_buff
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
} t_img_buff;

typedef struct s_color{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_fract {
	int			fract_code;
	int			(*function)(t_complex, t_complex, int);
	void		*mlx_ptr;
	void		*win_ptr;
	void		*image;
	int			size_x;
	int			size_y;
	int			frame;
	t_complex	c1;
	t_complex	c;
	t_complex	z0;
	double		escala_x;
	double		escala_y;
	double		zoom_fact;
	uint		*color;
	int			limit;
	t_mouse_pos	mouse_pos;
	int			button_pressed;
	int			key_pressed;
}	t_fract;

# define FRACT_MAND	1
# define FRACT_JULIA 2
# define FRACT_BURN 3
# define FRACT_TRICORN 4

# define MOUSE_BTN_LEFT 1
# define MOUSE_BTN_RIGHT 2
# define MOUSE_BTN_MIDDLE 3
# define MOUSE_BTN_ROT_UP 4
# define MOUSE_BTN_ROT_DW 5

# define SCALE_UP 1
# define SCALE_DW 0

# define SIZE_X 1000
# define SIZE_Y 750

# define ORIG_X_MANDEL -2.5
# define ORIG_Y_MANDEL -1.5
# define ESC_MANDEL 0.004

# define ORIG_X_JULIA -2.1
# define ORIG_Y_JULIA -1.6
# define ESC_JULIA 0.004

# define ORIG_X_BURNING -2.7
# define ORIG_Y_BURNING -2.4
# define ESC_BURNING 0.005

# define ORIG_X_TRICORN -3
# define ORIG_Y_TRICORN -2.4
# define ESC_TRICORN 0.006

# define ORIG_INF_RE 2
# define ORIG_INF_IM 2

# define MAX 0xFFFFFFFFF
# define ITER 100
# define MITTE_IMG_X 355
# define MITTE_IMG_Y 355
// eventslist
// Key	Event	 	Key	Event	 	Key	Event
# define EVENT_KEY_PRESS 02
# define EVENT_KEY_RELEASE 03
# define EVENT_BUTTON_PRESS 04
# define EVENT_BUTTON_RELEASE 05
# define EVENT_MOTION_NOTIFY 06
# define EVENT_DESTROY_NOTIFY 17
// Key	Event	 	Key	Event	 	Key	Event
# define MASK_KEY_PRESS 1L<<0
# define MASK_KEY_RELEASE 1L<<1
# define MASK_BUTTON_PRESS 1L<<2
# define MASK_BUTTON_RELEASE 1L<<3
# define MASK_MOTION_NOTIFY 1L<<6
# define MASK_DESTROY_NOTIFY 1L<<17

//int			fract_calc(t_complex c, t_complex z0);
//fractol_utils
t_fract		*create_fract(int fract_type);
void		free_fract(t_fract *frac);
//void		put_pixel_color(char *pixel, uint color);
int			get_fractal(char *name);
//palette
void		palette(int n, uint *color_pal);
uint		new_color(uint r, uint g, uint b, uint a);
// complex_oper0
t_complex	casign(double a, double b);
t_complex	cequal(t_complex b);
double		cmod(t_complex z);
double		cdeg(t_complex z);
t_complex	csqr(t_complex a);
// complex_oper1
t_complex	csum(t_complex a, t_complex b);
t_complex	csub(t_complex a, t_complex b);
t_complex	cmul(t_complex a, t_complex b);
t_complex	cdiv(t_complex a, t_complex b);
t_complex	cpower(t_complex a, t_complex b);
//mandelbrot
int			mandelbrot(t_complex z0, t_complex c, int limit);
void		conf_mandel(t_fract *frac);
// julia
int			julia(t_complex z0, t_complex c, int limit);
void		conf_julia(t_fract *frac);
// tricorn
int			tricorn(t_complex z0, t_complex c, int limit);
void 		conf_tricorn(t_fract *frac);
// fractol_draw
void		fractol_draw(t_fract *frac);

void		new_scale(int sense, t_fract *fract, int x, int y);
//close_win
int			close_win(t_fract *frac);
//keyevents
int			key_events(int key, t_fract *frac);
//mouse_events
int			mouse_events_pre(int mouse, int x, int y, t_fract *frac);
int			mouse_events_rel(int mouse, int x, int y, t_fract *frac);
int			mouse_events_mov(int x, int y, t_fract *frac);
//int mouse_events_mov(int mouse, int x, int y, t_fract *frac);
//burning_ship
int			burning(t_complex z0, t_complex c, int limit);
void		conf_burning(t_fract *frac);
#endif
