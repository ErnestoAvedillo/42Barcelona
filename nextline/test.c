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

//int main(int av, char **ac)
int main()
{
	int		i;
	int		fd1;
	char	*leter;

	fd1 = open("./textfiles/Invisible Man, The.txt", O_RDONLY);
	i = 0;
	while (i < 10)
	{
		leter = get_next_line(fd1);
		if (leter == NULL)
		{
			free(leter);
			break;		
		}
		printf("%slinea nº %d %s ",KGRN ,i+1, KNRM );
		printf("%s",leter );
		free (leter);
		i++;
	}
	close(fd1);
	return(0);
}
