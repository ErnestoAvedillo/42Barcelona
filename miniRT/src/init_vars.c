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
bool init_vec(t_vector v, double i , double j, double k)
{
	v.x = i;
	v.y = j;
	v.z = k;
}
static bool init_cyl(t_cylinder cyl);
{

}

static bool init_sph(t_sphere sph)
{

}

static bool init_pln(t_plane pln)
{

}

int initvars (t_field field)
{
	init_cyl(field.cyl);
	init_sph(field.sph);
	init_pln(field.pln)
}