/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:13:05 by eavedill          #+#    #+#             */
/*   Updated: 2022/10/17 06:14:22 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<test.h>

int is_func(char **ac, char *str)
{
	int i = 0;

	while (ac[i])
	{
		if (ft_strncmp(ac[i], str, ft_strlen(str)) == 0)
			return (1);
		i++;
	}
	return (0);
}

int main(int av, char **ac)
{
	printf("BUFFER SIZE = %d\n",BUFFER_SIZE );
	if (av == 1 || is_func(ac, "standard"))
	{
		printf("%sTest standard%s\n",KCYN,KNRM );
		standardread("./textfiles/Time Machine, The.txt", 20);
	}
	if (av == 1 || is_func(ac, "empty"))
	{
		printf("%sTest empty%s\n",KCYN,KNRM );
		standardread("./textfiles/empty.txt", 20);
	}
	if (av == 1 || is_func(ac, "nl"))
	{
		printf("%sTest new line%s\n",KCYN,KNRM );
		standardread("./textfiles/newline.txt", 20);
	}
	if (av == 1 || is_func(ac, "short"))
	{
		printf("%sTest short file%s\n",KCYN,KNRM );
		standardread("./textfiles/Short file.txt", 20);
	}
	if (av == 1 || is_func(ac, "special"))
	{
		printf("%sTest special file%s\n",KCYN,KNRM );
		standardread("./textfiles/open_close_open.txt", 20);
	}
	if (av == 1 || is_func(ac, "1char"))
	{
		printf("%sTest only 1char file%s\n",KCYN,KNRM );
		standardread("./textfiles/1char.txt", 20);
	}
	if (av == 1 || is_func(ac, "only_nl"))
	{
		printf("%sTest only_nl file%s\n",KCYN,KNRM );
		standardread("./textfiles/only_nl.txt", 20);
	}
	if (av == 1 || is_func(ac, "giant_nl"))
	{
		printf("%sTest only_nl file%s\n",KCYN,KNRM );
		standardread("./textfiles/giant_line.txt", 20);
	}
	if (av == 1 || is_func(ac, "giant"))
	{
		printf("%sTest only_nl file%s\n",KCYN,KNRM );
		standardread("./textfiles/giant_line_nl.txt", 20);
	}

	return(0);
}
