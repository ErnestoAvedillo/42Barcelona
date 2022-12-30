/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 12:38:17 by eavedill          #+#    #+#             */
/*   Updated: 2022/11/25 17:11:03 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct l_form_data
{
	char	flag;
	int		ispoint;
	int		iszero;
	int		longfield;
	char	format;
	int		cur_str_pos;
	int		prtstrlen;
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
# define NONE_FLAG '\0'

# define PERC_FORMAT '%'
# define INT_FORMAT_I 'i'
# define INT_FORMAT_D 'd'
# define CHAR_FORMAT_C 'c'
# define STR_FORMAT_S 's'
# define ADDR_FORMAT_P 'p'
# define LONG_FORMAT_U 'u'
# define HEX_FORMAT_X 'x'
# define HEX_FORMAT_X_CAP 'X'
# define NONE_FORMAT '\0'

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

#endif
