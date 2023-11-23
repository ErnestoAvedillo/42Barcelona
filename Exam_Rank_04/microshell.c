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
#include <sys/types.h>
#include <process.h>


int len_arr(char **arr)
{
	int i = -1;
	while(arr[i++]);
	return i;
}
int ft_lenstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return i;
}

char *ft_substr(char *str, int start, int len)
{
	char *out;
	int i = -1;

	if (!str)
		return NULL;
	if (start > ft_lenstr(str))
		return NULL;
	if (ft_lenstr(str) < len + start)
		len = ft_lenstr(str) - start;
	out = (char*) malloc((len + 1) * sizeof(char)) ;
	while (++i <= len)
		out[i] = str[start + i];
	out[i] = '\0';
	return out;
}

int is_cd(char **str)
{
	int i = 0;
	char *command;
	
	i =  ft_lenstr(str[0]);
	command = ft_substr(str[0], i -3, 3);
	printf("Long str %i, comando es %s\n",i, command);
	if (strncmp(str[0],"cd ",2) == 0 || strcmp(command, "/cd") == 0)
		i = 1;
	else
		i= 0;
	free (command);
	return i;
}

int my_cd(char **ac)
{
	int out;

	if (len_arr(ac) < 2)
	{
		printf("error: cd: bad arguments\n");
		return -1;
	}
	out = chdir(ac[1]);
	if (out == -1)
		printf("error: cd: cannot change directory to path_to_change\n");
	else
		printf("success: cd: %i changed to path \n");
	return out;
}

/*
int exec_cmd(char **ac, char **env)
{
	int pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		printf("Fork error\n");
		return 1;
	}
	else if (pid == 0)
		execve(ac[0],ac,env);
	wait (&status);
	return 0;
}
*/
int get_nxt_cmd(int cur,char **ac)
{
	int i = cur;
	while (ac[i] && ac[i][0] != '|' &&  ac[i][0] != ';')
	{
		i++;
	}
	return i;
}
char **ext_nxt_cmd(int start, int end, char **ac)
{
	char **out;
	int i;
	i = start;
	out = (char**)malloc((end - start + 1) * sizeof(char*));
	while (i < end)
	{
		out[i-start] = ac[i];
		i++;
	}
	out[i-start] = NULL;
	return out;
}

void prt_cmd(char **ac)
{
	int i = -1;
	printf("Nueva lista de comandos.\n");
	while (ac[++i])
	{
		printf("comando N.: %i es %s.\n",i,ac[i]);
	}
}

int main (int av, char **ac, char **env)
{
	char **comando;
	int is_semicol = 0;
	int is_pipe= 0;
	int i,j;

	if (av < 2)
		return (0);
	i = 0;
	while (++i <= av)
	{
		j = get_nxt_cmd(i,ac);
		printf("resultado start %i end %i\n",i, j);
		comando = ext_nxt_cmd(i,j,ac);
		i = j;
		prt_cmd(comando);
		if(is_cd(comando))
		{
			printf("El comando >%s< es CD\n", comando[0]);
			my_cd(comando);
		}
//		exec_cmd(comando, env);
		free(comando);
	}
}
/*		if (strcmp(ac[i], ";") == 0)
		{º
			is_semicol = 1;	
			printf ("el comando es <;> : %s\n"g, ac[i]);
		}
		else if (strcmp(ac[i], "|") == 0)
		{
			is_pipe = 1;	
			printf ("el comando es <|> : %s\n", ac[i]);
		}
		else if (is_cd(ac[i]))
		{
			printf ("el comando es <cd> : %s\n", ac[i]);
		}
		else
		{
		printf ("el comando no es ninguno del resto : %s\n", ac[i]);
		execve (ac[i], ac[i +1], env);
		}*/