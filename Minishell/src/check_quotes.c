/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:59:18 by eavedill          #+#    #+#             */
/*   Updated: 2023/06/22 19:59:25 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

bool	is_quote(char c)
{
	if (c == '"' || c == '\'')
		return (true);
	return (false);
}

//Booleano. Es true si es correcto el control de las comillas
//Estara OK si:
//a) No hay comillas
//b) Si las hay y se han cerrado despues de abrirse.
bool	quotes_ok(char *str)
{
	int		c;
	char	quote;
	bool	quoted_off;

	c = 0;
	quote = '\0';
	quoted_off = true;
	if (!str)
		return (true);
	while (str[c])
	{
		if (is_quote(str[c]) && quoted_off)
		{
			quoted_off = false;
			quote = str[c];
		}
		else if (is_quote(str[c]) && !quoted_off && str[c] == quote)
		{
			quoted_off = true;
			quote = '\0';
		}
		c++;
	}
	return (quoted_off);
}
