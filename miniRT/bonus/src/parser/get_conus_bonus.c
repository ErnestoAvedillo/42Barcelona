/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_conus_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/26 18:18:38 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	get_optional_values(t_field *field, t_geom *cone, char **content)
{
	if (ft_array_size(content) == 7)
	{
		if (ft_strcmp(content[6], "NO_CHECKBOARD") == 0)
			cone->is_chckbd = false;
		else
			cone->bumpmap = get_bumpmap(content[6], field);
	}
	if (ft_array_size(content) == 8)
	{
		if (ft_strcmp(content[7], "NO_CHECKBOARD") == 0)
			cone->is_chckbd = false;
		else
			cone->bumpmap = get_bumpmap(content[7], field);
	}
}

t_geom	*get_conus(char *line, t_field *field)
{
	t_geom	*cone;
	char	**content;

	content = ft_split(line, ' ');
	cone = malloc(sizeof(t_geom));
	cone->type = CONUS;
	cone->vp.pt = add_vec3(content[1]);
	cone->vp.v = conv_v_unit(add_vec3(content[2]));
	cone->r = ft_atof(content[3]) / 2;
	cone->height = ft_atof(content[4]);
	cone->color = add_color(content[5]);
	cone->sense = 1;
	cone->next = NULL;
	cone->axis.pos = cone->vp.pt;
	cone->axis.vx = cone->vp.v;
	cone->axis.vy = conv_v_unit(prod_vectorial(create_vect(0, 0, 1), \
			cone->axis.vx));
	cone->axis.vz = conv_v_unit(prod_vectorial(cone->axis.vx, cone->axis.vy));
	cone->bumpmap.is_bumpmap = false;
	cone->is_chckbd = true;
	get_optional_values(field, cone, content);
	ft_array_free(content, ft_array_size(content));
	return (cone);
}
