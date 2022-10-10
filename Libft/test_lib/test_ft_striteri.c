#include "../entrega/libft.h"
#include "test_lib.h"

void	ft_test_iteri(unsigned int i, char *c)
{
	i = 32;
	*c += i;
	return;
}

void test_ft_striteri ()
{
	char str[50];
	/*ft_striteri
	 */

	printf("%sTest de ft_strmapi%s\n",KGRN, KNRM);
	printf("%sTest1%s\n",KYEL, KNRM);
	ft_strlcpy(str, "ABC",4);
	printf("La funcion ft_striteri modifica cada caracter del str: %s \n",str );
	ft_striteri(str,ft_test_iteri);
	printf("quedando: %s \n",str );
	printf("\n");
}