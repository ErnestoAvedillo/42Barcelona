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
		//printf("readret <%d>\n",readret );
		if (readret < 0)
			break;
		else if (readret == 0)
		{
			aux = my_joinstr (str, buff_str,readret);
			break;
		}
		else
			aux = my_joinstr (str, buff_str,readret);
		//printf("control str <%s>\n",str );
		//printf("control buff_str <%s>\n",buff_str );
		//printf("control aux <%s>\n",aux );
		free(str);
		if (!aux)
			break;
		else
			str = aux;
	}
	//printf("str out <%s>\n", str );
	free (buff_str);
	if (readret < 0 || !aux || (readret == 0 && my_strlen(str) == 0 ))
		return (NULL);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*current_str;
	char		*out;
	int			i;
	char		*aux;
	
	if(!current_str)
		current_str = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	current_str = getcur_str(current_str, fd);
	if (!current_str)
	{
		//printf("valor de current devuelto <%s>\n",current_str );
		free(current_str);
		return (NULL);
	}
	i = my_strchr (current_str, '\n');
	if (i == 0)
		i = my_strlen(current_str);
	out = my_substr (current_str, 0, i + 1);
	aux = my_substr (current_str, i + 1, my_strlen(current_str) - i - 1);
	//printf("control out <%s>\n",out);
	//printf("control aux <%s>\n",aux );
	free(current_str);
	current_str = aux;
	return (out);
}
