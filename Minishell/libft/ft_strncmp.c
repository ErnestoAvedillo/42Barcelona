/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:14:47 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/24 10:05:55 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*   Descriptinon:	Compares 2 strings for a given length.
*   Arguments:		char *s1: First string to compare.
*					char *s2: Second string to compare.
*					int strt: Start position to compare.
*					int length: of charachters to compare
*   Returns:		0 if are identical
*					difference between first char not equal.
*/
int	ft_strncmp(char *s1, char *s2, unsigned int strt, unsigned int n)
{
	unsigned int	counter;

	counter = strt;
	while (s1[counter] != '\0' && s2[counter] != '\0' && counter < n)
	{
		if ((unsigned char)s1[counter] != (unsigned char)s2[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		counter++;
	}
	if ((s1[counter] != s2[counter]) && counter < n)
		return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
	return (0);
}
