/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:19:31 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/02 12:19:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include"../mlx/mlx.h"
# include<math.h>
# include<stdio.h>
# include<bool.h>
/// #include<limits.h>
# ifdef KEY_LNX_H
#  include "../inc/key_mouse_cod_lnx.h"
# endif
# ifdef KEY_MAC_H
#  include "../inx/key_mouse_cod_mac.h"
# endif

# include<time.h>


typedef struct s_img_buff
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img_buff;

typedef struct s_color{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_vector {
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_sphere {
	t_vector	pt;
	double		r;
	t_color		color;
}	t_sphere;

typedef struct s_cylinder {
	t_vector	pt1;
	t_vector	pt2;
	double		r;
	t_color		color;
}	t_cylinder;

typedef struct s_plane {
	t_vector	pt1;
	t_vector	dir1;
	t_vector	dir2;
	double		wide;
	double		high;
	t_color		color;
}	t_plane;

typedef struct s_mouse_pos
{
	int	x;
	int	y;
}	t_mouse_pos;

typedef struct s_sph_list
{
	t_sphere 
}	t_sph_list;


typedef struct s_field
{
	t_sph_list	*frst_sph;
	t_cyl_list	*frst_cyl;
	t_pln_list	*frst_pln;
	t_color		bck_col;
	t_vector	camera;
	t_vector	light;
}	t_field;

#endif
