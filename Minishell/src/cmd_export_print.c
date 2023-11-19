/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_export_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:43:13 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/21 19:43:17 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

/**
 *
 * Description:		Printe the environment variables sorted
 *					
 * Arguments:		char **env
 *					
 * Returns:			NONE
 * 
 **/
void	print_env_sorted(char **env)
{
	int		i;
	char	**aux;

	aux = ft_cpy_str_arr(env);
	aux = ft_strsort_arr(aux, 1);
	i = -1;
	while (aux[++i] != NULL)
		ft_printf("declare -x %s\n", aux[i]);
	free(aux);
	return ;
}
