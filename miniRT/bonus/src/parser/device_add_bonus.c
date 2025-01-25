/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   device_add_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/27 17:19:47 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_camera_center(t_field *field, char **content)
{
	t_vec3	aux;

	field->camera.center.vx = conv_v_unit(add_vec3(content[2]));
	aux = create_vect(0, 0, 1);
	field->camera.center.vy = prod_vectorial(aux, field->camera.center.vx);
	if (is_zero_vec(field->camera.center.vy))
		field->camera.center.vy = create_vect(0, 1, 0);
	field->camera.center.vz = prod_vectorial(field->camera.center.vx, \
			field->camera.center.vy);
}

int	get_camera(t_field *field, char *line)
{
	char	**content;
	t_vec3	aux;
	double	lambda;

	content = ft_split(line, ' ');
	field->camera.center.pos = add_vec3(content[1]);
	get_camera_center(field, content);
	field->camera.fov = ft_atoi(content[3]);
	if (field->camera.fov == 0)
		field->camera.observer = create_vect(LONG_MIN, LONG_MIN, LONG_MIN);
	else
	{
		lambda = -(field->mlx.size_x / 2 - FRAME) * PIXEL \
			/ tan((double)field->camera.fov / 2 / 180 * M_PI);
		aux = prod_cte_vector(lambda, field->camera.center.vx);
		field->camera.observer = suma_vector(field->camera.center.pos, aux);
	}
	ft_array_free(content, ft_array_size(content));
	return (0);
}

int	get_light(t_field *field, char *line)
{
	char	**content;
	t_light	*new_light;

	content = ft_split(line, ' ');
	new_light = malloc(sizeof(t_light));
	if (!new_light)
		return (1);
	new_light->pos = add_vec3(content[1]);
	new_light->ratio = ft_atof(content[2]);
	new_light->color = add_color(content[3]);
	new_light->next = NULL;
	ft_lightadd_back(&field->light, new_light);
	ft_array_free(content, ft_array_size(content));
	return (0);
}

int	get_ambient_light(t_field *field, char *line)
{
	char	**content;

	content = ft_split(line, ' ');
	field->ambient.ratio = ft_atof(content[1]);
	field->ambient.color = add_color(content[2]);
	ft_array_free(content, ft_array_size(content));
	return (0);
}

int	get_devices(t_field *field, char *line)
{
	char	**type;
	int		error;

	error = 0;
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "C") == 0)
	{
		error = get_camera(field, line);
		field->orig_camera = field->camera;
	}
	else if (ft_strcmp(type[0], "L") == 0)
		error = get_light(field, line);
	else if (ft_strcmp(type[0], "A") == 0)
		error = get_ambient_light(field, line);
	else if (ft_strcmp(type[0], "CHECKBOARD") == 0)
		error = get_checkboard(field, line);
	ft_array_free(type, ft_array_size(type));
	return (error);
}
