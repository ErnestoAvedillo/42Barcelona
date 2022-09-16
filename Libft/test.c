#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "libft.h"

int main (int av, char **ac)
{
	/* ft_isalpha
	*/
	int var1 = 'r'
	int var2 = '2'
	if (ft_isalpha(var1))
		printf("la variable 1 es alfabetica");
	else
		printf("la variable 1 no es alfabetica");

	if (ft_isalpha(var2))
		printf("la variable 2 es alfabetica");
	else
		printf("la variable 2 no es alfabetica");

}