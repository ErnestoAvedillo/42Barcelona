/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 06:59:44 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/24 06:59:47 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"
/**
 *
 * Description:		Creates a new strin and where will be str1 and str2 
 * 					concatenated. str1 and str2 will be free.
 *					
 * Arguments:		char *str1: First string to concatenate
 * 					char str2: second string to be cpncatenated.
 *					
 * Returns:			char* out: a string where the 2 strings are concatenated.
 **/
char	*concat_cmd(char *str1, char *str2)
{
	char	*out;

	out = ft_strjoin(str1, str2);
	free(str1);
	free(str2);
	return (out);
}
