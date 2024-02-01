/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/02 12:23:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<../inc/miniRT.h>
t_vector init_vec()
{
	t_vector *v;

	v = (t_vector*) malloc (sizeof(t_vector));
	v.x = 0;
	v.y = 0;
	v.z = 0;
}
t_cylinder *init_cyl( )
{
	t_cylinder	*cyl;
	
	cyl = (t_cylinder*) malloc (sizeof(t_cylinder));
	cyl->pt1 = init_vec();
	cyl->pt2 = init_vec();

}

t_sphere *init_sph( )
{
	t_sphere	*sph;


}

t_plane *init_pln( )
{
	t_plane	*pln;

}

t_field *initvars (t_field field)
{
	t_field *field

	field = (t_field *) malloc(sizeof(t_field));
	init_cyl(field.cyl);
	init_sph(field.sph);
	init_pln(field.pln)
}