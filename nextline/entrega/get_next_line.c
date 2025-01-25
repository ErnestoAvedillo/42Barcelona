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
#include "get_next_line.h"

char	*get_new_current_str(char *current_str, int start)
{
	char	*out;
	int		longstr;

	longstr = my_strlen(current_str);
	out = my_substr(current_str, start, longstr - start);
	free_null (&current_str);
	return (out);
}

char	*getcur_str(char *current_str, int fd)
{
	char	*buff_str;
	int		readret;

	readret = 0;
	buff_str = (char *) malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (!buff_str)
		return (NULL);
	while (my_strchr(current_str, '\n') < 0)
	{
		readret = read(fd, buff_str, BUFFER_SIZE);
		if (readret > 0)
			current_str = my_joinstr (current_str, buff_str, readret);
		if (readret < BUFFER_SIZE || !current_str)
			break ;
	}
	free_null (&buff_str);
	if (readret < 0 || (readret == 0 && my_strlen (current_str) == 0))
	{
		free_null (&current_str);
		return (NULL);
	}
	return (current_str);
}

char	*get_next_line(int fd)
{
	static char	*current_str;
	char		*out;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, 0, 0) < 0)
	{
		if (current_str)
			current_str[0] = 0;
		return (NULL);
	}
	current_str = getcur_str(current_str, fd);
	if (!current_str)
		return (NULL);
	i = my_strchr (current_str, '\n');
	if (i < 0)
		i = my_strlen(current_str) - 1;
	out = my_substr (current_str, 0, i + 1);
	if (!out)
		free_null(&current_str);
	else
		current_str = get_new_current_str (current_str, i + 1);
	if (current_str && my_strchr(out, '\n') < 0)
		free_null(&current_str);
	return (out);
}
