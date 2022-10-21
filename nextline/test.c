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
	FILE	*fd1;
	char leter;

	fd1 = fopen("./textfiles/Dr Moreau.txt", "r");
	while (1)
	{
		leter = fgetc(fd1);
		if (feof(fd1))
			break;
		printf("%c",leter );
	}	
	fclose(fd1);
	return(0);
}
