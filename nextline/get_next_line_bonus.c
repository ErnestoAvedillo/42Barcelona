/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:15:35 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/17 06:18:27 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"

char	*getcur_str(char *str, int fd)
{
	char	*buff_str;
	char	*aux;
	int		readret;

	if (!str)
		str = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	buff_str = (char *) malloc ((BUFFER_SIZE + 1) * sizeof (char));
	while (!my_strchr(str, '\n'))
	{
		if (!buff_str)
		{
			free(buff_str);
			return (NULL);
		}
		readret = read(fd, buff_str, BUFFER_SIZE);
		if (readret < 0)
			return (NULL);
		aux = my_joinstr (str, buff_str, readret);
		free(str);
		str = aux;
	}
	free (buff_str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*current_str[1024];
	char		*out;
	int			i;
	char		*aux;

	current_str[fd] = getcur_str(current_str[fd], fd);
	if (!current_str[fd])
	{	
		free(current_str[fd]);
		return (NULL);
	}
	i = my_strchr (current_str[fd], '\n');
	out = my_substr (current_str[fd], 0, i + 1);
	aux = my_substr (current_str[fd], i + 1, \
						my_strlen(current_str[fd]) - i - 1);
	free(current_str[fd]);
	current_str[fd] = aux;
	return (out);
}
