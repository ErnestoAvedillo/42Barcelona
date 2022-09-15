/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:14:09 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 19:57:09 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	length_str(char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
		count++;
	return (count);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	counter;
	int				terminar;

	counter = 0;
	terminar = 0;
	if (length_str(dest) < size || length_str(dest) == 0)
		return (0);
	while (src[counter] != '\0' && ! terminar)
	{
		if (size > 0 && (counter < (size - 1)))
			dest[counter] = src[counter];
		else
		{
			dest[counter] = '\0';
			terminar = 1;
		}
		counter++;
	}
	while (src[counter] != '\0')
	{
		dest[counter] = '\0';
		counter++;
	}
	return (counter);
}
