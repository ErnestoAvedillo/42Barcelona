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
# include <sys/types.h>
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

# define PLUS_FLAG 43 			//char +
# define MINUS_FLAG 45			//char -
# define POINT_FLAG 46			//char .
# define SPACE_FLAG 32			//char ' ' space
# define POUND_FLAG 35			//char #
# define ZERO_FLAG 48			//char 0
# define NONE_FLAG 0			//char \0

# define PERC_FORMAT 37			//char %
# define INT_FORMAT_I 105		//char i 
# define INT_FORMAT_D 100		//char d
# define CHAR_FORMAT_C 99		//char c
# define STR_FORMAT_S 115		//char s
# define ADDR_FORMAT_P 112		//char p
# define LONG_FORMAT_U 117		//char u
# define HEX_FORMAT_X 120		//char x
# define HEX_FORMAT_X_CAP 88	//char X
# define NONE_FORMAT 0			//char \0

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
