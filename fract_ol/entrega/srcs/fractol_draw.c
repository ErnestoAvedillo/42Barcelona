/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:11:39 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/17 19:12:36 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

void fractol_draw (t_fract *frac)
{
	int i;
	int j;
	int k;
	int result;
//	clock_t start;
//	clock_t end;
//	clock_t start1;
//	clock_t end1;
	t_complex c;
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(frac->image, &pixel_bits, &line_bytes, &endian);

	i = frac->frame;
	k = 0;
	while(++i < frac->size_x - frac->frame * 2)
	{
		j = frac->frame;
		while(++j < frac->size_y - frac->frame * 2)
		{
			c.re = ((double)i - frac->origin_x) / frac->escala;
			c.im = ((double)j - frac->origin_y) / frac->escala;
			//start = clock();
			result = frac->function(frac->z0, c, frac->repet, frac->limit);
			//end = clock();
			//mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, i, j, result * frac->color);
			put_pixel_color (&buffer[j * line_bytes + i * pixel_bits / 8 ] , frac->color, result);
			//if ((double) (end - start) > 40)
			//	printf("tiempo transcurrido %f %d %i %f %f\n",(double) (end - start) / CLOCKS_PER_SEC, i, j, c.re, c.im);
			k++;
		} 
	}
	//start1 = clock();
	mlx_put_image_to_window(frac->mlx_ptr,frac->win_ptr, frac->image, frac->frame, frac->frame);
	//end1 = clock();
	//printf("tiempo transcurrido %f --- %f \n",(double) (end - start) / CLOCKS_PER_SEC, (double) (end1 - start1) / CLOCKS_PER_SEC);
}
