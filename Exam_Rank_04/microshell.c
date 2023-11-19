/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:03:45 by eavedill          #+#    #+#             */
/*   Updated: 2023/11/19 18:41:19 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int is_cd(char *str)
{
	char **comando;
	int i = 0;
	int j = 0;

	comando = split(ac[i],'/');
	while(comando[i])
		i++;
	if (strcmp((comando[i - 1], "cd") == 0)
		i = 1;
	else
		i = 0;
	while (comando[j])
		free (comando[j++]);
	free (comando);
	return i;

}

int main (int av, char **ac, char **env)
{
	char **comando;
	int is_semicol = 0;
	int is_ pipe= 0;
	int i;

	if (av < 2)
		return (0);
	i = 0;
	while (ac[++i])
	{
		comando = split(ac[i];
		
		if (strcmp(ac[i], ";") == 0)
		{
			is_semicol = 1;	
			printf ("el comando es <;> : %s\n", ac[i]);
		}
		else if (strcmp(ac[i], "|") == 0)
		{
			is_pipe = 1;	
			printf ("el comando es <|> : %s\n", ac[i]);
		}
		else if (is_cd(ac[i])
		{
			printf ("el comando es <cd> : %s\n", ac[i]);
		}
		else
		{
		printf ("el comando no es ninguno del resto : %s\n", ac[i]);
		}
	}
}
