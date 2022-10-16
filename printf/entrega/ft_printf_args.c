/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 11:07:18 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 11:07:31 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write (1, &c, 1));
}

int	ft_print_int(int val)
{
	char	*str;
	int		lng;

	str = ft_itoa (val);
	lng = ft_printf (str);
	free (str);
	return (lng);
}

int	ft_print_uint(unsigned int val, char formato)
{
	char	*str;
	int		lng;

	if (formato == 'u' || val == 0)
		str = ft_utoa (val);
	else
		str = ft_addrtoa ((size_t)val, formato);
	lng = ft_printf (str);
	free (str);
	return (lng);
}

int	ft_print_addr(size_t val, char formato)
{
	char	*str;
	int		lng;

	if (val == 0)
		str = ft_strdup("0x0");
	else
		str = ft_addrtoa (val, formato);
	lng = ft_printf (str);
	free (str);
	return (lng);
}
