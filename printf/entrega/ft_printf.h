/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:38:17 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/16 12:38:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include "./libft/libft.h"

int		ft_printf(char const *str, ...);
char	*ft_utoa(unsigned int n);
char	*ft_addrtoa(size_t n, int formato);
int		ft_print_char(char c);
int		ft_print_int(int val);
int		ft_print_uint(unsigned int val, char formato);
int		ft_print_addr(size_t val, char formato);
#endif
