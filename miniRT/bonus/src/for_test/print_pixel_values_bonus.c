/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pixel_values_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/30 12:24:16 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

void	print_pixel_values(int x, int y, t_field *field)
{
	int	k;

	if (x < FRAME || y < FRAME || x > (field->mlx.size_x - FRAME) || \
		y > (field->mlx.size_y - FRAME))
		return ;
	k = (x - FRAME) + (y - FRAME) * (field->mlx.size_x - 2 * FRAME);
	printf("*********************************************************\n");
	ft_print_vec3("Posicion del punto de luz: ", field->light->pos);
	printf("Datos del punto visualizado por la cámara:\n");
	ft_print_vec3("El Vector camara es", field->camera.int_vp[k].pt.pt);
	ft_print_vec3("El Vector direccional  es ", field->camera.int_vp[k].pt.v);
}

/*
static double	calculate_behind_pts(t_int_pts vp, t_vec_pos vl_pt, t_geom *ptr)
{
	t_vec3		aux;
	double		dist[3];
	t_vec_pos	*out;

	aux = resta_vector(vl_pt.pt, vp.pt.pt);
	dist[0] = modulo_vector(aux);
	dist[1] = LONG_MAX;
	dist[2] = LONG_MAX;
	out = get_int_pt(&vl_pt, ptr);
	if (out != NULL)
	{
		aux = resta_vector(vl_pt.pt, out[0].pt);
		dist[1] = modulo_vector(aux);
		if (prod_escalar(aux, vl_pt.v) < 0)
			dist[1] = LONG_MAX;
		aux = resta_vector(vl_pt.pt, out[1].pt);
		dist[2] = modulo_vector(aux);
		if (prod_escalar(aux, vl_pt.v) < 0)
			dist[2] = LONG_MAX;
	}
	free(out);
	if (dist[0] > dist[1] || dist[0] > dist[2])
		return (true);
	return (false);
}

static bool	is_behind_srf(t_int_pts vp, t_vec_pos vl_pt, t_geom *geo)
{
	t_geom	*ptr;

	ptr = geo;
	while (ptr)
	{
		if (ptr != vp.geom)
		{
			if (calculate_behind_pts(vp, vl_pt, ptr))
				return (true);
		}
		ptr = ptr->next;
	}
	return (false);
}

static double	get_difuse(t_vec_pos vp, t_vec_pos vl_pt, double amb_rate)
{
	double	aux;

	aux = prod_escalar(vp.v, vl_pt.v);
	//	aux = pow(aux, 4);
	if (aux < amb_rate)
		aux = amb_rate;
	return (aux);
}

static double	get_specular(t_vec_pos vp, t_vec_pos vl_pt, \
	t_vec_pos pixl, double light_ratio)
{
	double	aux;
	t_vec3	out;

	aux = 2 * prod_escalar(vp.v, vl_pt.v);
	if (aux < 0)
		return (0);
	out = resta_vector(prod_cte_vector(aux, vp.v), vl_pt.v);
	aux = prod_escalar(out, pixl.v);
	if (aux > 0)
		return (0);
	aux = pow(aux, 8);
	aux = fmin(aux, light_ratio);
	return (aux);
}

t_color	set_pixel_color_print(t_int_pts vp, t_field *field, t_vec_pos pixl)
{
	t_vec_pos	v_luz_pt;
	t_color		out[5];
	double		aux;
	t_light		*lght;

	out[3].r = 0;
	out[3].g = 0;
	out[3].b = 0;
	out[3].a = 0;
	rgb_to_hsl(&out[3]);
	if (vp.pt.pt.x == LONG_MAX && vp.pt.pt.z == LONG_MAX && \
		vp.pt.pt.z == LONG_MAX)
		out[4] = field->ambient.color;
	else
	{
		lght = field->light;
		while (lght)
		{
			printf("*********************\n");
			print_color_values("Color in ", vp.pt.c);
			print_color_values("Color in luz ", lght->color);
			v_luz_pt.pt = lght->pos;
			v_luz_pt.v = conv_v_unit(resta_vector(v_luz_pt.pt, vp.pt.pt));
			v_luz_pt.c = lght->color;
			if (is_behind_srf(vp, v_luz_pt, field->geom))
			{
				out[0] = mult_color(v_luz_pt.c, field->ambient.ratio);
				print_color_values("Color bh ambient ", out[0]);
				out[3] = prod_color(out[0], vp.pt.c);
				hsl_to_rgb(&out[3]);
			}
			else
			{
				out[0] = mult_color(v_luz_pt.c, field->ambient.ratio);
				print_color_values("Color ambient ", out[0]);
				aux = get_difuse(vp.pt, v_luz_pt, field->ambient.ratio);
				printf("Valor difuse = %f\n", aux);
				out[1] = mult_color(v_luz_pt.c, aux);
				print_color_values("Color difuse ", out[1]);
				out[2] = mix_color(out[0], out[1]);
				print_color_values("Color light mixed ", out[2]);
				aux = get_specular(vp.pt, v_luz_pt, pixl, lght->ratio);
				printf("Valor especular = %f\n", aux);
				out[1] = mult_color(v_luz_pt.c, aux);
				print_color_values("Color especular ", out[1]);
				out[2] = mix_color(out[1], out[2]);
				out[3] = mix_color(out[3], out[2]);
				print_color_values("Color total ", out[3]);
			}
			lght = lght->next;
		}
		out[4] = prod_color(out[3], vp.pt.c);
		hsl_to_rgb(&out[4]);
		print_color_values("Color out ", out[4]);
		printf("*********************\n");
	}
	return (out[4]);
}

void	print_color_values(char *s, t_color c)
{
	printf("%s", s);
	printf("R=%x, G=%x, B=%x, a=%x, H=%f, S=%f, L=%f\n", \
	c.r, c.g, c.b, c.a, c.h, c.s, c.l);
}

static bool	is_bhd_cam(t_vec3 pint, t_vec3 pi, t_vec3 vx)
{
	t_vec3		temp;
	double		aux;

	temp = conv_v_unit(resta_vector(pint, pi));
	aux = prod_escalar(vx, temp);
	if (aux > 0)
		return (false);
	return (true);
}

static t_int_pts	get_min_vect(t_int_pts cur, t_vec_pos *new,
						t_geom *geom, t_vec_pos *pixl)
{
	t_int_pts	out;
	double		long_cur;
	int			i;

	out = cur;
	if (!new)
		return (cur);
	long_cur = modulo_vector(resta_vector(cur.pt.pt, pixl->pt));
	i = -1;
	while (++i < 2)
	{
		if (modulo_vector(resta_vector(new[i].pt, pixl->pt)) < long_cur)
		{
			out.pt = new[i];
			out.pt.c = geom->color;
			out.geom = geom;
		}
	}
	return (out);
}

t_int_pts	calcula_color(int pixel, t_field *field)
{
	t_geom		*ptr;
	t_vec_pos	*out;
	t_int_pts	vp_int;
	t_vec_pos	*vps;
	int			i;

	ptr = field->geom;
	vps = &field->camera.field_vp[pixel];
	vp_int.pt = init_vp(vps->c);
	vp_int.geom = NULL;
	while (ptr)
	{
		out = get_int_pt(vps, ptr);
		i = -1;
		while (++i < 2)
		{
			printf("==============================\n");
			if (out && !is_bhd_cam(out[i].pt, vps->pt, field->camera.center.vx))
			{
				vp_int = get_min_vect(vp_int, out, ptr, vps);
				vp_int.pt.v = prod_cte_vector(ptr->sense, vp_int.pt.v);
				vp_int.ref.vz = vp_int.pt.v;
				vp_int.ref.vx = conv_v_unit(prod_vectorial(create_vect(0, 0, 1),\
							 vp_int.ref.vz));
				vp_int.ref.vy = conv_v_unit(prod_vectorial(vp_int.ref.vz, \
							vp_int.ref.vx));
			}
			if (out)
				ft_print_vec3("El punto out es ", out->pt);
			else
				printf("No intersection \n");
			ft_print_vec3("El punto vpint es ", vp_int.pt.pt);
			ft_print_vec3("El Vector direccional del pixel es ", vps->v);
			ft_print_vec3("El Vector posicion del pixel  es ", vps->pt);
			print_color_values("El color resultante es: ", vp_int.pt.c);
			printf("==============================\n");
			if (ptr->type == PLANE)
				i++;
		}
		ptr = ptr->next;
		free (out);
	}
	if (vp_int.geom && vp_int.geom->bumpmap.is_bumpmap)
		set_pixel_color_bumpmap(&vp_int, field);
	vp_int.pt.c = set_pixel_color_print(vp_int, field, *vps);
	return (vp_int);
}

void	print_pixel_values(int x, int y, t_field *field)
{
	int			k;
	t_color		c;
	t_int_pts	inters;
	t_img_buff	buf;

	if (x < FRAME || y < FRAME || x > field->mlx.size_x - FRAME || \
		y > field->mlx.size_y - FRAME)
		return ;
	buf.buffer = mlx_get_data_addr(field->mlx.img, &buf.pixel_bits,
			&buf.line_bytes, &buf.endian);
	k = y * buf.line_bytes + x * buf.pixel_bits / 8;
	c.b = buf.buffer[k];
	c.g = buf.buffer[k + 1];
	c.r = buf.buffer[k + 2];
	c.a = buf.buffer[k + 3];
	k = (x - FRAME) + (y - FRAME) * (field->mlx.size_x - 2 * FRAME);
	printf("========================Datos generales=======================\n");
	ft_print_vec3("El observador de la cámara está en: ", \
	field->camera.observer);
	printf("==============================================================\n");
	ft_print_vec3("El centro de la cámara está en: ", field->camera.center.pos);
	ft_print_vec3("El observador respecto a la cámara está en: ", \
	resta_vector(field->camera.observer, field->camera.center.pos));
	printf("Modulo vector observador cámara está en: %f\n", \
	modulo_vector(resta_vector(field->camera.observer, \
	field->camera.center.pos)));
	printf("El punto es x=%i, y=%i\n", x, y);
	ft_print_vec3("El punto de luz está en: ", field->light->pos);
	printf("Datos del vector del pixel de la cámara:\n");
	ft_print_vec3("El Vector camara es", field->camera.field_vp[k].pt);
	ft_print_vec3("El Vector direccional  es", field->camera.field_vp[k].v);
	print_color_values("El Color del objeto es: ", field->camera.field_vp[k].c);
	printf("Datos del punto visualizado por la cámara:\n");
	ft_print_vec3("El Vector camara es", field->camera.int_vp[k].pt.pt);
	ft_print_vec3("El Vector direccional  es ", field->camera.int_vp[k].pt.v);
	print_color_values("El color resultante es: ", \
	field->camera.int_vp[k].pt.c);
	print_color_values("El color de la pantallea es: ", c);
	inters = calcula_color(k, field);
	printf("Datos del punto calculado:\n");
	ft_print_vec3("El Vector int es", inters.pt.pt);
	ft_print_vec3("El Vector direccion int  es ", inters.pt.v);
	print_color_values("El color resultante es: ", inters.pt.c);
	printf("==============================================================\n");
}
*/
