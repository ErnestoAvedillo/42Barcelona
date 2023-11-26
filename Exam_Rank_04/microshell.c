/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 10:40:10 by eavedill          #+#    #+#             */
/*   Updated: 2023/11/26 12:18:38 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


 #include <stdlib.h>
 #include <stdio.h>
 #include <unistd.h>
 #include <string.h>
 #include <sys/wait.h>
 #include <sys/types.h>

int prt_err(char *ac1, char *ac2)
{
	int i = -1;
	while (ac1[++i])
		write(2, &ac1[i], 1);
	i = -1;
	if (ac2)
		while (ac2[++i])
			write(2, &ac2[i], 1);
	write(2, "\n", 1);
	return 1;
}

int exec_cmd(char **ac, int i, int tmp_fd, char **env)
{
	dup2(tmp_fd, STDIN_FILENO);
	close(tmp_fd);
	ac[i] = NULL;
	execve(ac[0], ac, env);
	return (prt_err("error: cannot execute ", ac[0]));
}

int main (int av, char **ac, char **env)
{
	int tmp_fd, fd[2];
	int i = 0;
	int status;
	
	if (av < 2)
		return 0;
	tmp_fd = dup(STDIN_FILENO);
	ac = &ac[1];
//		printf("paso %i %s \n", i, ac[i]);
	while (ac[i])
	{
		while(ac[i] && strcmp(ac[i],";") && strcmp(ac[i],"|"))
		{
//		printf("paso %i %s \n", i, ac[i]);
//		getchar();
			i++;
		}
//		printf("salgo %i %s \n", i, ac[i]);
		if(i > 0 && (!strcmp(ac[0], "cd") || !strcmp(ac[0], "/usr/bin/cd")))
		{
//			printf("es cd %i %s \n", i, ac[0]);
			if (i != 2)
				prt_err("error: cd: bad arguments",NULL);
			else if (chdir(ac[1]) != 0)
				prt_err("error: cd: cannot change directory to ", ac[1]);
		}
		else if (i > 0 &&(!ac[i] || !strcmp(ac[i], ";")))
		{
//			printf("es ; %i %s \n", i, ac[i]);
			if (fork() == 0)
			{
				if(exec_cmd(ac,i,tmp_fd,env))
					return 1;
			}
			else
			{
				close(tmp_fd);
				wait(&status);
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		else if (!strcmp(ac[i], "|"))
		{
//			printf("es pipe %i %s \n", i, ac[0]);
			pipe(fd);
			if(fork() == 0 )
			{
				dup2(fd[1],STDOUT_FILENO);
				close(fd[0]);
				close(fd[1]);
				if(exec_cmd(ac,i,tmp_fd, env))
					return (1);
			}
			else
			{
				close(fd[1]);
				close(tmp_fd);
				tmp_fd = fd[0];
			}
		}
//		printf("sigo en bucle %i del todo %s \n", i, ac[i]);
		if(ac[i])
			ac = &ac[i+1];
		else
			ac = &ac[i];
//		printf("sigo en bucle %i del todo %s \n", i, ac[0]);
		i = 0;
	}
//	printf("salgo %i del todo %s \n", i, ac[i]);
	return (0);
}


