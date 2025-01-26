/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 12:29:43 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/19 12:30:03 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_fract *frac)
{
	free_fract(frac);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}
