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

	if (!str)
		str = (char *)malloc ((BUFFER_SIZE + 1) * sizeof(char));
	buff_str = (char *) malloc ((BUFFER_SIZE + 1) * sizeof (char));
	while (!my_strchr(str, '\n'))
	{
		if (!buff_str)
		{
			//printf("fallo de memoria\n");
			free(buff_str);
			return (NULL);
		}
		readret = read(fd, buff_str, BUFFER_SIZE);
		//printf("readret <%d>\n",readret );
		if (readret < 0)
			return (NULL);
		aux = my_joinstr (str, buff_str,readret);
		//printf("control str <%s>\n",str );
		//printf("control buff_str <%s>\n",buff_str );
		//printf("control aux <%s>\n",aux );
		free(str);
		str = aux;
	}
	free (buff_str);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*current_str;
	char		*out;
	int			i;
	char		*aux;

	current_str = getcur_str(current_str, fd);
	//printf("control current_str <%s>\n", current_str );
	if (!current_str)
	{
		//printf("fallo de memoria\n");
		free(current_str);
		return (NULL);
	}
	i = my_strchr (current_str, '\n');
	out = my_substr (current_str, 0, i + 1);
	aux = my_substr (current_str, i + 1, my_strlen(current_str) - i - 1);
	//printf("control aux <%s>\n",aux );
	free(current_str);
	current_str = aux;
	return (out);
}
