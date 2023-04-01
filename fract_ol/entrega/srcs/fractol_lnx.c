/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:24:07 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/04 11:28:02 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"

static int	print_help_message(void)
{
	ft_printf("=========Usage==========\n");
	ft_printf("Available fractals are\n");
	ft_printf("\tM - Mandelbrot\n");
	ft_printf("\tJ - Julia\n");
	ft_printf("\tT - Tricorn\n");
	ft_printf("\tB - Burningship\n");
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
	mlx_mouse_hook_pre(frac->win_ptr, mouse_events_pre, (t_fract *)frac);
	mlx_mouse_hook_rel(frac->win_ptr, mouse_events_rel, (t_fract *)frac);
	mlx_mouse_hook_mov(frac->win_ptr, mouse_events_mov, (t_fract *)frac);
	mlx_hook(frac->win_ptr, EVENT_DESTROY_NOTIFY, MASK_DESTROY_NOTIFY, \
			close_win, (t_fract *)frac);
	mlx_loop(frac->mlx_ptr);
	return (0);
}
