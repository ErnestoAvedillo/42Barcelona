/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:58:11 by eavedill          #+#    #+#             */
/*   Updated: 2023/02/11 14:58:13 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"fractol.h"

int mandelbrot(t_complex z0, t_complex c,int iter,int limit)
{
	int i;
	t_complex znext;
	double tmp;
//	t_complex power;
//	clock_t start1;
//	clock_t start2;
//	clock_t start3;
//	clock_t start4;
//	clock_t start5;
//	clock_t end;
//	clock_t	diff = 0;

	i = 0;
//	start1 = clock();
//	power = casign(2, 0);
//	start2 = clock();
	znext = cequal(z0);
//	start3 = clock();
	while (i <= iter)
	{
		if ((znext.re * znext.re + znext.im * znext.im) > (double)limit)
			break ;
		tmp = 2 * znext.re * znext.im + c.im;
		znext.re = znext.re * znext.re - znext.im * znext.im + c.re;
		znext.im = tmp;
		i++;
//		start4 = clock();
//		znext = csum(csqr(znext), c);
//		start5 = clock();
//		if (diff < start5 - start4)
//			diff = start5 - start4;
//		if (cmod(znext) > limit)
//			break;
//		i++;
	}
//	end = clock();
//	if ((double) (end - start1) > 40)
//		printf("tiempo transcurrido start1-2 %f start2-3 %f start3-end %f diff %f \n",(double) (start2 - start1) / CLOCKS_PER_SEC, \
//																			 (double) (start3 - start2) / CLOCKS_PER_SEC, \
//																			 (double) (end - start3)/ CLOCKS_PER_SEC, \
//																			 (double) diff / CLOCKS_PER_SEC);

	//printf("mandelbrot %f + %f i = %f \n", c.re, c.im, cmod(znext));
	//getchar();
	
/*	if (cmod(znext) > (double) MAX)
		i = MAX;
	else
	i = ft_abs((int)(cmod(znext)* MAX)) ;
*/	return (i);
}
