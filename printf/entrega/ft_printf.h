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

typedef struct l_form_data
{
	char	flag;
	int		iszero;
	int		longfield;
	char	format;
	int		cur_str_pos;
	int		print_len;
}		t_form_data;

typedef struct l_print_data
{
	int	lng;
	int	cur_str_pos;
}		t_print_data;

# define PLUS_FLAG '+'
# define MINUS_FLAG '-'
# define POINT_FLAG '.'
# define SPACE_FLAG ' '
# define POUND_FLAG '#'
# define NONE_FLAG '\0'

# define INT_FORMAT_I 'i'
# define INT_FORMAT_D 'd'
# define CHAR_FORMAT_C 'c'
# define STR_FORMAT_S 's'
# define ADDR_FORMAT_P 'p'
# define LONG_FORMAT_U 'u'
# define HEX_FORMAT_x 'x'
# define HEX_FORMAT_X 'X'
# define NONE_FORMAT '\0'



int		ft_printf(char const *str, ...);
char	*ft_utoa(unsigned int n);
char	*ft_addrtoa(size_t n, int formato);
int		ft_print_char(char c);
int		ft_print_int(int val);
int		ft_print_uint(unsigned int val, char formato);
int		ft_print_addr(size_t val, char formato);
int		ft_print_extended(char *str, va_list args, int pos);
int		get_len_field(char *str, int first_pos);
t_form_data *newdata ();
int		write_extended(char *str, t_form_data *formato);
int		print_int_frm(int val, t_form_data *formato);
int		print_char_frm(int val, t_form_data *formato);
int		print_str_frm(char *prtstr, t_form_data *formato);
int		print_addr_frm(size_t ptr, t_form_data *formato);
int		print_uint_frm(unsigned int val, t_form_data *formato);

#endif
