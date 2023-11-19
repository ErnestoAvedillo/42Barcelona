/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 19:10:29 by eavedill          #+#    #+#             */
/*   Updated: 2023/07/07 17:31:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	check_old_dir(t_instruct *instruct)
{
	if (!instruct->arg[1])
		return (0);
	if (instruct->arg[1][0] == '-' && (instruct->arg[1][1] == '\0' || \
		(instruct->arg[1][1] == '-' && instruct->arg[1][2] == '\0' )))
	{
		if (instruct->arg[1][1] == '-')
			ft_strrmchr(instruct->arg[1], 1);
		instruct->arg[1] = repl_old_dir(instruct->arg[1]);
		if (!instruct->arg[1])
		{
			print_err("minishell: cd: OLDPWD not set\n");
			return (1);
		}
	}
	return (0);
}

/**
 *
 * Description:		creates the complete address in case ~ is given or
 * 					no argument is given 
 *					
 * Arguments:		t_instruct *instruct: structure with the instruction 
 * 					requested.
 *					
 * Returns:			char * the string with the address.
 **/
char	*get_address(t_instruct *instruct)
{
	char	*dir;

	dir = (char *) malloc(1024 * sizeof(char));
	dir [0] = '\0';
	if (instruct->arg[1] == NULL)
		ft_strlcpy(dir, getenv("HOME"), 1024);
	else
	{
		ft_strlcat(dir, instruct->arg[1], 1024);
	}
	return (dir);
}

void	actualize_oldpwd(t_instruct *instr, char *dir)
{
	char	*str;

	setenv("OLDPWD", dir, 1);
	str = concat_env("OLDPWD");
	instr->header->env = actualize_env(instr->header->env, str, 1);
	free(str);
	return ;
}

/**
 *
 * Description:		Changes the directory 
 *					
 * Arguments:		t_instruct *instruct: structure with the instruction 
 * 					requested.
 *					
 * Returns:			1.
 **/
int	cmd_cd(t_instruct *instruct)
{
	char	*dir[2];
	char	buffer[1024];

	if (check_old_dir(instruct))
		return (1);
	dir[1] = getcwd(buffer, sizeof(buffer));
	dir[0] = get_address(instruct);
	if (chdir(dir[0]) == -1)
	{
		print_err("Minishell: cd: %s: No such file or directory .\n", dir[0]);
		free(dir[0]);
		return (1);
	}
	else
	{
		actualize_oldpwd(instruct, dir[1]);
		free(dir[0]);
		dir[0] = getcwd(buffer, sizeof(buffer));
		setenv("PWD", dir[0], 1);
		dir[0] = concat_env("PWD");
		instruct->header->env = actualize_env(instruct->header->env, dir[0], 1);
		free(dir[0]);
	}
	return (0);
}
