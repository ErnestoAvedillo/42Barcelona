/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:15:35 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/17 06:18:27 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

int my_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++]);
	return (i);
}

size_t	my_strchr(char *str,char c)
{
	size_t	i;

	i = 0;
	while(i < BUFFER_SIZE)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
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
	out[i] = str[i];
	return (out);
}

char	*get_next_line(int fd)
{
	char		*out;
	char		*buff_str;
	static char	*first_pos;
	int			i;

	i = 0;
	buff_str = (char *)malloc (BUFFER_SIZE * sizeof(char));
	i = read(fd, first_pos, BUFFER_SIZE);
	i = my_strchr(buff_str,'\n');
	if (i)
	{
		out = my_substr(buff_str,0,(int)i);
	}
	else
		return (NULL);
	first_pos = first_pos + i;
	free (buff_str);
	return (out);
}
