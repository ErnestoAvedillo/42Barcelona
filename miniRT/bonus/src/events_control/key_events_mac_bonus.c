/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_mac_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:51:44 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/27 17:44:57 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

static void	restart_screen(t_field *field)
{
	free(field->camera.int_vp);
	free(field->camera.field_vp);
	dump_mem_2_scr(field);
}

static void	key_events_resets(int key, t_field *field)
{
	if (key == XK_R || key == XK_L)
	{
		if (key == XK_R)
		{
			free(field->camera.int_vp);
			free(field->camera.field_vp);
			field->camera = field->orig_camera;
			printf("Restarting Camera\n");
		}
		else if (key == XK_L)
		{
			ft_free_light(&field->light);
			field->light = ft_clone_lightning(field->orig_light);
			printf("Restarting Light\n");
		}
	}
}

int	key_events_press(int key, t_field *field)
{
	if (key == XK_CTRL)
	{
		field->events.key_ctrl_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
	}
	else if (key == XK_ALT)
	{
		field->events.key_alt_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
	}
	else if (key == XK_SHIFT)
	{
		field->events.key_shift_press = 1;
		if (!field->events.btn_left_presd)
			field->aux = create_vect(0, 0, 0);
	}
	key_events_resets(key, field);
	return (0);
}

int	key_events_release(int key, t_field *field)
{
	if (key == XK_ESC)
		ft_close(field);
	else if (key == XK_CTRL)
	{
		field->events.key_ctrl_press = 0;
		restart_screen(field);
	}
	else if (key == XK_ALT)
	{
		field->events.key_alt_press = 0;
		restart_screen(field);
	}
	else if (key == XK_SHIFT)
	{
		field->events.key_shift_press = 0;
		restart_screen(field);
	}
	else if (key == XK_L)
		restart_screen(field);
	else if (key == XK_R)
		dump_mem_2_scr(field);
	return (0);
}
