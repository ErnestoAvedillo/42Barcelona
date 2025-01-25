/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_add_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 20:17:30 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/21 14:25:14 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

int	get_geom(t_field *field, char *line)
{
	t_geom	*temp;
	char	**type;

	temp = NULL;
	type = ft_split(line, ' ');
	if (ft_strcmp(type[0], "sp") == 0)
		temp = get_sphere(line, field);
	else if (ft_strcmp(type[0], "pl") == 0)
		temp = get_plane(line, field);
	else if (ft_strcmp(type[0], "cy") == 0)
		temp = get_cylinder(line, field);
	else if (ft_strcmp(type[0], "cn") == 0)
		temp = get_conus(line, field);
	else if (ft_strcmp(type[0], "tr") == 0)
		temp = get_triang(line, field);
	ft_geomadd_back(&field->geom, temp);
	ft_array_free(type, ft_array_size(type));
	return (0);
}
