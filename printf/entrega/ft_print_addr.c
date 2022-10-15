/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 12:27:40 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/15 12:27:46 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../Libft/entrega/libft.h"
#include "ft_printf.h"

int ft_print_addr (size_t addr)
{	
	
	if (addr)
		return (1);
	else
		return(0);
}