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
#include"testlib.h"

//int main(int av, char **ac)
int standardread(char *filename, int nrlines)
{
	int		i;
	int		fd1;
	char	*leter;

	fd1 = open(filename, O_RDONLY);
/*	if (fd1 == -1)
	{
		printf("Error en la apertura del fichero <%s>\n", filename);
		return(0);
	}
	else
		printf("Fichero abierto con fd = %d\n", fd1);
*/	i = 0;
	while (i < nrlines)
	{
		leter = get_next_line(fd1);
		if (leter == NULL)
		{
			printf("Leter es null\n");
			//free(leter);
			break;		
		}
		printf("%slinea nº %d %s ",KGRN ,i+1, KNRM );
		printf("<%s> %p\n",leter, leter );
		//free (leter);
		i++;
	}
	close(fd1);
	return(0);
}
