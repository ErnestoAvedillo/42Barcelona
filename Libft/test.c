#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include "./Libft/libft.h"

//int main (int av, char **ac)
int main ()
{
	/* ft_isalpha
	*/
	int var1 = 'r';
	int var2 = '2';
	if (ft_isalpha(var1))
		printf("la variable %c es alfabetica", var1);
	else
		printf("la variable %c no es alfabetica", var1);

	if (ft_isalpha(var2))
		printf("la variable %c es alfabetica", var2);
	else
		printf("la variable %c no es alfabetica", var2);
	/* ft_isalpha
	*/
	int var1 = 'r';
	int var2 = '2';
	if (ft_isalpha(var1))
		printf("la variable 1 es alfabetica");
	else
		printf("la variable 1 no es alfabetica");

	if (ft_isalpha(var2))
		printf("la variable 2 es alfabetica");
	else
		printf("la variable 2 no es alfabetica");

}