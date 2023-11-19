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

/*
*	Returns the position of the given character in a given str.
*	Argument: 	string to serach
*				character
*	Returns: integer
*/
int	get_pos( char *str, char c)
{
	int	pos;

	pos = 0;
	while (str[pos] && str[pos] != c)
		pos++;
	if (!str[pos])
		return (0);
	return (pos);
}

/*
*	Returns the value of the event variable.
*	Argument: 	*char: Name to search
*				**char: Array of strings to search in
*	Returns: *char
*/
char	*get_env_value(char *name_env, char **env)
{
	int		len;
	char	*out;

	len = ft_strlen(name_env);
	while (*env)
	{
		if (!ft_strncmp(name_env, *env, 0, len))
			break ;
		env++;
	}
	out = ft_strtrim (*env, name_env);
	return (out);
}

/*
*	Returns the ame of the variable of listed in an string.
*	Returns in fact the string on the left side of the '=' character.
*	Argument: 	*char: String where to seach. 
*				**char: Array of strings to search in
*	Returns: *char
*/
char	*get_env_name(char *str)
{
	int	pos;

	pos = get_pos(str, '=');
	return (ft_substr(str, 0, pos));
}

/*
*	Returns if a character is in a string.
*	Argument: 	*char: strings to search in
*				char: character to search
*	Returns: bool
*/
bool	is_char_in_str(char *str, char c)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
			return (1);
	}
	return (0);
}

/*
*	Returns if the string is containing any of the operands defined into OPERANDS.
*	Argument: 	*char: strings to search in
*				char: character to search
*	Returns: bool
*/
bool	is_oper(char *str)
{
	char	**oper;
	int		i;

	oper = ft_split(OPERANDS, ' ');
	i = -1;
	while (oper[++i])
		if (str[0] == oper[i][0])
			return (true);
	return (false);
}
