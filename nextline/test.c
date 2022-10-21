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
#include"test.h"

//int main(int av, char **ac)
int main()
{
	int		fd1;
	char	*leter;

	fd1 = open("./textfiles/Dr Moreau.txt", O_RDONLY);
	leter = get_next_line(fd1);
	free (leter);
	printf("%s",leter );
	leter = get_next_line(fd1);
	free (leter);
	printf("%s",leter );
	close(fd1);
	return(0);
}
