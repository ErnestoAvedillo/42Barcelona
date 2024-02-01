#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
//#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>

int prt_err(char *ac1, char *ac2)
{
    while (*ac1)
        write(2, ac1++, 1);
    if (ac2)
        while (*ac2)
            write(2, ac2++, 1);
    write(2, "\n", 1);
    return 1;
}

int exec_cmd(char **ac, char **env, int tmp_fd, int i)
{
    ac[i] = NULL;
    dup2(tmp_fd, STDIN_FILENO);
    close(tmp_fd);
    execve(ac[0], ac, env);
    return (prt_err("error: Command no ejecutable", ac[0]));
}

int main (int av, char **ac, char **env)
{
    int i = 0;
    int tmp_fd, fd[2];

    if (av < 2)
        return 0;
    ac = &ac[1];
    tmp_fd = dup(STDIN_FILENO);
    while (ac[i])
    {
        while(ac[i]  && strcmp(ac[i], ";") && strcmp(ac[i], "|"))
            i++;
        if (!strcmp(ac[0], "cd") || !strcmp(ac[i], ";"))
        {
            if (i != 2)
                prt_err("error: cd: bad arguments", NULL);
            else if (chdir(ac[1]))
                prt_err("error: cd: Could not change to dir ", ac[1]);
        }
        else if ( i != 0 && (!ac[i] || !strcmp(ac[i], ";")) )
        {
            if(fork() == 0)
            {
                if(exec_cmd(ac, env, tmp_fd, i))
                    return 1;
            }
            else
            {
                close(tmp_fd);
                while(waitpid(-1, NULL, WUNTRACED) != -1);
                tmp_fd = dup(STDIN_FILENO);
            }
        }
        else if (i !=0 && strcmp(ac[i], "|"))
        {
            pipe(fd);
            if (fork() == 0)
            {
                dup2(fd[1], STDOUT_FILENO);
                close(fd[0]);
                close(fd[1]); 
                if(exec_cmd(ac, env, tmp_fd, i))
                    return 1;
            }
            else
            {
                close (fd[1]);
                close(tmp_fd);
                tmp_fd = fd[0];
            }
        }
        if (!ac[i])
            ac = &ac[i];
        else
            ac = &ac[i + 1];
        i = 0; 
    }
}