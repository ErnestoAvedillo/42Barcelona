/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_delimiter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 19:54:53 by eavedill          #+#    #+#             */
/*   Updated: 2023/08/07 19:54:56 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

char	*my_ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!little || !little[0])
		return ((char *)(big));
	i = 0;
	while (i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			k = i;
			while (big[k] == little[j] && big[k] && little[j] && k < len)
			{
				k++;
				j++;
			}
			if (!little[j] && k <= len)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}

char	*get_delimit(char *str)
{
	char	*aux[2];
	char	*out;

	aux[0] = get_start_delimit(str);
	aux[1] = get_end_delimit(str);
	out = ft_substr(str, (int)(aux[0] - str), (size_t)(aux[1] - aux[0]));
	return (out);
}

void	print_error(void)
{
	print_err("minishell: error while forking");
	g_out_status = 1;
}

void	free_aux(char **aux)
{
	free(aux[0]);
	free(aux[1]);
	free(aux[2]);
}

/*
 *   Checks that the command line does not have following errors
 *   " = " or " =" or "= " --> is not OK
 *   operands should be allways in betewwn blanks
 *
 * In function aux[0] corresonds to the auxiliar variable
 * In function aux[1] corresonds to the readed variable
 */
void	check_delimiter(t_instruct *instr)
{
	char	*aux[3];
	int		pid;
	int		status;

	instr->in->fd_type = 2;
	aux[1] = ft_strdup(instr->in->fd_name);
	aux[0] = ft_itoa(instr->header->contador);
	aux[2] = ft_strjoin(aux[1], "> ");
	instr->header->contador++;
	actualize_fdname(instr, aux[0]);
	reset_signals();
	pid = fork();
	if (pid == -1)
	{
		print_err("Error when fork\n");
		return ;
	}
	else if (pid == 0)
		fill_heredoc(instr, aux);
	wait(&status);
	g_out_status = WEXITSTATUS(status);
	if (g_out_status == 1)
		instr->header->execute = false;
	close(instr->in->fd);
	free_aux(aux);
}
