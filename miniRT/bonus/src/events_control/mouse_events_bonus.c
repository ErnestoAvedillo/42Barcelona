/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:50:25 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/30 12:19:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

/// @brief Select which events to realize depending on the mouse buttons press.
/// @param mouse	Event received
/// @param x		coord x of mouse
/// @param y		Coord Y of mouse
/// @param field	Struct with the information of the scene.
/// @return
// 	For testing add
//	print_pixel_values(x, y, field);
int	mouse_events_pre(int mouse, int x, int y, t_field *field)
{
	if (mouse == MOUSE_BTN_ROT_UP)
		zoom(-10, field);
	else if (mouse == MOUSE_BTN_ROT_DW)
		zoom(10, field);
	else if (mouse == MOUSE_BTN_MIDDLE)
		field->events.btn_cent_presd = 1;
	else if (mouse == MOUSE_BTN_RIGHT)
		field->events.btn_rght_presd = 1;
	else if (mouse == MOUSE_BTN_LEFT)
	{
		field->events.btn_left_presd = 1;
		x = x - field->mlx.size_x / 2;
		y = field->mlx.size_y / 2 - y;
		field->aux = create_vect(0, x, y);
	}
	return (0);
}

/// @brief Select which events to realize depending on the mouse
/// @brief buttons release.
/// @param mouse	Event received
/// @param x		coord x of mouse
/// @param y		Coord Y of mouse
/// @param field	Struct with the information of the scene.
/// @return
// 	For testing add
//	print_pixel_values(x, y, field);
int	mouse_events_rel(int mouse, int x, int y, t_field *field)
{
	if (mouse == MOUSE_BTN_MIDDLE)
		field->events.btn_cent_presd = 0;
	else if (mouse == MOUSE_BTN_RIGHT)
		field->events.btn_rght_presd = 0;
	if (mouse == MOUSE_BTN_LEFT && x > 0 && y > 0)
	{
		print_pixel_values(x, y, field);
		if (field->events.key_alt_press || field->events.key_ctrl_press)
			displ(field, x, y);
		if (field->events.key_shift_press)
			cam_rotate(field, x, y);
	}
	return (0);
}
