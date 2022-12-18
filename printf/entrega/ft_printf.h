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
	int		isplus;
	int		ispoint;
	int		iszero;
	int		longfield;
	int		prtstrlen;
	char	format;
	int		cur_str_pos;
	int		signo;
	int		error;
}		t_form_data;

typedef struct l_print_data
{
	int	lng;
	int	cur_str_pos;
}		t_print_data;

typedef struct true_table_spaces
{
	char	formato;
	char	flag;
	int		iszero;
	int		ispoint;
}		t_true_table_spcs;

# define PLUS_FLAG '+'
# define MINUS_FLAG '-'
# define POINT_FLAG '.'
# define SPACE_FLAG ' '
# define POUND_FLAG '#'
# define ZERO_FLAG '0'
# define ASTERISC_FLAG '*'
# define NONE_FLAG '\0'

# define PERC_FRMT '%'
# define INT_FRMT_I 'i'
# define INT_FRMT_D 'd'
# define CHAR_FRMT_C 'c'
# define STR_FRMT_S 's'
# define ADDR_FRMT_P 'p'
# define LONG_FRMT_U 'u'
# define HEX_FRMT_X 'x'
# define HEX_FRMT_X_CAP 'X'
# define NONE_FRMT '\0'

// ft printf
int			ft_printf(char const *str, ...);
// print_args
int			ft_print_str(char *str);
int			ft_print_char(char c);
int			ft_print_int(int val);
int			ft_print_uint(unsigned int val, char formato);
int			ft_print_addr(size_t val, char formato);
// ft_utoa
char		*ft_utoa(unsigned int n);
// ft_addrtoa
char		*ft_addrtoa(size_t n, int formato, int flag);
//bonus
int			ft_print_extended(char *str, va_list args, int pos);
//bonus_utils
t_form_data	*newdata(void);
int			is_format_char(char c);
int			find_flag(char c);
//print_format
int			print_int_frm(int val, t_form_data *formato);
int			print_char_frm(int val, t_form_data *formato);
int			print_str_frm(char *prtstr, t_form_data *formato);
int			print_addr_frm(size_t ptr, t_form_data *formato);
int			print_uint_frm(unsigned int val, t_form_data *formato);
//write_extended
int			write_extended(char *str, t_form_data *formato);
//ft_print_chrs
int			print_extra_char(t_form_data *formato, int lenstr, char c);
int			print_extra_zeros(t_form_data *formato, int lenstr);
int			print_symbol(t_form_data *formato);
//ft_print_suf
int			ft_printf_suf_str(t_form_data *formato);
int			ft_printf_suf_int(t_form_data *formato);
int			ft_printf_suf_lng(t_form_data *formato);
int			ft_printf_suf_hex(t_form_data *formato);
int			ft_printf_suf_addr(t_form_data *formato);
//fill_list
void		get_len_field(char *str, t_form_data *formato, va_list args);
void		get_len_zeros(char *str, t_form_data *formato, va_list args);
t_form_data	*fill_list(char *str, int pos, va_list args);
#endif
