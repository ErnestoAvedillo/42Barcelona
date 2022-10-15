#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../../Libft/entrega/libft.h"

int		ft_printf (char const *str, ...);
char	*ft_utoa(unsigned int n);
char	*ft_addrtoa(size_t n);
#endif