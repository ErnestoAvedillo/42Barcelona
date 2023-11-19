/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_var_name.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 22:46:18 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/11 22:46:23 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static bool	is_limit_char(char c)
{
	if (ft_isalnum(c) || c == '_')
		return (true);
	return (false);
}

char	*get_var_name(char *str, int pos)
{
	int	i;

	i = pos + 1;
	if (ft_isdigit(str[i]))
		return (ft_substr(str, pos, 2));
	if (str[i] == '?')
		return (ft_substr(str, pos, 2));
	i++;
	while (str[i] && is_limit_char(str[i]))
		i++;
	return (ft_substr(str, pos, i - pos));
}
