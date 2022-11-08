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
int		ft_print_extended(char *str, va_list args, int pos);
int		get_len_field(char *str, int first_pos);
int		write_extended(char *str, int post, int lenfield, char formato);
int		print_int_frm(char *str, int val, int pos, char formato);
int		print_char_frm(char *str, int val, int pos, char formato);
int		print_str_frm(char *str, char *prtstr, int pos, char formato);
int		print_addr_frm(char *str, size_t ptr, int pos, char formato);
int		print_uint_frm(char *str, unsigned int val, int pos, char formato);

#endif
