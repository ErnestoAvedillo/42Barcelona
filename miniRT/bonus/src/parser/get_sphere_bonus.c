/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sphere_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/26 18:18:49 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_optional_values(t_field *field, t_geom *sphere, char **content)
{
	if (ft_array_size(content) == 5)
	{
		if (ft_strcmp(content[4], "NO_CHECKBOARD") == 0)
			sphere->is_chckbd = false;
		else
			sphere->bumpmap = get_bumpmap(content[4], field);
	}
	if (ft_array_size(content) == 6)
	{
		if (ft_strcmp(content[5], "NO_CHECKBOARD") == 0)
			sphere->is_chckbd = false;
		else
			sphere->bumpmap = get_bumpmap(content[5], field);
	}
}

t_geom	*get_sphere(char *line, t_field *field)
{
	t_geom	*sph;
	char	**content;

	content = ft_split(line, ' ');
	sph = malloc(sizeof(t_geom));
	sph->type = SPHERE;
	sph->vp.pt = add_vec3(content[1]);
	sph->vp.v = create_vect(0, 0, 0);
	sph->r = ft_atof(content[2]) / 2;
	sph->color = add_color(content[3]);
	sph->sense = 1;
	sph->next = NULL;
	sph->bumpmap.is_bumpmap = false;
	sph->axis.pos = sph->vp.pt;
	sph->axis.vx = create_vect(1, 0, 0);
	sph->axis.vy = create_vect(0, 1, 0);
	sph->axis.vz = create_vect(0, 0, 1);
	sph->is_chckbd = true;
	get_optional_values(field, sph, content);
	ft_array_free(content, ft_array_size(content));
	return (sph);
}
