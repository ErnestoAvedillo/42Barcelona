/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 20:02:21 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 20:02:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 *
 * Description:		Concatenates the variable with it's value and the 
 * 					character equal
 *					
 * Arguments:		char *str: Name of the variable
 *					
 * Returns:			char *str: The resultant string. 
 * 								NULL If the variable does not exists.
 **/
char	*concat_env(char *name_var)
{
	char	*value;
	char	*out;
	size_t	i;

	value = getenv(name_var);
	if (!value)
		return (NULL);
	i = ft_strlen(name_var) + ft_strlen(value) + 2;
	out = (char *)malloc(i * sizeof(char));
	out[0] = '\0';
	ft_strlcat(out, name_var, i);
	ft_strlcat(out, "=", i);
	ft_strlcat(out, value, i);
	return (out);
}

/**
 *
 * Description:		Removes tue char number n in the str.
 *					
 * Arguments:		char *str: String where to remove the char
 * 					int n:	number of char to remove.
 *					
 * Returns:			char *str: The resultant string. 
 **/
void	ft_strrmchr(char *str, int n)
{
	int	i;
	int	str_len;

	str_len = ft_strlen(str);
	i = -1;
	while (++i < str_len)
	{
		if (i >= n)
			str[i] = str[i + 1];
	}
}

/**
 *
 * Description:		Replace the char c with c2 in case c == c1.
 *
 * Arguments:		char c: current char 
 * 					char c1: the condicional char to be removeed.
 * 					char c2: the char to replace.
 *
 * Returns:			char: the char resultant
 **/
char	replace_char(char c, char c1, char c2)
{
	if (c && c == (char)c1)
		return (c2);
	return (c);
}
