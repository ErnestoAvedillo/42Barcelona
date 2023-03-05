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
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(frac->image, &pixel_bits, &line_bytes, &endian);

	i = frac->frame;
	k = 0;
	while(++i < frac->size_x - frac->frame)
	{
		j = frac->frame;
		while(++j < frac->size_y - frac->frame)
		{
			frac->z0.re = (frac->c1.re + i * frac->escala_x);
			frac->z0.im = (frac->c1.im + j * frac->escala_y);
			//start = clock();
			result = frac->function(frac->c, frac->z0, frac->repet, frac->limit);
			//end = clock();
			//mlx_pixel_put(frac->mlx_ptr, frac->win_ptr, i, j, result * frac->color);
			put_pixel_color (&buffer[j * line_bytes + i * pixel_bits / 8 ] , frac->color, result);
			//if ((double) (end - start) > 40)
			//	printf("tiempo transcurrido %f %d %i %f %f\n",(double) (end - start) / CLOCKS_PER_SEC, i, j, c.re, c.im);
			k++;
		} 
	}
	//start1 = clock();
	mlx_put_image_to_window(frac->mlx_ptr,frac->win_ptr, frac->image, 0, 0);
	//end1 = clock();
	//printf("tiempo transcurrido %f --- %f \n",(double) (end - start) / CLOCKS_PER_SEC, (double) (end1 - start1) / CLOCKS_PER_SEC);
}

void	new_scale(int sense, t_fract *frac, int x, int y)
{
	t_complex	cur;
	x -= frac->frame;
	y -= frac->frame;

/*	printf("\n\n\n inicio\n\n\n");
	printf("escla_x %f ;escla_y %f ; ofigen X %f --  origen Y %f\n", frac->escala_x, frac->escala_y, frac->c1.re, frac->c1.im);
	printf(" Pos x %i -- Pos y %i \n", x, y);
	printf("valor de c1 = %f %+fi\n",frac->c1.re, frac->c1.im);
*/	if (sense == SCALE_UP)
	{
//		printf("SCALE UP\n");
		cur = casign (frac->c1.re + x * frac->escala_x, frac->c1.im + y * frac->escala_y);
		frac->escala_x /= frac->zoom_fact;
		frac->escala_y /= frac->zoom_fact;
		frac->c1 = casign(cur.re - x * frac->escala_x, cur.im - y * frac->escala_y);
	}
	else if (sense == SCALE_DW)
	{
//		printf("SCALE DOWN\n");
		cur = casign (frac->c1.re + x * frac->escala_x, frac->c1.im + y * frac->escala_y);
		frac->escala_x *= frac->zoom_fact;
		frac->escala_y *= frac->zoom_fact;
		frac->c1 = casign(cur.re - x * frac->escala_x,cur.im - y * frac->escala_y);
	}
/*	printf("escla_x %f ;escla_y %f ; ofigen X %f --  origen Y %f\n", frac->escala_x, frac->escala_y, frac->c1.re, frac->c1.im);
	printf(" Pos x %i -- Pos y %i \n", x, y);
 	printf("valor de c1 = %f %+fi\n",frac->c1.re, frac->c1.im);*/
}