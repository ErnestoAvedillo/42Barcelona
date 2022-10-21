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
int strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i++]);
	return (i);
}

size_t	strchr(char *str)
{
	size_t	i;

	i = 0;
	while(i < BUFFER_SIZE)
	{
		if (str[i] == '\n')
		{
			return (i);
			i++;
		}
	}
	return (0);
}

char	*substr(char *str, int start, int len)
{
	char	*out;
	int		i;

	if (start > strlen(str))
		return (NULL);
	*
	i = start;
	while (str[i] && i < len + start)
	{

	}
}

char	*get_next_line(int fd)
{
	static char	*firstchar;
	char		*out;
	char		buff_str[BUFFER_SIZE];
	size_t			i;

	i = 0;
	while (i++ < 100)
	{
		buff_str = read(firstchar,BUFFER_SIZE, fd);
		printf("%s\n",buff_str;
		i = strchr(*firstchar,'\n');
		if (i)
		{
			out = substr(str,0,(int)i)
			
		}

	}

}
