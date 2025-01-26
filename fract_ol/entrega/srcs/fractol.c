/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:24:07 by eavedill          #+#    #+#             */
/*   Updated: 2023/04/01 14:05:01 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	print_help_message(void)
{
	ft_printf("=========Usage==========\n");
	ft_printf("./fractol fractal real imaginary\n");
	ft_printf("fractal: parameter can be\n");
	ft_printf("\tM - Mandelbrot\n");
	ft_printf("\tI- Julia\n");
	ft_printf("\tT - Tricorn\n");
	ft_printf("\tB - Burningship\n");
	ft_printf("=========Numeric Prameters in real format======\n");
	ft_printf("real:0.00 ; imaginary:0.00 \n");
	ft_printf("=========Mouse Usage instructions==========\n");
	ft_printf("\tLeft Button to move fractal\n");
	ft_printf("\tWheel to zoom in & zoom out\n");
	ft_printf("\tRight Button to change form (except for Tricorn)\n");
	ft_printf("=========Key Usage instructions==========\n");
	ft_printf("\tKeys 1 to 6 to change color pallete\n");
	ft_printf("\tKey b to change to Burning ship\n");
	ft_printf("\tKey m to change to Mandelbrot\n");
	ft_printf("\tKey j to change to Julia\n");
	ft_printf("\tKey t to change to Tricorn\n");
	return (0);
}

int	main(int av, char **ac)
{
	t_fract		*frac;
	int			fract_type;
	t_complex	init_c;

	if (av < 2)
		return (print_help_message());
	fract_type = get_fractal(ac[1]);
	if (fract_type == 0)
		return (print_help_message());
	init_c = get_z0(fract_type, av, ac);
	frac = create_fract(fract_type, init_c);
	fractol_draw(frac);
	mlx_key_hook(frac->win_ptr, key_events, (t_fract *)frac);
	mlx_hook(frac->win_ptr, EVENT_BUTTON_PRESS, 1L << MASK_BUTTON_PRESS, \
			mouse_events_pre, (t_fract *)frac);
	mlx_hook(frac->win_ptr, EVENT_BUTTON_RELEASE, 1L << MASK_BUTTON_RELEASE, \
	mouse_events_rel, (t_fract *)frac);
	mlx_hook(frac->win_ptr, EVENT_MOTION_NOTIFY, 1L << MASK_MOTION_NOTIFY, \
	mouse_events_mov, (t_fract *)frac);
	mlx_hook(frac->win_ptr, EVENT_DESTROY_NOTIFY, 1L << MASK_DESTROY_NOTIFY, \
	close_win, (t_fract *) frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}
