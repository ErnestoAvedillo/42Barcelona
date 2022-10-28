/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:18:53 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/17 06:19:42 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

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
	return (0);
}

char	*my_joinstr(char *dst, char *src)
{
	int		i;
	int		longdst;
	char	*out;

	longdst = my_strlen(dst);
	out = (char *) malloc ((longdst + my_strlen (src) + 1) * sizeof(char));
	i = 0;
	while (dst[i])
	{
		out[i] = dst[i];
		i++;
	}
	while (src[i - longdst])
	{
		out[i] = src[i - longdst];
		i++;
	}
	out[i] = '\0';
	return (out);
}

char	*my_substr(char *str, int start, int len)
{
	char	*out;
	int		i;

	if (start > my_strlen(str))
		return (NULL);
	i = start;
	out = (char *)malloc((len + 1) * sizeof(char));
	while (str[i] && (i < len + start) && (str[i] != -1))
	{
		out[i - start] = str[i];
		i++;
	}
	out[i - start] = '\0';
	return (out);
}
