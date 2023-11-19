/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:02:55 by frmurcia          #+#    #+#             */
/*   Updated: 2023/09/01 18:15:45 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

extern int	g_out_status;

/**** Busca dos errores consecutivas. Devuelven lo que tiene que printar
 * el error.
 * check_text lanza todo.
 *
 * */
char	*return_error_found(char *texto, int *i, int *j, \
		int *consecutive_errors)
{
	const char	*error_bl[] = {">|", "||", "|", "<<<", "<<", ">>", "<>", \
		">", "<"};
	int			block_length;
	char		*error;

	error = NULL;
	block_length = ft_strlen(error_bl[*j]);
	if (ft_strncmp_mod(&texto[*i], error_bl[*j], block_length) == 0)
	{
		*i += block_length;
		(*consecutive_errors)++;
		if (*consecutive_errors == 1)
		{
			*j = -1;
			return (F_E_F);
		}
		if (*consecutive_errors == 2)
		{
			error = ft_strdup(error_bl[*j]);
			*j = -1;
			return (error);
		}
	}
	return (NULL);
}

char	*return_check(char *texto, int *i, int *consecutive_errors)
{
	int		j;
	char	*ch_error;

	while (texto[*i])
	{
		j = 0;
		while (j < 9 && texto[*i])
		{
			if (texto[*i] == ' ' && texto[*i + 1])
				(*i)++;
			else if (texto[*i + 1] && texto[*i] != ' ' && !is_redir(texto[*i]))
			{
				*consecutive_errors = 0;
				if (texto[*i])
					(*i)++;
			}
			ch_error = return_error_found(texto, i, &j, consecutive_errors);
			if (ch_error != NULL && (ft_strcmp(ch_error, F_E_F) != 0))
				return (ch_error);
			else if (ch_error != NULL && (ft_strcmp(ch_error, F_E_F) == 0))
				break ;
			j++;
		}
	}
	return (NULL);
}

char	*process_many_blocks(char *text)
{
	char	*texto;
	char	*error;
	int		consecutive_errors;
	int		i;

	i = 0;
	error = NULL;
	consecutive_errors = 0;
	texto = ft_strdup(text);
	if (texto != NULL)
	{
		while (texto[i])
		{
			error = return_check(text, &i, &consecutive_errors);
			if (error != NULL)
			{
				free(texto);
				return (error);
			}
			if (texto [i + 1])
				i++;
		}
	}
	return ("newline");
}

int	unex_token(char *text)
{
	char	*unexpected;

	unexpected = process_many_blocks(text);
	print_err("Minishell: syntax error near unexpected token: `%s'\n", \
		unexpected);
	return (1);
}

bool	check_text(t_data *data)
{
	char	*texts;

	texts = ft_strdup(data->command);
	texts = free_quotes(texts);
	if (first_pipe(texts) || check_two_pipes(texts))
		return (false);
	if (many_blocks(texts))
	{
		unex_token(texts);
		g_out_status = 258;
		return (false);
	}
	else
	{
		if (final_redir(texts))
		{
			new_line();
			g_out_status = 258;
			return (false);
		}
	}
	free (texts);
	data->execute = true;
	return (true);
}
/*
int main() {
	char *input_text1 = "||||||||";
	printf("%s\n", input_text1);
	check_text(input_text1);

	char *input_text2 = ">";
	printf("%s\n", input_text2);
	check_text(input_text2);

	char *input_text3 = "> > > >";
	printf("%s\n", input_text3);
	check_text(input_text3);

	char *input_text4 = ">> >> >> >>";
	printf("%s\n", input_text4);
	check_text(input_text4);

	char *input_text5 = "<<";
	printf("%s\n", input_text5);
	check_text(input_text5);

	char *input_text6 = "| echo -n oui";
	printf("%s\n", input_text6);
	check_text(input_text6);

	char *input_text7 = "<<| echo wtf";
	printf("%s\n", input_text7);
	check_text(input_text7);

	char *input_text8 = ">>| echo wtf";
	printf("%s\n", input_text8);
	check_text(input_text8);

    return (0);
}*/
