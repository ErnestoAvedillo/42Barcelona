/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:18:53 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/17 06:19:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

void	free_null(char **prt)
{
	free(*prt);
	*prt = 0;
	return ;
}

int	my_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	my_strchr(char *str, char c)
{
	int	i;
	int	lenstr;

	lenstr = my_strlen(str);
	i = 0;
	while (i < lenstr)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*my_joinstr(char *dst, char *src, int lensrc)
{
	int		i;
	int		longdst;
	char	*out;

	if (!dst)
	{
		dst = (char *)malloc (1 * sizeof (char));
		if (!dst)
			return (NULL);
		dst[0] = '\0';
	}
	longdst = my_strlen(dst);
	out = (char *)malloc ((longdst + lensrc + 1) * sizeof (char));
	if (!out)
		return (NULL);
	i = -1;
	while (++i < longdst && longdst)
		out[i] = dst[i];
	i--;
	while (++i <= longdst + lensrc - 1)
		out[i] = src[i - longdst];
	out[i] = '\0';
	free_null(&dst);
	return (out);
}

char	*my_substr(char *str, int start, int len)
{
	char	*out;
	int		i;

	if (start > my_strlen(str) || len < 0)
		return (NULL);
	i = start;
	out = (char *)malloc ((len + 1) * sizeof (char));
	if (!out)
		return (NULL);
	while (str[i] && (i < len + start) && (str[i] != -1))
	{
		out[i - start] = str[i];
		i++;
	}
	out[i - start] = '\0';
	return (out);
}
