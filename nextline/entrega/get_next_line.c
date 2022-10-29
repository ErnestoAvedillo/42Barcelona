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

char	*getcur_str(char *str, int fd)
{
	char	*buff_str;
	char	*aux;
	int		readret;

	buff_str = (char *) malloc ((BUFFER_SIZE + 1) * sizeof (char));
	if (!buff_str)
	{
		free(buff_str);
		return (NULL);
	}
	while (!my_strchr(str, '\n'))
	{
		readret = read(fd, buff_str, BUFFER_SIZE);
		if (readret < 0)
			break;
		else if (readret == 0)
		{
			aux = my_joinstr (str, buff_str,readret);
			break;
		}
		else
			aux = my_joinstr (str, buff_str,readret);
		free(str);
		if (!aux)
			break;
		else
			str = aux;
	}
	free (aux);
	free (buff_str);
	if (readret < 0 || (readret == 0 && my_strlen(str) == 0 ))
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*current_str;
	char		*out;
	int			i;
	char		*aux;
	
	if(fd < 0 || BUFFER_SIZE <= 0 || read(fd,0,0) < 0)
		return (NULL);
	if(!current_str)
		current_str = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	current_str = getcur_str(current_str, fd);
	if (!current_str)
	{
		free(current_str);
		return (NULL);
	}
	i = my_strchr (current_str, '\n');
	if (i == 0)
	{
		i = my_strlen(current_str);
	}
	out = my_substr (current_str, 0, i + 1);
	aux = my_substr (current_str, i + 1, my_strlen(current_str) - i - 1);
	free(current_str);
	current_str = aux;
	return (out);
}
